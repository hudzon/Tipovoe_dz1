// Copyright 2015 <Sergey Gudz>

#include "./main.h"

Street::Street() : List<House>() {
  number = 0;
  houses_num = 0;
  repair = false;
}

Street::Street(int number, bool repair) :List<House>() {
  this->number = number;
  houses_num = 0;
  this->repair = repair;
}

Street::Street(const Street& str) :List<House>() {
  number = str.number;
  houses_num = 0;
  repair = str.repair;

  Element<House>* curr = str.first->get_next();
  while (curr) {
    add(curr->get_p());
    curr = curr->get_next();
  }
}

Street::~Street() {
  if (first !=cur)
    delete cur;
  delete first;
}

void Street::change_all_street(int number, bool repair) {
  this->number = number;
  this->repair = repair;
}

int Street::get_number() const {
  return number;
}

void Street::set_number(int number) {
  this->number = number;
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

House& Street::search_house(int i) {
  if (!has(i))
    throw ExNotFound("Not found");
  return cur->get_p();
}

void Street::add(const House& h) {
  if (has(h.get_num()))
    throw ExAlreadyHave("Already have");

  List<House>::add(h);
  ++houses_num;
}

void Street::del(const House& h) {
  if (!has(h.get_num()))
    throw ExNotHave("Not have");

  List<House>::del(h);
  --houses_num;
}

void Street::del_in_order(int i) {
  if (i > houses_num)
    throw ExNotHave("Not have");

  cur = first;

  for (int j=0; j < i-1; ++j)
    cur = cur->get_next();
  cur->set_next(cur->get_next()->get_next());

  --houses_num;
}

bool Street::has(int i) {
  cur = first;

  while ((cur) && (cur->get_p().get_num() != i)) {
    cur = cur->get_next();
  }
  if (cur) {
    if (cur->get_p().get_num() == i)
      return true;
  }

  return false;
}

const Street& Street::operator =(const Street& str) {
  if (this != &str) {
    number = str.number;
    houses_num = 0;
    repair = str.repair;

    Element<House>* curr = str.first->get_next();
    while (curr) {
      add(curr->get_p());
      curr = curr->get_next();
    }
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

  return ((number == str.number) &&
  (houses_num == str.houses_num) &&
  (repair == str.repair));
}

std::ostream& operator <<(std::ostream& osout, Street str) {
  str.cur = str.first->get_next();

  osout << "Street " << str.number << " Houses num: " << str.houses_num
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
