// Copyright 2015 <Sergey Gudz>

#include "./main.h"

ExNotFound::ExNotFound(const House& h) {
  msg = "Not found house number ";
  msg += std::to_string(h.get_num());
  msg += " ,";
  msg += std::to_string(h.get_level());
  msg += " levels, ";
  msg += std::to_string(h.get_inhabitant());
  msg += " inhabitants, repair - ";
  if (h.get_repair())
    msg += "true";
  else
    msg += "false";
}

const char* ExNotFound::what() const throw() {
  return msg.c_str();
}

//////////////////////////////

ExAlreadyHave::ExAlreadyHave(const House& h) {
  msg = "This street already have house number ";
  msg += std::to_string(h.get_num());
  msg += " ,";
  msg += std::to_string(h.get_level());
  msg += " levels, ";
  msg += std::to_string(h.get_inhabitant());
  msg += " inhabitants, repair - ";
  if (h.get_repair())
    msg += "true";
  else
    msg += "false";
}

const char* ExAlreadyHave::what() const throw() {
  return msg.c_str();
}

/////////////////////////////

ExNotHave::ExNotHave(const House& h) {
  msg = "This street not have house number ";
  msg += std::to_string(h.get_num());
  msg += " ,";
  msg += std::to_string(h.get_level());
  msg += " levels, ";
  msg += std::to_string(h.get_inhabitant());
  msg += " inhabitants, repair - ";
  if (h.get_repair())
    msg += "true";
  else
    msg += "false";
}

const char* ExNotHave::what() const throw() {
  return msg.c_str();
}

////////////////////////////

ExNotHaveTwo::ExNotHaveTwo(int i) {
  msg = "This street have less house than ";
  msg += std::to_string(i);
}

const char* ExNotHaveTwo::what() const throw() {
  return msg.c_str();
}
