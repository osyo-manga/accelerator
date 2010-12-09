// accelerator-vec-library
// Copyright (c) 2010 osyo-manga : http://d.hatena.ne.jp/osyo-manga/
//
#include <boost/test/minimal.hpp>

#include <accelerator/vec/type_traits/has_dimension.hpp>

struct my_vec{
	static const std::size_t dimension = 3;
};
struct not_vec{};


int
test_main(int argc, char* argv[]){
	
	using accelerator::vec::has_dimension;

	BOOST_CHECK(( has_dimension<my_vec>::value ));
	BOOST_CHECK(( has_dimension<not_vec>::value == false ));
	
	return 0;
}
