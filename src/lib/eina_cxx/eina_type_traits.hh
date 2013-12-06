#ifndef _EINA_TYPE_TRAITS_HH
#define _EINA_TYPE_TRAITS_HH

#if __cplusplus >= 201103L
#include <type_traits>
#else
#include <eina_boost/utility/enable_if.hpp>
#include <eina_boost/type_traits/is_integral.hpp>
#include <eina_boost/type_traits/is_pod.hpp>
#include <eina_boost/type_traits/remove_cv.hpp>
#include <eina_boost/type_traits/is_const.hpp>
#endif

#include <string>
#include <vector>

namespace efl { namespace eina {

#if __cplusplus >= 201103L
using std::enable_if;
using std::enable_if_c;
using std::is_integral;
using std::is_pod;
using std::is_const;
using std::remove_cv;
using std::true_type;
using std::false_type;
#else
using ::efl_eina_boost::enable_if;
using ::efl_eina_boost::enable_if_c;
using ::efl_eina_boost::is_integral;
using ::efl_eina_boost::is_pod;
using ::efl_eina_boost::is_const;
using ::efl_eina_boost::remove_cv;
typedef ::efl_eina_boost::mpl::true_ true_type;
typedef ::efl_eina_boost::mpl::false_ false_type;
#endif

template <typename T, typename Enable = void>
struct is_contiguous_iterator : false_type {};
template <>
struct is_contiguous_iterator<std::string::const_iterator> : true_type {};
template <>
struct is_contiguous_iterator<std::string::iterator> : true_type {};
template <>
struct is_contiguous_iterator<std::vector<char>::const_iterator> : true_type {};
template <>
struct is_contiguous_iterator<std::vector<char>::iterator> : true_type {};

} }

#endif
