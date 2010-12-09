// accelerator-vec-library
// Copyright (c) 2010 osyo-manga : http://d.hatena.ne.jp/osyo-manga/
//
#include <accelerator/vec/type_traits/dimension.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>
#include <d3dx9.h>

using accelerator::vec::dimension_type;
using accelerator::vec::dimension;

/**
	vec 型の次元数を取得するメタ関数です。
	ユーザ側で定義する vec 型をライブラリで使用する為に必要なメタ関数です。
	次元数を std::size_t 型の定数で定義します。

	使用する為には、

	1.accelerator::vec::dimension の 特殊化を行う
	2.accelerator::vec::vec_traits の 特殊化を行い、dimension_type 型の dimensio を定義する
	3.vec 型で、dimension_type 型の dimension を定義する
	
	の3つがあります。
	複数定義されている場合は、上から順にプラオリティが高くなっています。
	（vec 型で、dimension を定義し、accelerator::vec::dimension も特殊化している場合は、
	　accelerator::vec::dimension で、定義されている値が優先されます）

	また、次元数が可変長の vec 型(std::vector を使用する等)の場合は、使用することが出来ません。
*/


//----------------------------------------------------------
// ユーザ側で定義する vec 型の場合は、dimension を定義する
struct my_vec{
	static const dimension_type dimension = 3;
};

BOOST_STATIC_ASSERT(( dimension<my_vec>::value == 3 ));


//----------------------------------------------------------
// すでに定義済みの vec 型は、template の特殊化を行い、定義する
namespace accelerator { namespace vec {

template<>
struct dimension<D3DVECTOR>{
	static const dimension_type value = 3;
};

} } // namespace accelerator { namespace vec {

// マクロで定義することも出来る
//ACCELERATOR_VEC_DIMENSION(D3DVECTOR, 3)

BOOST_STATIC_ASSERT(( dimension<D3DVECTOR>::value == 3 ));


//----------------------------------------------------------
// 両方で定義されている場合は、dimension の特殊化が優先される
struct my_vec2{
	static const dimension_type dimension = 3;
};
ACCELERATOR_VEC_DIMENSION(my_vec2, 2)

BOOST_STATIC_ASSERT(( dimension<my_vec2>::value == 2 ));


int
main(){

	return 0;
}
