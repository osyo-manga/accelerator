// accelerator-vec-library
// Copyright (c) 2010 osyo-manga : http://d.hatena.ne.jp/osyo-manga/
//

#include <accelerator/vec/type_traits/value_type.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>
#include <d3dx9.h>

using accelerator::vec::value_type;

/**
	vec 型の要素の型を取得するメタクラスです。
	ユーザ側で定義する vec 型をライブラリで使用する為に必要なメタ関数です。

	使用する為には、

	1.accelerator::vec::value_type の 特殊化を行う
	2.accelerator::vec::vec_traits の 特殊化を行い、value_type を定義する
	3.vec 型で、value_type を定義する
	
	の3つがあります。
	複数定義されている場合は、上から順にプラオリティが高くなっています。
	（vec 型で、value_type を定義し、accelerator::vec::value_type も特殊化している場合は、
	　accelerator::vec::value_type で、定義されている型が優先されます）
*/


//----------------------------------------------------------
// ユーザ側で定義する vec 型の場合は、value_type を定義する
struct my_vec{
	typedef float value_type;	// 要素の型を定義する
	value_type x, y, z;
};

BOOST_STATIC_ASSERT((
	boost::is_same<value_type<my_vec>::type, float>::value
));


//----------------------------------------------------------
// すでに定義済みの vec 型は、template の特殊化を行い、定義する
namespace accelerator { namespace vec {

template<>
struct value_type<D3DVECTOR>{
	typedef float type;
};

} } // namespace accelerator { namespace vec {

// マクロで定義することも出来る
// ACCELERATOR_VEC_VALUE_TYPE(D3DVECTOR, float)

BOOST_STATIC_ASSERT((
	boost::is_same<value_type<D3DVECTOR>::type, float>::value
));


//----------------------------------------------------------
// 両方で定義されている場合は、value_type の特殊化が優先される
struct my_vec2{
	typedef float value_type;
	value_type x, y, z;
};
ACCELERATOR_VEC_VALUE_TYPE(my_vec2, double)

BOOST_STATIC_ASSERT((
	boost::is_same<value_type<my_vec2>::type, double>::value
));



int
main(){
	
	return 0;
}
