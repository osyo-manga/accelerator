// accelerator-vec-library
// Copyright (c) 2010 osyo-manga : http://d.hatena.ne.jp/osyo-manga/
// 

#include <boost/test/minimal.hpp>
#include <boost/type_traits/is_same.hpp>

#include <accelerator/vec/type_tratis/value_type.hpp>

struct my_vec{
	typedef float value_type;
	value_type x, y, z;
};

struct my_vec2{
	typedef float value_type;
	value_type x, y, z;
};

struct my_vec3{
	typedef float value_type;
	value_type x, y, z;
};

namespace accelerator{ namespace vec{

template<>
struct vec_traits<my_vec2>{
	typedef int value_type;
};

template<>
struct vec_traits<my_vec3>{
	typedef int value_type;
};

/*
template<>
struct value_type<my_vec3>{
	typedef double type;
};
*/

} }

ACCELERATOR_VEC_VALUE_TYPE(my_vec3, double)

int
test_main(int argc, char* argv[]){
	
	namespace vec = accelerator::vec;
	
	BOOST_CHECK(( boost::is_same<vec::value_type<my_vec >::type, float>::value ));
	BOOST_CHECK(( boost::is_same<vec::value_type<my_vec2>::type, float>::value == false ));
	BOOST_CHECK(( boost::is_same<vec::value_type<my_vec2>::type, int>::value ));
	BOOST_CHECK(( boost::is_same<vec::value_type<my_vec3>::type, double>::value ));
	
	return 0;
}
