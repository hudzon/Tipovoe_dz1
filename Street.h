// Copyright 2015 <Sergey Gudz>

#pragma once

class Street:public List<House> {
  int number;
  int houses_num;
  bool repair;

 public:
  Street();
  Street(int, bool);
  Street(const Street&);
  ~Street();

  void add(const House&);
  void del(const House&);
  void del_in_order(int i);
  bool has(int a);
  House& search_house(int n);
  void change_all_street(int, bool);
  int get_num_inhabitants() const;
  int get_number() const;
  void set_number(int num);

  bool get_repair() const;
  void set_repair(bool repair);

  const Street& operator =(const Street&);
  bool operator ==(const Street&) const;
  friend std::ostream& operator <<(std::ostream&, Street*);
};
