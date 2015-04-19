// Copyright 2015 <Sergey Gudz>

#include "./main.h"

House::House() {
  number = 0;
  level = 0;
  inhabitant = 0;
  repair = 0;
}

House::House(const House& h) {
  number = h.number;
  level = h.level;
  inhabitant = h.inhabitant;
  repair = h.repair;
}

House::House(int number, int level, int inhabitant, bool repair) {
  this->number = number;
  this->level = level;
  this->inhabitant = inhabitant;
  this->repair = repair;
}

House::House(int number, int level) {
  this->number = number;
  this->level = level;
  inhabitant = 0;
  repair = false;
}

House::~House() {
}

void House::change_all_house(int number, int inhabitant, bool repair) {
  this->number = number;
  this->inhabitant = inhabitant;
  this->repair = repair;
}

void House::print() {
  std::cout << "Home " << number << " ,"
  << inhabitant << " inhabitants, repair - " << repair << std::endl;
}

int House::get_inhabitant() const {
  return inhabitant;
}

void House::set_inhabitant(int inhabitant) {
  this->inhabitant = inhabitant;
}

int House::get_num()const {
  return number;
}

void House::set_num(int number) {
  this->number = number;
}

int House::get_level()const {
  return level;
}

void House::set_level(int level) {
  this->level = level;
}

bool House::get_repair()const {
  return repair;
}

void House::set_repair(bool repair) {
  this->repair = repair;
}

std::ostream& operator <<(std::ostream& osout, House h) {
  osout << "Home " << h.number << ", " << h.level << " levels, "
    << h.inhabitant << " inhabitants, repair - ";
  if (h.repair)
    osout << "true" << std::endl;
  else
  osout << "false" << std::endl;

  return osout;
}

const House& House::operator =(const House& h) {
  if (this != &h) {
    number = h.number;
    level = h.level;
    inhabitant = h.inhabitant;
    repair = h.repair;
  }

  return *this;
}

bool House::operator ==(const House& h) const {
  return ((number == h.number) &&
    (level == h.level) &&
    (inhabitant == h.inhabitant) &&
    (repair == h.repair));
}
