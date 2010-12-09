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
	vec �^�̎��������擾���郁�^�֐��ł��B
	���[�U���Œ�`���� vec �^�����C�u�����Ŏg�p����ׂɕK�v�ȃ��^�֐��ł��B
	�������� std::size_t �^�̒萔�Œ�`���܂��B

	�g�p����ׂɂ́A

	1.accelerator::vec::dimension �� ���ꉻ���s��
	2.accelerator::vec::vec_traits �� ���ꉻ���s���Adimension_type �^�� dimensio ���`����
	3.vec �^�ŁAdimension_type �^�� dimension ���`����
	
	��3������܂��B
	������`����Ă���ꍇ�́A�ォ�珇�Ƀv���I���e�B�������Ȃ��Ă��܂��B
	�ivec �^�ŁAdimension ���`���Aaccelerator::vec::dimension �����ꉻ���Ă���ꍇ�́A
	�@accelerator::vec::dimension �ŁA��`����Ă���l���D�悳��܂��j

	�܂��A���������ϒ��� vec �^(std::vector ���g�p���铙)�̏ꍇ�́A�g�p���邱�Ƃ��o���܂���B
*/


//----------------------------------------------------------
// ���[�U���Œ�`���� vec �^�̏ꍇ�́Adimension ���`����
struct my_vec{
	static const dimension_type dimension = 3;
};

BOOST_STATIC_ASSERT(( dimension<my_vec>::value == 3 ));


//----------------------------------------------------------
// ���łɒ�`�ς݂� vec �^�́Atemplate �̓��ꉻ���s���A��`����
namespace accelerator { namespace vec {

template<>
struct dimension<D3DVECTOR>{
	static const dimension_type value = 3;
};

} } // namespace accelerator { namespace vec {

// �}�N���Œ�`���邱�Ƃ��o����
//ACCELERATOR_VEC_DIMENSION(D3DVECTOR, 3)

BOOST_STATIC_ASSERT(( dimension<D3DVECTOR>::value == 3 ));


//----------------------------------------------------------
// �����Œ�`����Ă���ꍇ�́Adimension �̓��ꉻ���D�悳���
struct my_vec2{
	static const dimension_type dimension = 3;
};
ACCELERATOR_VEC_DIMENSION(my_vec2, 2)

BOOST_STATIC_ASSERT(( dimension<my_vec2>::value == 2 ));


int
main(){

	return 0;
}
