// Copyright 2015 <Sergey Gudz>

#pragma once
#include <string>

class Street:public List<House> {
  std::string name;
  bool repair;

 public:
  Street();
  Street(std::string, bool);
  Street(const Street&);
  ~Street();

  void add(const House&);
  void del(const House&);
  void del_in_order(int i);
  bool has(int a);
  House& search_house(int n);
  void change_all_street(std::string, bool);
  int get_num_inhabitants() const;
  std::string get_name() const;
  void set_name(std::string num);

  bool get_repair() const;
  void set_repair(bool repair);

  const Street& operator =(const Street&);
  bool operator ==(const Street&) const;
  friend std::ostream& operator <<(std::ostream&, Street);
};
