#include "Street.h"


int main()
{
	Street *str[3];

	for (int i = 0; i < 3; ++i)
	{
		str[i] = new Street(i + 1, true);
		str[i]->add( House(1, 9, 106, true));
		str[i]->add( House(2, 8, 91, true));
		str[i]->add( House(3, 2, 33, true));
		str[i]->add( House(4, 3, 42, true));
	}
	for (int i = 0; i < 3; ++i)
		std::cout << str[i] << std::endl;
	std::cout << "Number of voters 1 Street: "<< str[0]->getnuminhabitants();

	std::cout << std::endl << "After" << std::endl;

	str[0]->changeallstreet(10, false);
	str[0]->searchhouse(3).changeallhouse(3,123, false);
	str[1]->del(3);
	str[2]->del(2);
	str[2]->del(3);
	for (int i = 0; i < 3; ++i)
		std::cout << str[i] << std::endl;
	std::cout << "Number of voters 1 Street: " << str[0]->getnuminhabitants();
	return 0;
}