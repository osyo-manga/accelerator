// accelerator-vec-library
// Copyright (c) 2010 osyo-manga : http://d.hatena.ne.jp/osyo-manga/
//

#ifndef _ACCELERATOR_VEC_HAS_DIMENSION_H_
#define _ACCELERATOR_VEC_HAS_DIMENSION_H_

#include "../../type_traits/detail/sfinae_helper.hpp"
#include <boost/mpl/bool.hpp>

namespace accelerator { namespace vec {

namespace detail{

using accelerator::detail::sfinae_helper_value;

template<typename T, typename U = void>
struct has_dimension_impl{
	static const bool value = false;
};

template<typename T>
struct has_dimension_impl<T, typename sfinae_helper_value<std::size_t, T::dimension>::type>{
	static const int value = true;
};

}  // namespace detail


template<typename T>
struct has_dimension : public boost::mpl::bool_<detail::has_dimension_impl<T>::value>{};

} }  // namespace accelerator { namespace vec {


#endif  // _ACCELERATORC_VEC_HAS_DIMENSION_H_
