// accelerator-vec-library
// Copyright (c) 2010 osyo-manga : http://d.hatena.ne.jp/osyo-manga/
//

#include <accelerator/vec/type_traits/value_type.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>
#include <d3dx9.h>

using accelerator::vec::value_type;

/**
	vec �^�̗v�f�̌^���擾���郁�^�N���X�ł��B
	���[�U���Œ�`���� vec �^�����C�u�����Ŏg�p����ׂɕK�v�ȃ��^�֐��ł��B

	�g�p����ׂɂ́A

	1.accelerator::vec::value_type �� ���ꉻ���s��
	2.accelerator::vec::vec_traits �� ���ꉻ���s���Avalue_type ���`����
	3.vec �^�ŁAvalue_type ���`����
	
	��3������܂��B
	������`����Ă���ꍇ�́A�ォ�珇�Ƀv���I���e�B�������Ȃ��Ă��܂��B
	�ivec �^�ŁAvalue_type ���`���Aaccelerator::vec::value_type �����ꉻ���Ă���ꍇ�́A
	�@accelerator::vec::value_type �ŁA��`����Ă���^���D�悳��܂��j
*/


//----------------------------------------------------------
// ���[�U���Œ�`���� vec �^�̏ꍇ�́Avalue_type ���`����
struct my_vec{
	typedef float value_type;	// �v�f�̌^���`����
	value_type x, y, z;
};

BOOST_STATIC_ASSERT((
	boost::is_same<value_type<my_vec>::type, float>::value
));


//----------------------------------------------------------
// ���łɒ�`�ς݂� vec �^�́Atemplate �̓��ꉻ���s���A��`����
namespace accelerator { namespace vec {

template<>
struct value_type<D3DVECTOR>{
	typedef float type;
};

} } // namespace accelerator { namespace vec {

// �}�N���Œ�`���邱�Ƃ��o����
// ACCELERATOR_VEC_VALUE_TYPE(D3DVECTOR, float)

BOOST_STATIC_ASSERT((
	boost::is_same<value_type<D3DVECTOR>::type, float>::value
));


//----------------------------------------------------------
// �����Œ�`����Ă���ꍇ�́Avalue_type �̓��ꉻ���D�悳���
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
