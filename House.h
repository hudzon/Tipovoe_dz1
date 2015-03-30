#include <iostream>

class House
{
	int number;
	int level;
	int inhabitant;
	bool repair;

public:
	House(const House&);
	House(int number, int level, int inhabitant, bool repair);
	House(int number, int level);
	~House();

	void changeallhouse(int,int,bool);
	void print();
	const int getinhabitant();
	void setinhabitant(int);
	const int getnum();
	void setnum(int);

	friend std::ostream & operator <<(std::ostream&,House*);
	House& operator =(House&);
	bool operator ==(House&);
};