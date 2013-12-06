//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// The aim of this header is just to include <functional> but to do
// so in a way that does not result in recursive inclusion of
// the Boost TR1 components if boost/tr1/tr1/functional is in the
// include search path.  We have to do this to avoid circular
// dependencies:
//

#ifndef EFL_EINA_BOOST_CONFIG_FUNCTIONAL
#  define EFL_EINA_BOOST_CONFIG_FUNCTIONAL

#  ifndef EFL_EINA_BOOST_TR1_NO_RECURSION
#     define EFL_EINA_BOOST_TR1_NO_RECURSION
#     define EFL_EINA_BOOST_CONFIG_NO_FUNCTIONAL_RECURSION
#  endif

#  include <functional>

#  ifdef EFL_EINA_BOOST_CONFIG_NO_FUNCTIONAL_RECURSION
#     undef EFL_EINA_BOOST_TR1_NO_RECURSION
#     undef EFL_EINA_BOOST_CONFIG_NO_FUNCTIONAL_RECURSION
#  endif

#endif
