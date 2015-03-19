#include "Container.h"

element::element(void *pp, element *next)
{
	this->pp = pp;
	this->next = next;
}

element::~element()
{
	delete pp, next;
}

element * element::getnext()
{
	return next;
}

void element::setnext(element *next)
{
	this->next = next;
}

void *element::getp()
{
	return pp;
}

///////////////////////////////////////////////////

list::list(element *first)
{
	this->first = first;
	cur = first;
}

void list::add(int i, void *pp)
{
	cur = first; 

	for (int j = 0; j < i - 1; j++)
		cur = cur->getnext();
	element *tmp = new element(pp, cur->getnext());
	cur->setnext(tmp);

	cur = first->getnext();
}

void list::del(void *el)
{
	cur = first;

	while (cur->getnext()->getp() != el)
	{
		cur = cur->getnext();
	}
	cur->setnext(cur->getnext()->getnext());

	cur = first->getnext();
}

element *list::getcur()
{
	return cur;
}

void list::setcur(element *cur)
{
	this->cur = cur;
}