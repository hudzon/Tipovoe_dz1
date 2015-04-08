// Copyright 2015 <Sergey Gudz>

#include "main.h"

House::House() {
  number = 0;
  level = 0;
  inhabitant = 0;
  repair = 0;
}

House::House(const House &h) {
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

House::~House() {}

void House::changeallhouse(int number, int inhabitant, bool repair) {
  this->number = number;
  this->inhabitant = inhabitant;
  this->repair = repair;
}

void House::print() {
  std::cout << "Home " << number << " ,"
  << inhabitant << " inhabitants, repair - " << repair << std::endl;
}

const int House::getinhabitant() {
  return inhabitant;
}

void House::setinhabitant(int inhabitant) {
  this->inhabitant = inhabitant;
}

const int House::getnum()const {
  return number;
}

void House::setnum(int number) {
  this->number = number;
}

std::ostream & operator <<(std::ostream & osout, House h) {
  osout << "Home " << h.number << ", " << h.level << " levels, "
    << h.inhabitant << " inhabitants, repair - ";
  if (h.repair)
    osout << "true" << std::endl;
  else
  osout << "false" << std::endl;

  return osout;
}

House & House::operator =(const House & h) {
  if (!(*this == h)) {
    number = h.number;
    level = h.level;
    inhabitant = h.inhabitant;
    repair = h.repair;
  }

  return *this;
}

bool House::operator ==(const House & h) {
  if ((number == h.number) &&
    (level == h.level) &&
    (inhabitant == h.inhabitant) &&
    (repair == h.repair))
    return true;
  else
  return false;
}
