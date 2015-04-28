// Copyright 2015 <Sergey Gudz>

#include <string>
#include "./main.h"

Street::Street() : List<House>() {
  name = "Ordinary Street";
  repair = false;
}

Street::Street(std::string name, bool repair) :List<House>() {
  this->name = name;
  this->repair = repair;
}

Street::Street(const Street& str) :List<House>() {
  name = str.name;
  repair = str.repair;

  List<House>::operator =(str);
}

Street::~Street() {
}

void Street::change_all_street(std::string name, bool repair) {
  this->name = name;
  this->repair = repair;
}

std::string Street::get_name() const {
  return name;
}

void Street::set_name(std::string name) {
  this->name = name;
}

bool Street::get_repair() const {
  return repair;
}

void Street::set_repair(bool repair) {
  this->repair = repair;
}

int Street::get_num_inhabitants() const {
  Element<House> *cur;
  cur = get_first()->get_next();

  int s = 0;
  House *h;

  if (cur) {
    while (cur) {
      h = &cur->get_p();
      s += h->get_inhabitant();
      cur = cur->get_next();
    }
  }
  return s;
}

House& Street::find(const House& h) const {
  if (!has(h))
    throw ExNotFound(h);

  return List<House>::find(h);
}

void Street::add(const House& h) {
  if (has(h))
    throw ExAlreadyHave(h);

  List<House>::add(h);
}

void Street::del(const House& h) {
  if (!has(h))
    throw ExNotHave(h);

  List<House>::del(h);
}

void Street::del_in_order(int i) {
  if (i > get_num())
    throw ExNotHaveTwo(i);

  List<House>::del(List<House>::find_i(i));
}

bool Street::has(const House& h) const {
  return List<House>::has(h);
}

const Street& Street::operator =(const Street& str) {
  if (this != &str) {
    name = str.name;
    repair = str.repair;

    List<House>::operator =(str);
  }

  return *this;
}

bool Street::operator ==(const Street& str) const {
  return ((name == str.name) && (repair == str.repair) &&
         (List<House>::operator == (str)));
}

std::ostream& operator <<(std::ostream& osout, Street str) {
  Element<House>* cur = str.get_first()->get_next();

  osout << "Street " << str.name << " Houses num: " << str.get_num()
        << " Repair: ";
  if (str.repair)
    osout<< "true"<< "\n";
  else
    osout << "false" << "\n";
  while (cur) {
    osout << "     " << cur->get_p();
    cur = cur->get_next();
  }

  return osout;
}
