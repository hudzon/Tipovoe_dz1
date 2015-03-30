#include "Element.h"

template<class T>
Element<T>::Element(T pp, Element *next)
{
	this->pp = pp;
	this->next = next;
}

template<class T>
Element<T>::~Element(){}

template<class T>
Element<T> * Element<T>::getnext()
{
	return next;
}

template<class T>
void Element<T>::setnext(Element *next)
{
	this->next = next;
}

template<class T>
T Element<T>::getp()
{
	return pp;
}