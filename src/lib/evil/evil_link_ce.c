#ifdef HAVE_CONFIG_H
# include "config.h"
#endif /* HAVE_CONFIG_H */

#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN

#include <shellapi.h>

#include "Evil.h"
#include "evil_private.h"


/*
 * Symbolic links and directory related functions
 *
 */


/* REMARK: Windows has no symbolic link. */
/*         Nevertheless, it can create and read .lnk files */

int
symlink(const char *oldpath, const char *newpath)
{
   wchar_t *w_oldpath;
   wchar_t *w_newpath;
   BOOL     res;

   w_oldpath = evil_char_to_wchar(oldpath);
   if (!w_oldpath)
     return -1;

   w_newpath = evil_char_to_wchar(newpath);
   if (!w_newpath)
     {
        free(w_oldpath);
        return -1;
     }

   res = SHCreateShortcut(w_newpath, w_oldpath);
   if (!res)
     _evil_last_error_display(__FUNCTION__);

   free(w_oldpath);
   free(w_newpath);

   return res ? 0 : -1;
}

ssize_t
readlink(const char *path, char *buf, size_t bufsiz)
{
   wchar_t *w_path;
   wchar_t  w_newpath[1024];
   char    *newpath;
   size_t   length;
   BOOL     res;

   w_path = evil_char_to_wchar(path);
   if (!w_path)
     return -1;

   res = SHGetShortcutTarget(w_path, w_newpath, 1024);
   if (!res)
     _evil_last_error_display(__FUNCTION__);

   free(w_path);

   if (!res)
     return -1;

   newpath = evil_wchar_to_char(w_newpath);
   if (!newpath)
     return -1;

   /* That stupid SHGetShortcutTarget add " around the file name... */
   length = strlen(newpath) - 2;
   if (length > bufsiz)
     length = bufsiz;

   memcpy(buf, newpath + 1, length);

   free(newpath);

   return length;
}
