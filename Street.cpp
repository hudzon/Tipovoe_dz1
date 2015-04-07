// Copyright 2015 <Sergey Gudz>

#include "1.h"

Street::Street() : List<House>()
{
	number = 0;
	houses_num = 0;
	repair = false;
}

Street::Street(int number, bool repair) :List<House>()
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
	cur = first->getnext();

	int s = 0;
	House *h;
	
	if (cur)
	while (cur)
	{
		h = &cur->getp();
		s += h->getinhabitant();
		cur=cur->getnext();
	}

	return s;
}


House * Street::searchhouse(int i)
{
	if (!has(i))
		throw "Not found";
	return &cur->getp();
}

void Street::add(const House& h)
{
	if (has(h.getnum()))
		throw "Already have";
	
	List<House>::add(h);
	++houses_num;
}

void Street::del(const House & h)
{
	if (!has(h.getnum()))
		throw "Not have";

	List<House>::del(h);
	--houses_num;
}

bool Street::has(int i)
{
	cur = first;

	while ((cur) && (cur->getp().getnum() != i))
	{
		cur = cur->getnext();
	}
	if (cur)
	{
		if (cur->getp().getnum() == i)
			return true;
	}
	return false;
}

std::ostream & operator <<(std::ostream & osout, Street * str)
{
	str->cur = str->first->getnext();

	osout << "Street " << str->number << " Houses num: " << str->houses_num << " Repair: ";
	if(str->repair)
		osout<< "true"<< std::endl;
	else osout << "false" << std::endl;
	while (str->cur)
	{
		osout << "     " << str->cur->getp();
		str->cur=str->cur->getnext();
	}

	return osout;
}