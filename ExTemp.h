// Copyright 2015 <Sergey Gudz>

#pragma once
#include <string>

template <class T>
class ExListFind : public std::exception {
 public:
  explicit ExListFind(const T&);

  const char* what() const throw();

 private:
  std::string msg;
};

template <class T>
class ExListDel : public std::exception {
 public:
  explicit ExListDel(const T&);

  const char* what() const throw();

 private:
  std::string msg;
};
