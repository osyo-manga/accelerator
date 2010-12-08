// accelerator-vec-library
// Copyright (c) 2010 osyo-manga : http://d.hatena.ne.jp/osyo-manga/
// 

#ifndef _ACCELERATOR_VEC_TYPE_TRAITS_VALUE_TYPE_H_
#define _ACCELERATOR_VEC_TYPE_TRAITS_VALUE_TYPE_H_

#include "../../type_traits/detail/sfinae_helper.hpp"
#include "vec_traits.hpp"

namespace accelerator{ namespace vec{

namespace detail{

using accelerator::detail::sfinae_helper;

template<typename T, typename U = void>
struct value_type_impl{
	typedef typename T::value_type type;
};

template<typename T>
struct value_type_impl<T, typename sfinae_helper<typename vec_traits<T>::value_type>::type>{
	typedef typename vec_traits<T>::value_type type;
};

}  // namespace detail


template<typename T>
struct value_type : public detail::value_type_impl<T>{};


#define ACCELERATOR_VEC_VALUE_TYPE(_class, _value_type)	\
namespace accelerator { namespace vec {					\
														\
template<> struct value_type<_class>{					\
	typedef _value_type type;							\
};														\
														\
} } // namespace accelerator { namespace vec {


} }  // namespace accelerator{ namespace vec{


#endif // _ACCELERATOR_VEC_TYPE_TRAITS_VALUE_TYPE_H_
