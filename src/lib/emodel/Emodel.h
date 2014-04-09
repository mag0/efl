/**
   @brief Emodel Library Public API Calls

   These routines are used for Emodel Library interaction
 */

/**

   @page emodel_main Emodel

   @date 2014 (created)

   @section toc Table of Contents

 */

#ifndef _EMODEL_H
#define _EMODEL_H

#include <Eo.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup Emode
 *
 * @{
 */
#define EMODEL_CLASS emodel_class_get()
const Eo_Class *emodel_class_get(void) EINA_CONST;
extern EAPI Eo_Op EMODEL_BASE_ID;

enum
{
   EMODEL_SUB_ID_PROPERTIES_GET,
   EMODEL_SUB_ID_PROPERTY_GET,
   EMODEL_SUB_ID_PROPERTY_SET,
   EMODEL_SUB_ID_LOAD,
   EMODEL_SUB_ID_UNLOAD,
   EMODEL_SUB_ID_CHILD_ADD,
   EMODEL_SUB_ID_CHILD_DEL,
   EMODEL_SUB_ID_CHILDREN_GET,
   EMODEL_SUB_ID_CHILDREN_SLICE_GET,
   EMODEL_SUB_ID_CHILDREN_COUNT_GET,
   EMODEL_SUB_ID_LAST,
};

typedef void (*Emodel_Cb)(void *data, Eo *child, void *event_info);

struct _Emodel_Property_EVT
{
   Eina_Value *value;
   const char *prop; 
};

typedef struct _Emodel_Property_EVT Emodel_Property_EVT;

struct _Emodel_Children_EVT
{
   Eo *child;
   void *data;
   int idx;
};

typedef struct _Emodel_Children_EVT Emodel_Children_EVT;

#define EMODEL_ID(sub_id) (EMODEL_BASE_ID + sub_id)

/**
 * @def emodel_properties_get
 * @since 1.9
 *
 */
#define emodel_properties_get() EMODEL_ID(EMODEL_SUB_ID_PROPERTIES_GET)

/**
 * @def emodel_property_get
 * @since 1.9
 *
 */
#define emodel_property_get(property) EMODEL_ID(EMODEL_SUB_ID_PROPERTY_GET), EO_TYPECHECK(const char *, property)

/**
 * @def emodel_property_set
 * @since 1.9
 *
 */
#define emodel_property_set(property, value) EMODEL_ID(EMODEL_SUB_ID_PROPERTY_SET), EO_TYPECHECK(const char *, property), EO_TYPECHECK(Eina_Value *, value)

/**E
 * @def emodel_load
 * @since 1.9
 *
 */
#define emodel_load() EMODEL_ID(EMODEL_SUB_ID_LOAD)

/**
 * @def emodel_unload
 * @since 1.9
 *
 */
#define emodel_unload() EMODEL_ID(EMODEL_SUB_ID_UNLOAD)

/**
 * @def emodel_child_add
 * @since 1.9
 *
 */
#define emodel_child_add(child_add_cb, data) EMODEL_ID(EMODEL_SUB_ID_CHILD_ADD), EO_TYPECHECK(Emodel_Cb , child_add_cb), EO_TYPECHECK(void *, data)


/**
 * @def emodel_child_del
 * @since 1.9
 *
 */
#define emodel_child_del() EMODEL_ID(EMODEL_SUB_ID_CHILD_DEL)

/**
 * @def emodel_children_get
 * @since 1.9
 *
 */
#define emodel_children_get(children_get_cb, data) EMODEL_ID(EMODEL_SUB_ID_CHILDREN_GET), EO_TYPECHECK(Emodel_Cb, children_get_cb), EO_TYPECHECK(void *, data)

/**
 * @def emodel_children_slice_get
 * @since 1.9
 *
 */
#define emodel_children_slice_get(children_slice_get_cb, start, count, data) EMODEL_ID(EMODEL_SUB_ID_CHILDREN_SLICE_GET), EO_TYPECHECK(Emodel_Cb, children_slice_get_cb), EO_TYPECHECK(int, start), EO_TYPECHECK(int, count), EO_TYPECHECK(void *, data)

/**
 * @def emodel_children_count_get
 * @since 1.9
 *
 */
#define emodel_children_count_get() EMODEL_ID(EMODEL_SUB_ID_CHILDREN_COUNT_GET)

extern const Eo_Event_Description _EMODEL_PROPERTIES_CHANGE_EVT;
#define EMODEL_PROPERTIES_CHANGE_EVT (&(_EMODEL_PROPERTIES_CHANGE_EVT))

extern const Eo_Event_Description _EMODEL_PROPERTY_CHANGE_EVT;
#define EMODEL_PROPERTY_CHANGE_EVT (&(_EMODEL_PROPERTY_CHANGE_EVT))

extern const Eo_Event_Description _EMODEL_CHILD_ADD_EVT;
#define EMODEL_CHILD_ADD_EVT (&(_EMODEL_CHILD_ADD_EVT))

//TODO: implement
extern const Eo_Event_Description _EMODEL_CHILD_DEL_EVT;
#define EMODEL_CHILD_DEL_EVT (&(_EMODEL_CHILD_DEL_EVT))

//TODO: remove this event ?
extern const Eo_Event_Description _EMODEL_CHILDREN_GET_EVT;
#define EMODEL_CHILDREN_GET_EVT (&(_EMODEL_CHILDREN_GET_EVT))

extern const Eo_Event_Description _EMODEL_CHILDREN_COUNT_GET_EVT;
#define EMODEL_CHILDREN_COUNT_GET_EVT (&(_EMODEL_CHILDREN_COUNT_GET_EVT))

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif //_EMODEL_H
