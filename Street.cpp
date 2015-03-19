#include "Street.h"

street::street()
{
	number = 0;
	houses_num = 0;
	HouseList = new list(new element(0,0));
	repair = false;
}

street::street(int number, bool repair)
{
	this->number = number;
	houses_num = 0;
	HouseList = new list(new element(0, 0));
	this->repair = repair;
}

street::~street()
{
	number = 0;
	houses_num = 0;
	delete HouseList;
	repair = false;
}

void street::addhouse(house* ph, int i)
{
	HouseList->add(i, (void*)ph);
	++houses_num;
}

void street::delhouse(int i)
{
	HouseList->del((void*)SearchHouse(i));
	--houses_num;
}

void street::ChangeAllStreet(int number, bool repair)
{
	this->number = number;
	this->repair = repair;
}

int street::getnumber()
{
	return number;
}

int street::getnuminhabitants()
{
	int s = 0;
	house *h;
	list p = *HouseList;
	
	if (&p)
	while (p.getcur())
	{
		h = (house*)p.getcur()->getp();
		s += h->GetInhabitant();
		p.setcur(p.getcur()->getnext());
	}

	return s;
}


house *street::SearchHouse(int i)
{
	list p = *HouseList;
	house *h = (house*)p.getcur()->getp();

	while (h->GetNum()!=i)
	{
		p.setcur(p.getcur()->getnext());
		h = (house*)p.getcur()->getp();
	}

	return h;
}

ostream & operator <<(ostream & osout, street * str)
{
	list p = *str->HouseList;

	osout << "Street " << str->number << " Houses num: " << str->houses_num << " Repair: ";
	if(str->repair)
		osout<< "true"<< endl;
	else osout << "false" << endl;
	while ((house*)p.getcur())
	{
		osout << "     " << (house*)p.getcur()->getp();
		p.setcur(p.getcur()->getnext());
	}
	return osout;
}