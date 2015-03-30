#include "Container.h"

template<class T>
List<T>::List(Element<T> *first)
{
	this->first = first;
	cur = first;
}

template<class T>
void List<T>::add(T pp)
{

	Element<T> *tmp = new Element<T>(pp, cur->getnext());
	cur->setnext(tmp);

	cur = first->getnext();
}

template<class T>
void List<T>::del(T el)
{
	while (cur->getnext()->getp() != el)
	{
		cur = cur->getnext();
	}
	cur->setnext(cur->getnext()->getnext());

	cur = first->getnext();
}