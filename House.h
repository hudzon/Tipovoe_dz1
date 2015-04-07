// Copyright 2015 <Sergey Gudz>

#pragma once

class House
{
	int number;
	int level;
	int inhabitant;
	bool repair;

public:
	House();
	House(const House&);
	House(int number, int level, int inhabitant, bool repair);
	House(int number, int level);
	~House();

	void changeallhouse(int,int,bool);
	void print();
	const int getinhabitant();
	void setinhabitant(int);
	const int getnum()const;
	void setnum(int);

	friend std::ostream & operator <<(std::ostream&,House);
	House& operator =(House&);
	bool operator ==(House&);
};