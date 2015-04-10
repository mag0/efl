#include "Elua.h"
#include "elua_private.h"

static Eina_Prefix *_elua_pfx = NULL;

static int _elua_init_counter = 0;
int _elua_log_dom = -1;

EAPI int
elua_init(void)
{
   const char *dom = "elua";
   if (_elua_init_counter > 0) return ++_elua_init_counter;

   eina_init();
   _elua_log_dom = eina_log_domain_register(dom, EINA_COLOR_LIGHTBLUE);
   if (_elua_log_dom < 0)
     {
        EINA_LOG_ERR("Could not register log domain: %s", dom);
        return EINA_FALSE;
     }

   eina_log_timing(_elua_log_dom, EINA_LOG_STATE_STOP, EINA_LOG_STATE_INIT);
   INF("elua init");

   _elua_pfx = eina_prefix_new(NULL, elua_init, "ELUA", "elua", "checkme",
                               PACKAGE_BIN_DIR, "", PACKAGE_DATA_DIR,
                               LOCALE_DIR);

   if (!_elua_pfx)
     {
        ERR("coul not find elua prefix");
        return EINA_FALSE;
     }

   return ++_elua_init_counter;
}

EAPI int
elua_shutdown(void)
{
   if (_elua_init_counter <= 0)
     {
        EINA_LOG_ERR("Init count not greater than 0 in shutdown.");
        return EINA_FALSE;
     }
   --_elua_init_counter;

   if (_elua_init_counter > 0)
     return _elua_init_counter;

   INF("shutdown");
   eina_log_timing(_elua_log_dom, EINA_LOG_STATE_START, EINA_LOG_STATE_SHUTDOWN);

   eina_prefix_free(_elua_pfx);
   _elua_pfx = NULL;

   eina_log_domain_unregister(_elua_log_dom);
   _elua_log_dom = -1;

   eina_shutdown();
   return _elua_init_counter;
}

EAPI Elua_State *
elua_state_new(const char *progname)
{
   Elua_State *ret = NULL;
   lua_State *L = luaL_newstate();
   if (!L)
     return NULL;
   ret = calloc(1, sizeof(Elua_State));
   ret->luastate = L;
   if (progname) ret->progname = eina_stringshare_add(progname);
   luaL_openlibs(L);
   lua_pushlightuserdata(L, ret);
   lua_setfield(L, LUA_REGISTRYINDEX, "elua_ptr");
   return ret;
}

EAPI void
elua_state_free(Elua_State *es)
{
   void *data;
   if (!es) return;
   if (es->luastate)
     {
        EINA_LIST_FREE(es->cmods, data)
          {
             lua_rawgeti(es->luastate, LUA_REGISTRYINDEX, (size_t)data);
             lua_call(es->luastate, 0, 0);
          }
        lua_close(es->luastate);
     }
   else if (es->cmods)
     eina_list_free(es->cmods);
   EINA_LIST_FREE(es->lincs, data)
     eina_stringshare_del(data);
   eina_stringshare_del(es->progname);
   eina_stringshare_del(es->coredir);
   eina_stringshare_del(es->moddir);
   eina_stringshare_del(es->appsdir);
   free(es);
}

EAPI void
elua_state_dirs_set(Elua_State *es, const char *core, const char *mods,
                    const char *apps)
{
   EINA_SAFETY_ON_NULL_RETURN(es);
   if (core) es->coredir = eina_stringshare_add(core);
   if (mods) es->moddir  = eina_stringshare_add(mods);
   if (apps) es->appsdir = eina_stringshare_add(apps);
}

EAPI void
elua_state_dirs_fill(Elua_State *es, Eina_Bool ignore_env)
{
   const char *coredir = NULL, *moddir = NULL, *appsdir = NULL;
   char coredirbuf[PATH_MAX], moddirbuf[PATH_MAX], appsdirbuf[PATH_MAX];
   EINA_SAFETY_ON_NULL_RETURN(es);
   if (!(coredir = es->coredir))
     {
        if (ignore_env || !(coredir = getenv("ELUA_CORE_DIR")) || !coredir[0])
          {
             coredir = coredirbuf;
             snprintf(coredirbuf, sizeof(coredirbuf), "%s/core",
                      eina_prefix_data_get(_elua_pfx));
          }
        if (coredir) es->coredir = eina_stringshare_add(coredir);
     }
   if (!(moddir = es->moddir))
     {
        if (ignore_env || !(moddir = getenv("ELUA_MODULES_DIR")) || !moddir[0])
          {
             moddir = moddirbuf;
             snprintf(moddirbuf, sizeof(moddirbuf), "%s/modules",
                      eina_prefix_data_get(_elua_pfx));
          }
        if (moddir) es->moddir = eina_stringshare_add(moddir);
     }
   if (!(appsdir = es->appsdir))
     {
        if (ignore_env || !(appsdir = getenv("ELUA_APPS_DIR")) || !appsdir[0])
          {
             appsdir = appsdirbuf;
             snprintf(appsdirbuf, sizeof(appsdirbuf), "%s/apps",
                      eina_prefix_data_get(_elua_pfx));
          }
        if (appsdir) es->appsdir = eina_stringshare_add(appsdir);
     }
}

EAPI Eina_Stringshare *
elua_state_core_dir_get(const Elua_State *es)
{
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, NULL);
   return es->coredir;
}

EAPI Eina_Stringshare *
elua_state_mod_dir_get(const Elua_State *es)
{
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, NULL);
   return es->moddir;
}

EAPI Eina_Stringshare *
elua_state_apps_dir_get(const Elua_State *es)
{
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, NULL);
   return es->moddir;
}

EAPI Eina_Stringshare *
elua_state_prog_name_get(const Elua_State *es)
{
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, NULL);
   return es->progname;
}

EAPI void
elua_state_include_path_add(Elua_State *es, const char *path)
{
   EINA_SAFETY_ON_NULL_RETURN(es);
   EINA_SAFETY_ON_NULL_RETURN(path);
   EINA_SAFETY_ON_FALSE_RETURN(path[0]);
   es->lincs = eina_list_append(es->lincs, eina_stringshare_add(path));
}

EAPI Eina_Bool
elua_state_require_ref_push(Elua_State *es)
{
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, EINA_FALSE);
   EINA_SAFETY_ON_NULL_RETURN_VAL(es->luastate, EINA_FALSE);
   EINA_SAFETY_ON_FALSE_RETURN_VAL(es->requireref != LUA_REFNIL, EINA_FALSE);
   lua_rawgeti(es->luastate, LUA_REGISTRYINDEX, es->requireref);
   return EINA_TRUE;
}

EAPI Eina_Bool
elua_state_appload_ref_push(Elua_State *es)
{
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, EINA_FALSE);
   EINA_SAFETY_ON_NULL_RETURN_VAL(es->luastate, EINA_FALSE);
   EINA_SAFETY_ON_FALSE_RETURN_VAL(es->apploadref != LUA_REFNIL, EINA_FALSE);
   lua_rawgeti(es->luastate, LUA_REGISTRYINDEX, es->apploadref);
   return EINA_TRUE;
}

EAPI lua_State *
elua_state_lua_state_get(const Elua_State *es)
{
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, NULL);
   return es->luastate;
}

EAPI Elua_State *
elua_state_from_lua_get(lua_State *L)
{
   EINA_SAFETY_ON_NULL_RETURN_VAL(L, NULL);
   lua_getfield(L, LUA_REGISTRYINDEX, "elua_ptr");
   if (!lua_isnil(L, -1))
     {
        void *st = lua_touserdata(L, -1);
        lua_pop(L, 1);
        return (Elua_State *)st;
     }
   lua_pop(L, 1);
   return NULL;
}

static void
_elua_errmsg(const char *pname, const char *msg)
{
   ERR("%s%s%s", pname ? pname : "", pname ? ": " : "", msg);
}

EAPI int
elua_report_error(const Elua_State *es, const char *pname, int status)
{
   EINA_SAFETY_ON_FALSE_RETURN_VAL(es && es->luastate, status);
   if (status && !lua_isnil(es->luastate, -1))
     {
        const char *msg = lua_tostring(es->luastate, -1);
        _elua_errmsg(pname, msg ? msg : "(non-string error)");
        lua_pop(es->luastate, 1);
     }
   return status;
}

static int
_elua_gettext_bind_textdomain(lua_State *L)
{
#ifdef ENABLE_NLS
   const char *textdomain = luaL_checkstring(L, 1);
   const char *dirname    = luaL_checkstring(L, 2);
   const char *ret;
   if (!textdomain[0] || !strcmp(textdomain, PACKAGE))
     {
        lua_pushnil(L);
        lua_pushliteral(L, "invalid textdomain");
        return 2;
     }
   if (!(ret = bindtextdomain(textdomain, dirname)))
     {
        lua_pushnil(L);
        lua_pushstring(L, strerror(errno));
        return 2;
     }
   bind_textdomain_codeset(textdomain, "UTF-8");
   lua_pushstring(L, ret);
   return 1;
#else
   lua_pushliteral(L, "");
   return 1;
#endif
}

const luaL_reg gettextlib[] =
{
   { "bind_textdomain", _elua_gettext_bind_textdomain },
   { NULL, NULL }
};

EAPI Eina_Bool
elua_state_setup_i18n(const Elua_State *es)
{
#ifdef ENABLE_NLS
   char *(*dgettextp)(const char*, const char*) = dgettext;
   char *(*dngettextp)(const char*, const char*, const char*, unsigned long)
      = dngettext;
#endif
   char buf[PATH_MAX];
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, EINA_FALSE);
   EINA_SAFETY_ON_NULL_RETURN_VAL(es->luastate, EINA_FALSE);
   EINA_SAFETY_ON_NULL_RETURN_VAL(es->coredir, EINA_FALSE);
   snprintf(buf, sizeof(buf), "%s/gettext.lua", es->coredir);
   if (elua_report_error(es, elua_state_prog_name_get(es),
       elua_io_loadfile(es, buf)))
     return EINA_FALSE;
   lua_createtable(es->luastate, 0, 0);
   luaL_register(es->luastate, NULL, gettextlib);
#ifdef ENABLE_NLS
   lua_pushlightuserdata(es->luastate, *((void**)&dgettextp));
   lua_setfield(es->luastate, -2, "dgettext");
   lua_pushlightuserdata(es->luastate, *((void**)&dngettextp));
   lua_setfield(es->luastate, -2, "dngettext");
#endif
   lua_call(es->luastate, 1, 0);
   return EINA_TRUE;
}

EAPI int
elua_module_init(lua_State *L)
{
   Elua_State *es = elua_state_from_lua_get(L);
   if (!lua_isnoneornil(L, 1))
     {
        lua_pushvalue(L, 1);
        lua_call(L, 0, 0);
     }
   if (!lua_isnoneornil(L, 2))
     {
        lua_pushvalue(L, 2);
        es->cmods = eina_list_append(es->cmods,
           (void*)(size_t)luaL_ref(L, LUA_REGISTRYINDEX));
     }
   return 0;
}

EAPI int
elua_module_system_init(lua_State *L)
{
   Elua_State       *es       = elua_state_from_lua_get(L);
   const char       *corepath = es->coredir;
   const char       *modpath  = es->moddir;
   const char       *appspath = es->appsdir;
   Eina_Stringshare *data     = NULL;
   int n = 3;
   if (!corepath || !modpath || !appspath)
     return 0;
   lua_pushvalue(L, 1);
   es->requireref = luaL_ref(L, LUA_REGISTRYINDEX);
   lua_pushvalue(L, 2);
   es->apploadref = luaL_ref(L, LUA_REGISTRYINDEX);
   lua_pushfstring(L, "%s/?.lua;", corepath);
   EINA_LIST_FREE(es->lincs, data)
     {
        lua_pushfstring(L, "%s/?.lua;", data);
        eina_stringshare_del(data);
        ++n;
     }
   lua_pushfstring(L, "%s/?.eo.lua;", modpath);
   lua_pushfstring(L, "%s/?.lua;", modpath);
   lua_pushvalue(L, 3);
   lua_concat(L, n + 1);
   lua_pushfstring(L, "%s/?.lua;", appspath);
   lua_pushvalue(L, 4);
   lua_concat(L, 2);
   return 2;
}

/* Utility functions - these could be written using the other APIs */

static int
_elua_traceback(lua_State *L)
{
   lua_getglobal(L, "debug");
   if (!lua_istable(L, -1))
     {
        lua_pop(L, 1);
        return 1;
     }
   lua_getfield(L, -1, "traceback");
   if (!lua_isfunction(L, -1))
     {
        lua_pop(L, 2);
        return 1;
     }
   lua_pushvalue(L, 1);
   lua_pushinteger(L, 2);
   lua_call(L, 2, 1);
   return 1;
}

static int
_elua_docall(Elua_State *es, int narg, int nret)
{
   int status;
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, -1);
   EINA_SAFETY_ON_NULL_RETURN_VAL(es->luastate, -1);
   int bs = lua_gettop(es->luastate) - narg;
   lua_pushcfunction(es->luastate, _elua_traceback);
   lua_insert(es->luastate, bs);
   status = lua_pcall(es->luastate, narg, nret, bs);
   lua_remove(es->luastate, bs);
   if (status)
      lua_gc(es->luastate, LUA_GCCOLLECT, 0);
   return status;
}

static int
_elua_getargs(Elua_State *es, int argc, char **argv, int n)
{
   int i;
   int narg = argc - (n + 1);
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, -1);
   EINA_SAFETY_ON_NULL_RETURN_VAL(es->luastate, -1);
   luaL_checkstack(es->luastate, narg + 3, "too many arguments to script");
   for (i = n + 1; i < argc; ++i)
     {
        lua_pushstring(es->luastate, argv[i]);
     }
   lua_createtable(es->luastate, narg, n + 1);
   for (i = 0; i < argc; ++i)
     {
        lua_pushstring(es->luastate, argv[i]);
        lua_rawseti(es->luastate, -2, i - n);
     }
   return narg;
}

EAPI int
elua_util_require(Elua_State *es, const char *libname)
{
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, -1);
   EINA_SAFETY_ON_NULL_RETURN_VAL(es->luastate, -1);
   EINA_SAFETY_ON_FALSE_RETURN_VAL(elua_state_require_ref_push(es), -1);
   lua_pushstring(es->luastate, libname);
   return elua_report_error(es, es->progname,
                            lua_pcall(es->luastate, 1, 0, 0));
}

EAPI int
elua_util_file_run(Elua_State *es, const char *fname)
{
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, -1);
   EINA_SAFETY_ON_NULL_RETURN_VAL(es->luastate, -1);
   return elua_report_error(es, es->progname,
                            elua_io_loadfile(es, fname)
                            || _elua_docall(es, 0, 1));
}

EAPI int
elua_util_string_run(Elua_State *es, const char *chunk, const char *chname)
{
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, -1);
   EINA_SAFETY_ON_NULL_RETURN_VAL(es->luastate, -1);
   return elua_report_error(es, es->progname,
                            luaL_loadbuffer(es->luastate, chunk, strlen(chunk),
                                            chname)
                            || _elua_docall(es, 0, 0));
}

EAPI Eina_Bool
elua_util_app_load(Elua_State *es, const char *appname)
{
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, EINA_FALSE);
   EINA_SAFETY_ON_NULL_RETURN_VAL(es->luastate, EINA_FALSE);
   EINA_SAFETY_ON_FALSE_RETURN_VAL(elua_state_appload_ref_push(es), EINA_FALSE);
   lua_pushstring(es->luastate, appname);
   lua_call(es->luastate, 1, 2);
   if (lua_isnil(es->luastate, -2))
     {
        lua_remove(es->luastate, -2);
        return EINA_FALSE;
     }
   lua_pop(es->luastate, 1);
   return EINA_TRUE;
}

EAPI int
elua_util_script_run(Elua_State *es, int argc, char **argv, int n, int *quit)
{
   int status, narg;
   const char *fname;
   EINA_SAFETY_ON_FALSE_RETURN_VAL(n < argc, -1);
   EINA_SAFETY_ON_NULL_RETURN_VAL(es, -1);
   EINA_SAFETY_ON_NULL_RETURN_VAL(es->luastate, -1);
   fname = argv[n];
   narg = _elua_getargs(es, argc, argv, n);
   lua_setglobal(es->luastate, "arg");
   if (fname[0] == '-' && !fname[1]) fname = NULL;
   if (fname)
     {
        /* check if there is a file of that name */
        FILE *f = fopen(fname, "r");
        if (f)
          {
             fclose(f);
             status = elua_io_loadfile(es, fname);
          }
        else
          status = !elua_util_app_load(es, fname);
     }
   else
     status = elua_io_loadfile(es, fname);
   lua_insert(es->luastate, -(narg + 1));
   if (!status)
     status = _elua_docall(es, narg, 1);
   else
     lua_pop(es->luastate, narg);
   if (!status)
     {
        *quit = lua_toboolean(es->luastate, -1);
        lua_pop(es->luastate, 1);
     }
   return elua_report_error(es, es->progname, status);
}
