
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusion

// input:  EFL_EINA_BOOST_FT_syntax     type macro to use
// input:  EFL_EINA_BOOST_FT_cc         empty or cc specifier 
// input:  EFL_EINA_BOOST_FT_ell        empty or "..."
// input:  EFL_EINA_BOOST_FT_cv         empty or cv qualifiers
// input:  EFL_EINA_BOOST_FT_flags      single decimal integer encoding the flags
// output: EFL_EINA_BOOST_FT_n          number of component types (arity+1)
// output: EFL_EINA_BOOST_FT_arity      current arity
// output: EFL_EINA_BOOST_FT_type       macro that expands to the type
// output: EFL_EINA_BOOST_FT_tplargs(p) template arguments with given prefix
// output: EFL_EINA_BOOST_FT_params(p)  parameters with given prefix

# include <eina_boost/function_types/detail/components_impl/arity10_1.hpp>
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10, typename L>
struct components_impl<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L>
{
typedef encode_bits<EFL_EINA_BOOST_FT_flags,EFL_EINA_BOOST_FT_cc_id> bits;
typedef constant<EFL_EINA_BOOST_FT_full_mask> mask;
typedef function_types::components<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L> type;
typedef components_mpl_sequence_tag tag;
typedef mpl::integral_c<std::size_t,11> function_arity;
typedef mpl::vector12< R, typename class_transform<T0 EFL_EINA_BOOST_FT_cv, L> ::type , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 > types;
};
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11, typename L>
struct components_impl<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L>
{
typedef encode_bits<EFL_EINA_BOOST_FT_flags,EFL_EINA_BOOST_FT_cc_id> bits;
typedef constant<EFL_EINA_BOOST_FT_full_mask> mask;
typedef function_types::components<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L> type;
typedef components_mpl_sequence_tag tag;
typedef mpl::integral_c<std::size_t,12> function_arity;
typedef mpl::vector13< R, typename class_transform<T0 EFL_EINA_BOOST_FT_cv, L> ::type , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 > types;
};
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12, typename L>
struct components_impl<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L>
{
typedef encode_bits<EFL_EINA_BOOST_FT_flags,EFL_EINA_BOOST_FT_cc_id> bits;
typedef constant<EFL_EINA_BOOST_FT_full_mask> mask;
typedef function_types::components<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L> type;
typedef components_mpl_sequence_tag tag;
typedef mpl::integral_c<std::size_t,13> function_arity;
typedef mpl::vector14< R, typename class_transform<T0 EFL_EINA_BOOST_FT_cv, L> ::type , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 > types;
};
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13, typename L>
struct components_impl<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L>
{
typedef encode_bits<EFL_EINA_BOOST_FT_flags,EFL_EINA_BOOST_FT_cc_id> bits;
typedef constant<EFL_EINA_BOOST_FT_full_mask> mask;
typedef function_types::components<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L> type;
typedef components_mpl_sequence_tag tag;
typedef mpl::integral_c<std::size_t,14> function_arity;
typedef mpl::vector15< R, typename class_transform<T0 EFL_EINA_BOOST_FT_cv, L> ::type , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 > types;
};
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14, typename L>
struct components_impl<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L>
{
typedef encode_bits<EFL_EINA_BOOST_FT_flags,EFL_EINA_BOOST_FT_cc_id> bits;
typedef constant<EFL_EINA_BOOST_FT_full_mask> mask;
typedef function_types::components<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L> type;
typedef components_mpl_sequence_tag tag;
typedef mpl::integral_c<std::size_t,15> function_arity;
typedef mpl::vector16< R, typename class_transform<T0 EFL_EINA_BOOST_FT_cv, L> ::type , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 > types;
};
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15, typename L>
struct components_impl<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L>
{
typedef encode_bits<EFL_EINA_BOOST_FT_flags,EFL_EINA_BOOST_FT_cc_id> bits;
typedef constant<EFL_EINA_BOOST_FT_full_mask> mask;
typedef function_types::components<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L> type;
typedef components_mpl_sequence_tag tag;
typedef mpl::integral_c<std::size_t,16> function_arity;
typedef mpl::vector17< R, typename class_transform<T0 EFL_EINA_BOOST_FT_cv, L> ::type , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 > types;
};
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16, typename L>
struct components_impl<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L>
{
typedef encode_bits<EFL_EINA_BOOST_FT_flags,EFL_EINA_BOOST_FT_cc_id> bits;
typedef constant<EFL_EINA_BOOST_FT_full_mask> mask;
typedef function_types::components<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L> type;
typedef components_mpl_sequence_tag tag;
typedef mpl::integral_c<std::size_t,17> function_arity;
typedef mpl::vector18< R, typename class_transform<T0 EFL_EINA_BOOST_FT_cv, L> ::type , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 > types;
};
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17, typename L>
struct components_impl<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L>
{
typedef encode_bits<EFL_EINA_BOOST_FT_flags,EFL_EINA_BOOST_FT_cc_id> bits;
typedef constant<EFL_EINA_BOOST_FT_full_mask> mask;
typedef function_types::components<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L> type;
typedef components_mpl_sequence_tag tag;
typedef mpl::integral_c<std::size_t,18> function_arity;
typedef mpl::vector19< R, typename class_transform<T0 EFL_EINA_BOOST_FT_cv, L> ::type , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 > types;
};
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18, typename L>
struct components_impl<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L>
{
typedef encode_bits<EFL_EINA_BOOST_FT_flags,EFL_EINA_BOOST_FT_cc_id> bits;
typedef constant<EFL_EINA_BOOST_FT_full_mask> mask;
typedef function_types::components<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L> type;
typedef components_mpl_sequence_tag tag;
typedef mpl::integral_c<std::size_t,19> function_arity;
typedef mpl::vector20< R, typename class_transform<T0 EFL_EINA_BOOST_FT_cv, L> ::type , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 > types;
};
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 , typename T10 , typename T11 , typename T12 , typename T13 , typename T14 , typename T15 , typename T16 , typename T17 , typename T18 , typename T19, typename L>
struct components_impl<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L>
{
typedef encode_bits<EFL_EINA_BOOST_FT_flags,EFL_EINA_BOOST_FT_cc_id> bits;
typedef constant<EFL_EINA_BOOST_FT_full_mask> mask;
typedef function_types::components<EFL_EINA_BOOST_FT_syntax(EFL_EINA_BOOST_FT_cc, EFL_EINA_BOOST_PP_EMPTY) (T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 EFL_EINA_BOOST_FT_ell) EFL_EINA_BOOST_FT_cv, L> type;
typedef components_mpl_sequence_tag tag;
typedef mpl::integral_c<std::size_t,20> function_arity;
typedef mpl::vector21< R, typename class_transform<T0 EFL_EINA_BOOST_FT_cv, L> ::type , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 > types;
};

