#include "Street.h"

int main()
{
	street *str[3];

	for (int i = 0; i < 3; ++i)
	{
		str[i] = new street(i + 1, true);
		str[i]->addhouse(new house(1, 9, 106, true),1);
		str[i]->addhouse(new house(2, 8, 91, true), 1);
		str[i]->addhouse(new house(3, 2, 33, true), 3);
		str[i]->addhouse(new house(4, 3, 42, true), 3);
	}
	for (int i = 0; i < 3; ++i)
		cout << str[i] << endl;

	cout << endl << "After" << endl;

	str[0]->ChangeAllStreet(10, false);
	str[0]->SearchHouse(3)->ChangeAllHouse(3,123, false);
	str[1]->delhouse(3);
	str[2]->delhouse(2);
	str[2]->delhouse(3);
	for (int i = 0; i < 3; ++i)
		cout << str[i] << endl;
	return 0;
}