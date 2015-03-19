#include <iostream>
using namespace std;

class house
{
	int number;
	int level;
	int inhabitant;
	bool repair;

public:
	house();
	house(int, int, int, bool);
	house(int, int);
	~house();

	void ChangeAllHouse(int,int,bool);
	void Print();
	int GetInhabitant();
	int GetNum();

	friend ostream & operator <<(ostream&,house*);
	house& operator =(house&);
};