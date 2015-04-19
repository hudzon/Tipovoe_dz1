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

  void change_all_house(int a, int b, bool c);
  void print();
  int get_inhabitant() const;
  void set_inhabitant(int inhabitant);

  int get_num() const;
  void set_num(int number);

  int get_level() const;
  void set_level(int level);

  bool get_repair() const;
  void set_repair(bool repair);

  friend std::ostream& operator <<(std::ostream&, House);
  const House& operator =(const House&);
  bool operator ==(const House&) const;
};
