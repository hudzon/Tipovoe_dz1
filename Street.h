// Copyright 2015 <Sergey Gudz>

#pragma once

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
	void del(const House&);
	bool has(int);
	void changeallstreet(int,bool);
	const int getnumber();
	const int getnuminhabitants();
	House * searchhouse(int);

	friend std::ostream & operator <<(std::ostream &,Street*);
};