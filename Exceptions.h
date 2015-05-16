// Copyright 2015 <Sergey Gudz>

#pragma once
#include <string>

class ExNotFound : public std::exception {
 public:
  explicit ExNotFound(const House& h);

  const char* what() const throw();

 private:
  std::string msg;
};

class ExAlreadyHave : public std::exception {
 public:
  explicit ExAlreadyHave(const House& h);

  const char* what() const throw();

 private:
  std::string msg;
};

class ExNotHave : public std::exception {
 public:
  explicit ExNotHave(const House& h);

  const char* what() const throw();

 private:
  std::string msg;
};

class ExNotHaveTwo : public std::exception {
 public:
  explicit ExNotHaveTwo(int i);

  const char* what() const throw();

 private:
  std::string msg;
};

class ExListFindI : public std::exception {
 public:
  explicit ExListFindI(int i);

  const char* what() const throw();

 private:
  std::string msg;
};
