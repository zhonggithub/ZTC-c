/*
* Copyright (c) 2013 ZZ
* All rights reserved.
* 
* File Name       : ZIterator.hpp
* File Identifier :
* Abstract        :
* 
* Current Version : 1.0
* Author          : ZZ
* Completion Date : 2013.12.2 22:40:54
*
* Replace Version : 
* Original Author :
* Completion Date : 2013.12.2 22:40:54
*/

#ifndef ZTC_INCLUDE_ZITERATOR_HPP
#define ZTC_INCLUDE_ZITERATOR_HPP

#include "ZMacroDefine.h"

BEGIN_ZTC_NAMESPACE

/*------@ ���ֵ���������
*/
struct input_iterator_tag{}; //ֻ��������
struct output_iterator_tag{}; //Ψд������
struct forward_iterator_tag : public input_iterator_tag{}; //��д������
struct bidirectional_iterator_tag : public forward_iterator_tag{}; //˫���ƶ�������
struct random_access_iterator_tag : public bidirectional_iterator_tag{}; //���������

/*-----@ ��������������
*/
template <class Category, 
		  class T, 
		  class Distance = ptrdiff_t, 
		  class Pointer = T*, 
		  class Reference = T&>
struct ZIterator
{
	typedef Category iterator_category;
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
};

/*----- ��������ȡ
*/
template <class Iterator>
struct ZIteratorTraits
{
	typedef typename Iterator::iterator_category iterator_category;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
};

/*----- ��������ȡ��һ��ָ���ƫ�ػ�
*/
template <class T>
struct ZIteratorTraits <T*>
{
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
};

/*----- ��������ȡ��constָ���ƫ�ػ�
*/
template <class T>
struct ZIteratorTraits <const T*>
{
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef const T* pointer;
	typedef const T& reference;
};

template <class Iterator>
inline typename iterator_traits<Iterator>::iterator_category
iterator_category(const Iterator&)
{
	typedef typename iterator_traits<Iterator>::iterator_category category;
	return category();
}

template <class Iterator>
inline typename iterator_traits<Iterator>::difference_type*
distance_type(const Iterator&)
{
	return static_cast<typename iterator_traits<Iterator>::difference_type* >(0);
}

template <class Iterator>
inline typename iterator_traits<Iterator>::value_type*
value_type(const Iterator&)
{
	return static_cast<typename iterator_traits<Iterator>::value_type*>(0);
}

template <class InputIterator>
inline iterator_traits<InputIterator>::difference_type
__distance(InputIterator first, InputIterator last, input_iterator_tag)
{
	iterator_traits<InputIterator>::difference_type n = 0;
	while(first != last)
	{
		++first;
		++n;
	}
	return n;
}

END_ZTC_NAMESPACE
#endif //ZTC_INCLUDE_ZITERATOR_HPP