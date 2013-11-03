
#ifndef EFL_EINA_BOOST_MPL_AUX_CONFIG_ETI_HPP_INCLUDED
#define EFL_EINA_BOOST_MPL_AUX_CONFIG_ETI_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: eti.hpp 49267 2008-10-11 06:19:02Z agurtovoy $
// $Date: 2008-10-10 23:19:02 -0700 (Fri, 10 Oct 2008) $
// $Revision: 49267 $

#include <eina_boost/mpl/aux_/config/msvc.hpp>
#include <eina_boost/mpl/aux_/config/workaround.hpp>

// flags for MSVC 6.5's so-called "early template instantiation bug"
#if    !defined(EFL_EINA_BOOST_MPL_CFG_MSVC_60_ETI_BUG) \
    && !defined(EFL_EINA_BOOST_MPL_PREPROCESSING_MODE) \
    && EFL_EINA_BOOST_WORKAROUND(EFL_EINA_BOOST_MSVC, < 1300)

#   define EFL_EINA_BOOST_MPL_CFG_MSVC_60_ETI_BUG

#endif

#if    !defined(EFL_EINA_BOOST_MPL_CFG_MSVC_70_ETI_BUG) \
    && !defined(EFL_EINA_BOOST_MPL_PREPROCESSING_MODE) \
    && EFL_EINA_BOOST_WORKAROUND(EFL_EINA_BOOST_MSVC, == 1300)

#   define EFL_EINA_BOOST_MPL_CFG_MSVC_70_ETI_BUG

#endif

#if    !defined(EFL_EINA_BOOST_MPL_CFG_MSVC_ETI_BUG) \
    && !defined(EFL_EINA_BOOST_MPL_PREPROCESSING_MODE) \
    && ( defined(EFL_EINA_BOOST_MPL_CFG_MSVC_60_ETI_BUG) \
        || defined(EFL_EINA_BOOST_MPL_CFG_MSVC_70_ETI_BUG) \
        )

#   define EFL_EINA_BOOST_MPL_CFG_MSVC_ETI_BUG

#endif

#endif // EFL_EINA_BOOST_MPL_AUX_CONFIG_ETI_HPP_INCLUDED
