// accelerator-vec-library
// Copyright (c) 2010 osyo-manga : http://d.hatena.ne.jp/osyo-manga/
//
#include <boost/test/minimal.hpp>
#include <boost/type_traits/is_same.hpp>

#include <accelerator/vec/type_traits/dimension.hpp>


struct my_vec_dimension{
	static const std::size_t dimension = 3;
};

struct my_vec_dimension2{
	static const std::size_t dimension = 3;
};

struct my_vec_dimension3{
	static const std::size_t dimension = 3;
};

struct my_vec_dimension4{
	static const std::size_t dimension = 3;
};


namespace accelerator{ namespace vec{

template<>
struct dimension<my_vec_dimension2>{
	static const std::size_t value = 4;
};

template<>
struct vec_traits<my_vec_dimension3>{
	static const std::size_t dimension = 5;
};

template<>
struct vec_traits<my_vec_dimension4>{
	static const std::size_t dimension = 5;
};

} } // namespace accelerator{ namespace vec{

ACCELERATOR_VEC_DIMENSION(my_vec_dimension4, 6)


int
test_main(int argc, char* argv[]){
	namespace vec = accelerator::vec;
	
	BOOST_CHECK(( vec::dimension<my_vec_dimension>::value == 3 ));
	BOOST_CHECK(( vec::dimension<my_vec_dimension2>::value == 4 ));
	BOOST_CHECK(( vec::dimension<my_vec_dimension3>::value == 5 ));
	BOOST_CHECK(( vec::dimension<my_vec_dimension4>::value == 6 ));
	
	
	return 0;
}

