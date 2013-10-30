
//! 
//! @file inherit.hpp
//!
//! @brief Implements the inheritance of EO (C++) Classes.
//!

#ifndef EO3_INHERIT_HPP
#define EO3_INHERIT_HPP

#include "eo_private.hpp"

#include <boost/mpl/bool.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/find.hpp>

#include <boost/fusion/include/make_vector.hpp>
#include <boost/fusion/include/mpl.hpp>
#include <boost/fusion/include/at.hpp>

#include <boost/preprocessor/repetition/enum_trailing_binary_params.hpp>

#include <cassert>

namespace efl { namespace eo {

//!
//! @addtogroup Efl_Cxx_API
//! @{
//!

//!
//! @struct efl::eo::inherit
//! Implements the inheritance of EO (C++) Classes.
//!
//! <h2>Concepts:</h2>
//!
//! D: The derived class. It can be any class.
//! P: The parent class. It must be a valid EO C++ Class.
//! E0..EN: The class extensions, i.e., EO Interfaces and Mixins.
//!
//! <h2>Usage:</h2>
//!
//! Let @em eo3_simple be any C++ Class that binds an EO3 Object (this
//! class could have been generated by the conversion-tool for
//! example). Suppose you want your own C++ Class to inherit from @em
//! eo3_simple, you would do as follows:
//!
//! @code
//! struct my_class
//!   : efl::eo::inherit<my_class, eo3_simple>
//! { /*...*/ }
//! @endcode
//!
//! By doing so @verbatim my_class @endverbatim inherits all EO
//! Operations and EO Events from @verbatim eo3_simple @endverbatim
//! and also gets itself to be binded as a native EO Class (as soon as
//! the first instance is constructed) -- hence the CRTP, as you can
//! notice in the first argument of @verbatim inherit @endverbatim
//! template. 
//!
//! This simple declaration makes the new C++ Class to be fully and
//! transparently integrated into EO subsystem.
//!
template <typename D, typename P
	  BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(EFL_MAX_ARGS, typename E, = detail::void_tag_) >
struct inherit;

//!
//! @} (Efl_Cxx_API)
//!

//!
//! @addtogroup Efl_Cxx_Detail
//! @{

namespace detail {

template <typename Args>
inline void call_constructor(tag<void>, Eo*, Eo_Class const*, Args) {}

template <typename P BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(EFL_MAX_ARGS, typename E, = detail::void_tag_)>
struct operation_description_size
{
#define EFL_CXX_operation_description_class_size_val(Z, N, DATA) \
  + operation_description_class_size<BOOST_PP_CAT(E, N)>::value

  static const int value = operation_description_class_size<P>::value
    BOOST_PP_REPEAT(EFL_MAX_ARGS, EFL_CXX_operation_description_class_size_val, ~);
#undef EFL_CXX_operation_description_class_size_val
};


template <typename T>
struct predicate
{
  template <typename Args>
  struct apply { typedef boost::mpl::false_ type; };
  template <typename V>
  struct apply<args_class<T, V> >
  {
    typedef boost::mpl::true_ type;
  };
};

template <typename T>
struct call_constructor_aux
{
  template <typename I, typename Args>
  static void do_aux(Args const&, Eo* eo, Eo_Class const* cls, boost::mpl::true_)
  {
    detail::call_constructor(tag<void>(), eo, cls
                             , args_class<T, boost::fusion::vector0<> >
                             (boost::fusion::vector0<>()));
  }

  template <typename I, typename Args>
  static void do_aux(Args const& args, Eo* eo, Eo_Class const* cls, boost::mpl::false_)
  {
    typedef typename
      boost::mpl::distance<typename boost::mpl::begin<Args>::type, I>::type
      index_type;
    detail::call_constructor
      (tag<T>(), eo, cls
       , boost::fusion::at<index_type>(args));
  }

  template <typename Args>
  static void do_(Args const& args, Eo* eo, Eo_Class const* cls)
  {
    typedef typename boost::mpl::find_if<Args, predicate<T> >::type
      iterator;
    do_aux<iterator>(args
                     , eo, cls
		     , typename boost::is_same
		     <
                       typename boost::mpl::end<Args>::type
		       , iterator
		     >::type());
  }
};

template <typename D, typename P
  BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, typename E)
  , typename Args>
void inherit_constructor_impl(Eo* obj, Inherit_Private_Data* self, void* this_, Args args)
{
  self->this_ = this_;
  Eo_Class const* cls
    = static_cast<inherit<D, P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>*>(this_)->_eo_cls();

  detail::call_constructor_aux<P>::do_(args, obj, cls);
#define EFL_CXX_call_constructor_aux_rep(Z, N, DATA) \
  detail::call_constructor_aux<BOOST_PP_CAT(E, N)>::do_(args, obj, cls);
  BOOST_PP_REPEAT(EFL_MAX_ARGS, EFL_CXX_call_constructor_aux_rep, ~);
#undef EFL_CXX_call_constructor_aux_rep
}


template <typename P
  BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, typename E)
  , typename Args>
EAPI void inherit_constructor(void* this_, Args args)
{
  typedef void (*func_t)(Eo *, void *, void*, Args);
  Eo2_Op_Call_Data call;
  static Eo_Op op = EO_NOOP;
  if ( op == EO_NOOP )
    op = eo2_api_op_id_get((void*)&inherit_constructor
                           <P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E), Args>
                           , EO_OP_TYPE_REGULAR);
  if (!eo2_call_resolve(op, &call)) assert(eo2_call_resolve(op, &call));
  func_t func = (func_t) call.func;
  return func(call.obj, call.data, this_, args);
}

template <typename D, typename P
  BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, typename E)
  , typename Args>
Eo_Class const* create_class(/*info*/)
{
  static const Eo_Class* my_class = NULL;
  static Eo2_Op_Description op_descs
    [ detail::operation_description_size
      <P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>::value + 2 ];

  op_descs[detail::operation_description_size
           <P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>::value].func =
    reinterpret_cast<void*>
    (
     static_cast<void(*)(Eo*, Inherit_Private_Data*, void*, Args)>
     (&detail::inherit_constructor_impl<D, P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E), Args>)
    );

  op_descs[detail::operation_description_size
           <P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>::value].api_func =
    reinterpret_cast<void*>
    (
     static_cast<void(*)(void*, Args)>
     (&detail::inherit_constructor<P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E), Args>)
    );

  op_descs[detail::operation_description_size
           <P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>::value].op = EO_NOOP;
  op_descs[detail::operation_description_size
           <P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>::value].op_type = EO_OP_TYPE_REGULAR;
  op_descs[detail::operation_description_size
           <P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>::value].doc = "";
  op_descs[detail::operation_description_size
           <P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>::value+1].func = 0;
  op_descs[detail::operation_description_size
           <P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>::value+1].api_func = 0;
  op_descs[detail::operation_description_size
           <P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>::value+1].op = 0;
  op_descs[detail::operation_description_size
           <P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>::value+1].op_type = EO_OP_TYPE_INVALID;
  op_descs[detail::operation_description_size
           <P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>::value+1].doc = 0;

  detail::initialize_operation_description
    <inherit<D, P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)> >
    (detail::tag<P>(), op_descs);

#define BOOST_PP_ITERATION_PARAMS_1 (3, (0, BOOST_PP_DEC(EFL_MAX_ARGS), "inherit_pp_operation_description.hpp"))
#include BOOST_PP_ITERATE()

  //locks
  if(!my_class)
  {
    static Eo_Class_Description class_desc = {
      EO2_VERSION,
      "C++ Inherited class",
      EO_CLASS_TYPE_REGULAR,
      EO2_CLASS_DESCRIPTION_OPS(op_descs),
      NULL,
      sizeof(detail::Inherit_Private_Data),
      NULL,
      NULL
    };
    my_class = detail::do_eo_class_new<P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>::do_(class_desc);
  }
  return my_class;
}

} // namespace detail
//! @} Efl_Cxx_Detail

#define EFL_CXX_inherit_operations_rep(Z, N, DATA) \
  , detail::operations<BOOST_PP_CAT(E, N)>::template type<inherit<D, P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)> >

#define EFL_CXX_inherit_conversion_operator_rep(Z, N, DATA) \
, detail::conversion_operator<inherit<D, P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>, BOOST_PP_CAT(E, N)>


template <typename D, typename P
    BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, typename E)>
struct inherit
    : detail::operations<P>::template type<inherit<D, P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)> >
    BOOST_PP_REPEAT(EFL_MAX_ARGS, EFL_CXX_inherit_operations_rep, ~)
    , detail::conversion_operator<inherit<D, P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)>, P>
    BOOST_PP_REPEAT(EFL_MAX_ARGS, EFL_CXX_inherit_conversion_operator_rep, ~)
{
  //! @typedef inherit_base
  //! 
  typedef inherit<D, P BOOST_PP_ENUM_TRAILING_PARAMS(EFL_MAX_ARGS, E)> inherit_base;

#define BOOST_PP_ITERATION_PARAMS_1 (3, (0, EFL_MAX_ARGS, "inherit_pp_constructor.hpp"))
#include BOOST_PP_ITERATE()

  ~inherit()
  {
    eo_unref(_eo_raw);
  }

  Eo* _eo_ptr() const { return _eo_raw; }
  Eo_Class const* _eo_cls() const { return _eo_class; }

protected:
  inherit(inherit const& other)
    : _eo_class(other._eo_class)
    , _eo_raw(other._eo_raw)
  { eo_ref(_eo_raw); }

  inherit& operator=(inherit const& other)
  { 
    _eo_class = other._eo_class;
    _eo_raw = other._eo_raw;
    eo_ref(_eo_raw);
    return *this;
  }

private:
  Eo_Class const* _eo_class;
  Eo* _eo_raw;
};

#undef EFL_CXX_inherit_operations_rep
#undef EFL_CXX_inherit_conversion_operator_rep

} }

#endif // EO3_INHERIT_HPP
