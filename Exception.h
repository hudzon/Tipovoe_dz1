// Copyright 2015 <Sergey Gudz>

#pragma once
#include <string>

class ExNotFound : public std::exception {
 public:
  explicit ExNotFound(const int i) {
    msg = "Not found house number ";
    msg += std::to_string(i);
  }

  const char* what() const throw() {
    return msg.c_str();
  }

 private:
  std::string msg;
};

class ExAlreadyHave : public std::exception {
 public:
  explicit ExAlreadyHave(House h) {
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

  const char* what() const throw() {
    return msg.c_str();
  }

 private:
  std::string msg;
};

class ExNotHave : public std::exception {
 public:
  explicit ExNotHave(House h) {
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

  const char* what() const throw() {
    return msg.c_str();
  }

 private:
  std::string msg;
};

class ExNotHaveTwo : public std::exception {
 public:
  explicit ExNotHaveTwo(const int i) {
    msg = "This street have less house than ";
    msg += std::to_string(i);
  }

  const char* what() const throw() {
    return msg.c_str();
  }

 private:
  std::string msg;
};
