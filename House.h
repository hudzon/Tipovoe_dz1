// Copyright 2015 <Sergey Gudz>

#pragma once

class House {
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

  void changeallhouse(int a, int b, bool c);
  void print();
  const int getinhabitant();
  void setinhabitant(int inhabitant);
  const int getnum()const;
  void setnum(int number);

  friend std::ostream & operator <<(std::ostream&, House);
  House& operator =(const House&);
  bool operator ==(const House&);
};
