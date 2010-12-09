// accelerator-vec-library
// Copyright (c) 2010 osyo-manga : http://d.hatena.ne.jp/osyo-manga/
//
#include <boost/test/minimal.hpp>

#include <accelerator/vec/type_traits/has_iterator.hpp>

struct my_vec{
	typedef void iterator;
	typedef void const_iterator;
};

struct not_vec{};

int
test_main(int argc, char* argv[]){
	
	using accelerator::vec::has_iterator;
	using accelerator::vec::has_const_iterator;

	BOOST_CHECK(( has_iterator<my_vec>::value == true ));
	BOOST_CHECK(( has_iterator<not_vec>::value == false ));
	
	BOOST_CHECK(( has_const_iterator<my_vec>::value == true ));
	BOOST_CHECK(( has_const_iterator<not_vec>::value == false ));
	
	return 0;
}
