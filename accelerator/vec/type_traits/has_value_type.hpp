// accelerator-vec-library
// Copyright (c) 2010 osyo-manga : http://d.hatena.ne.jp/osyo-manga/
//

#ifndef _ACCELERATOR_VEC_HAS_VALUE_TYPE_H_
#define _ACCELERATOR_VEC_HAS_VALUE_TYPE_H_

#include "../../type_traits/detail/sfinae_helper.hpp"

#include <boost/mpl/bool.hpp>

namespace accelerator { namespace vec {

namespace detail{

using accelerator::detail::sfinae_helper;

template<typename T, typename U = void>
struct has_value_type_impl{
    static const bool value = false;
};

template<typename T>
struct has_value_type_impl<T, typename sfinae_helper<typename T::value_type>::type>{
    static const bool value = true;
};

}  // namespace detail

template<typename T>
struct has_value_type : public boost::mpl::bool_<detail::has_value_type_impl<T>::value>{};

} }  // namespace accelerator { namespace vec {


#endif  // _ACCELERATORC_VEC_HAS_VALUE_TYPE_H_
