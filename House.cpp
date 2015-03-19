#include "House.h"

house::house()
{
	number = 0;
	level = 0;
	inhabitant = 0;
	repair = false;
}

house::house(int number, int level, int inhabitant, bool repair)
{
	this->number = number;
	this->level = level;
	this->inhabitant = inhabitant;
	this->repair = repair;
}

house::house(int number, int level)
{
	this->number = number;
	this->level = level;
	inhabitant = 0;
	repair = false;
}

house::~house()
{
	number = 0;
	level = 0;
	inhabitant = 0;
	repair = false;
}

void house::ChangeAllHouse(int number, int inhabitant, bool repair)
{
	this->number = number;
	this->inhabitant = inhabitant;
	this->repair = repair;
}

void house::Print()
{
	std::cout << "Home " << number << " ," << inhabitant << " inhabitants, repair - " << repair << std::endl;
}

int house::GetInhabitant()
{
	return inhabitant;
}

int house::GetNum()
{
	return number;
}

ostream & operator <<(ostream & osout, house *h)
{
	osout << "Home " << h->number << ", " << h->level << " levels, " << h->inhabitant << " inhabitants, repair - ";
	if (h->repair)
		osout << "true" << endl;
	else osout << "false" << endl;
	
	return osout;
}

house & house::operator =(house & h)
{
	number = h.number;
	level = h.level;
	inhabitant = h.inhabitant;
	repair = h.repair;

	return *this;
}