// accelerator-vec-library
// Copyright (c) 2010 osyo-manga : http://d.hatena.ne.jp/osyo-manga/
//
#include <boost/test/minimal.hpp>

#include <accelerator/vec/type_traits/has_value_type.hpp>


struct my_vec{
	typedef void value_type;
};

struct not_vec{};


int
test_main(int argc, char* argv[]){
	
	using accelerator::vec::has_value_type;

	BOOST_CHECK(( has_value_type<my_vec>::value ));
	BOOST_CHECK(( has_value_type<not_vec>::value == false ));
	
	return 0;
}
