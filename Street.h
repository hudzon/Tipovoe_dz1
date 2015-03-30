#include "House.h"
#include "Container.h"

class Street:public List<House>
{
	int number;
	int houses_num;
	bool repair;
public:
	Street();
	Street(int, bool);
	~Street();

	void add(const House&);
	void del(int);
	bool has(int);
	void changeallstreet(int,bool);
	const int getnumber();
	const int getnuminhabitants();
	House searchhouse(int);

	friend std::ostream & operator <<(std::ostream &,Street*);
};