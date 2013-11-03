
#ifndef EFL_EINA_BOOST_MPL_AUX_POP_FRONT_IMPL_HPP_INCLUDED
#define EFL_EINA_BOOST_MPL_AUX_POP_FRONT_IMPL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: pop_front_impl.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-10 23:19:02 -0700 (Fri, 10 Oct 2008) $
// $Revision: 49267 $

#include <eina_boost/mpl/pop_front_fwd.hpp>
#include <eina_boost/mpl/aux_/traits_lambda_spec.hpp>
#include <eina_boost/mpl/aux_/config/workaround.hpp>
#include <eina_boost/mpl/aux_/config/msvc.hpp>

namespace efl_eina_boost { namespace mpl {

// no default implementation; the definition is needed to make MSVC happy

template< typename Tag >
struct pop_front_impl
{
    template< typename Sequence > struct apply
    // conservatively placed, but maybe should go outside surrounding
    // braces.
#if EFL_EINA_BOOST_WORKAROUND(EFL_EINA_BOOST_MSVC, <= 1300) 
    {
        typedef int type;
    }
#endif
    ;
};

EFL_EINA_BOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC(1, pop_front_impl)

}}

#endif // EFL_EINA_BOOST_MPL_AUX_POP_FRONT_IMPL_HPP_INCLUDED
