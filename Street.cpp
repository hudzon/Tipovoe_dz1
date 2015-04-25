// Copyright 2015 <Sergey Gudz>

#include <string>
#include "./main.h"

Street::Street() : List<House>() {
  name = "Ordinary Street";
  houses_num = 0;
  repair = false;
}

Street::Street(std::string name, bool repair) :List<House>() {
  this->name = name;
  houses_num = 0;
  this->repair = repair;
}

Street::Street(const Street& str) :List<House>() {
  name = str.name;
  houses_num = 0;
  repair = str.repair;

  Element<House>* curr = str.first->get_next();
  while (curr) {
    add(curr->get_p());
    curr = curr->get_next();
  }
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
  cur = first->get_next();

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

House& Street::search_house(int i)const {
  if (!has(i))
    throw ExNotFound(i);

  Element<House>* curr = first;

  while ((curr) && (curr->get_p().get_num() != i))
    curr = curr->get_next();

  return curr->get_p();
}

void Street::add(const House& h) {
  if (has(h.get_num()))
    throw ExAlreadyHave(h);

  List<House>::add(h);
}

void Street::del(const House& h) {
  if (!has(h.get_num()))
    throw ExNotHave(h);

  List<House>::del(h);
}

void Street::del_in_order(int i) {
  if (i > houses_num)
    throw ExNotHaveTwo(i);


  cur = first;

  for (int j=0; j < i; ++j)
    cur = cur->get_next();

  List<House>::del(cur->get_p());
}

bool Street::has(int i)const {
  Element<House>* curr = first;

  while ((curr) && (curr->get_p().get_num() != i)) {
    curr = curr->get_next();
  }
  if (curr) {
    if (curr->get_p().get_num() == i)
      return true;
  }

  return false;
}

const Street& Street::operator =(const Street& str) {
  if (this != &str) {
    name = str.name;
    houses_num = 0;
    repair = str.repair;

    List<House>::operator =(str);
  }

  return *this;
}

bool Street::operator ==(const Street& str) const {
  Element<House>* curr = str.first;
  Element<House>* curr2 = first;

  while (curr) {
    if (!(curr->get_p() == curr2->get_p()))
      return false;

    curr = curr->get_next();
    curr2 = curr2->get_next();
  }

  return ((name == str.name) &&
  (houses_num == str.houses_num) &&
  (repair == str.repair));
}

std::ostream& operator <<(std::ostream& osout, Street str) {
  str.cur = str.first->get_next();

  osout << "Street " << str.name << " Houses num: " << str.houses_num
        << " Repair: ";
  if (str.repair)
    osout<< "true"<< std::endl;
  else
    osout << "false" << std::endl;
  while (str.cur) {
    osout << "     " << str.cur->get_p();
    str.cur = str.cur->get_next();
  }

  return osout;
}
