#ifndef EFL_EINA_BOOST_PP_IS_ITERATING
/*=============================================================================
    Copyright (c) 2011 Eric Niebler
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(EFL_EINA_BOOST_FUSION_VECTOR30_FWD_HPP_INCLUDED)
#define EFL_EINA_BOOST_FUSION_VECTOR30_FWD_HPP_INCLUDED

#include <eina_boost/preprocessor/cat.hpp>
#include <eina_boost/preprocessor/iteration/iterate.hpp>
#include <eina_boost/preprocessor/repetition/enum_params.hpp>

#if !defined(EFL_EINA_BOOST_FUSION_DONT_USE_PREPROCESSED_FILES)
#include <eina_boost/fusion/container/vector/detail/preprocessed/vector30_fwd.hpp>
#else
#if defined(__WAVE__) && defined(EFL_EINA_BOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "detail/preprocessed/vector30_fwd.hpp")
#endif

/*=============================================================================
    Copyright (c) 2011 Eric Niebler
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    This is an auto-generated file. Do not edit!
==============================================================================*/

#if defined(__WAVE__) && defined(EFL_EINA_BOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

namespace efl_eina_boost { namespace fusion
{
    // expand vector21 to vector30
    #define EFL_EINA_BOOST_PP_FILENAME_1 <eina_boost/fusion/container/vector/vector30_fwd.hpp>
    #define EFL_EINA_BOOST_PP_ITERATION_LIMITS (21, 30)
    #include EFL_EINA_BOOST_PP_ITERATE()
}}

#if defined(__WAVE__) && defined(EFL_EINA_BOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif // EFL_EINA_BOOST_FUSION_DONT_USE_PREPROCESSED_FILES

#endif

#else

    template <EFL_EINA_BOOST_PP_ENUM_PARAMS(EFL_EINA_BOOST_PP_ITERATION(), typename T)>
    struct EFL_EINA_BOOST_PP_CAT(vector, EFL_EINA_BOOST_PP_ITERATION());

#endif
