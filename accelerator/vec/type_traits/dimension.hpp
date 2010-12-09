// accelerator-vec-library
// Copyright (c) 2010 osyo-manga : http://d.hatena.ne.jp/osyo-manga/
//

#ifndef _ACCELERATOR_VEC_DIMENSION_H_
#define _ACCELERATOR_VEC_DIMENSION_H_

#include "../../type_traits/detail/sfinae_helper.hpp"
#include "vec_traits.hpp"
#include <boost/mpl/int.hpp>


namespace accelerator { namespace vec {

namespace detail{

using accelerator::detail::sfinae_helper_value;

template<typename T, typename U = void>
struct dimension_impl{
	static const std::size_t value = T::dimension;
};

template<typename T>
struct dimension_impl<T, typename sfinae_helper_value<std::size_t, vec_traits<T>::dimension>::type>{
	static const std::size_t value = vec_traits<T>::dimension;
};

}  // namespace detail


template<typename T>
struct dimension : public boost::mpl::int_<detail::dimension_impl<T>::value>{};


#define ACCELERATOR_VEC_DIMENSION(_class, _dimension)	\
namespace accelerator { namespace vec {					\
														\
template<> struct dimension<_class>{					\
	static const std::size_t value = _dimension;		\
};														\
														\
} } // namespace accelerator { namespace vec {



} }  // namespace accelerator { namespace vec {


#endif  // _ACCELERATORC_VEC_DIMENSION_H_
