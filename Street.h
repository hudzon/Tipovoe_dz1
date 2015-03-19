#include "House.h"
#include "Container.h"

class street
{
	int number;
	int houses_num;
	list *HouseList;
	bool repair;
public:
	street();
	street(int, bool);
	~street();

	void addhouse(house *,int);
	void delhouse(int);
	void ChangeAllStreet(int,bool);
	int getnumber();
	int getnuminhabitants();
	house *SearchHouse(int);

	friend ostream & operator <<(ostream &,street*);
};