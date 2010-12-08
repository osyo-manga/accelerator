// accelerator-vec-library
// Copyright (c) 2010 osyo-manga : http://d.hatena.ne.jp/osyo-manga/
// 

#ifndef _ACCELERATOR_TYPE_TRAITS_SFINAE_HELPER_H_
#define _ACCELERATOR_TYPE_TRAITS_SFINAE_HELPER_H_

namespace accelerator{ namespace detail{

template<typename T>
struct sfinae_helper{
	typedef void type;
};

template<typename T, T N>
struct sfinae_helper_value{
	typedef void type;
};


} }  // namespace accelerator{ namespace detail{

#endif // _ACCELERATOR_TYPE_TRAITS_SFINAE_HELPER_H_
