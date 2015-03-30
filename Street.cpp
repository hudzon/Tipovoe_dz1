#include "Street.h"

Street::Street() : List<House>(0)
{
	number = 0;
	houses_num = 0;
	repair = false;
	
}

Street::Street(int number, bool repair) :List<House>(0)
{
	this->number = number;
	houses_num = 0;
	this->repair = repair;
}

Street::~Street(){}

void Street::changeallstreet(int number, bool repair)
{
	this->number = number;
	this->repair = repair;
}

const int Street::getnumber()
{
	return number;
}

const int Street::getnuminhabitants()
{
	int s = 0;
	House *h;
	
	if (cur)
	while (cur)
	{
		h = &cur->getp();
		s += h->getinhabitant();
		cur=cur->getnext();
	}

	cur = first->getnext();
	return s;
}


House Street::searchhouse(int i)
{
	House h(0, 0);

	do
	{
		h = cur->getp();
		cur = cur->getnext();
	} while ((h.getnum() != i)&&(cur));

	if (h.getnum()!=i)
		std::cout << std::endl << number <<
		" street doesn't have " << i << " house " << std::endl;

	cur = first->getnext();
	return h;
}

void Street::add(const House& h)
{
	House h1(h);
	if (!has(h1.getnum()))
		List<House>::add(h);
	else std::cout << h1.getnum() <<
		" house wasn't added, because " << number << " street already has it" << std::endl;
}

void Street::del(int i)
{
	if (has(i))
		List<House>::del(searchhouse(i));
	else std::cout << i <<
		" house wasn't deleted, because " << number << " street doesn't have it" << std::endl;
}

bool Street::has(int i)
{
	House h(0, 0);

	do
	{
		h = cur->getp();
		cur = cur->getnext();
	} while ((h.getnum() != i) && (cur));

	cur = first->getnext();
	if (h.getnum()==i)
		return true;
	else return false;
}

std::ostream & operator <<(std::ostream & osout, Street * str)
{
	osout << "Street " << str->number << " Houses num: " << str->houses_num << " Repair: ";
	if(str->repair)
		osout<< "true"<< std::endl;
	else osout << "false" << std::endl;
	while (str->cur)
	{
		osout << "     " << &str->cur->getp();
		str->cur=str->cur->getnext();
	}

	str->cur = str->first->getnext();
	return osout;
}