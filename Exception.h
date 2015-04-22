// Copyright 2015 <Sergey Gudz>

#pragma once

class ExNotFound : public std::exception {
 public:
  explicit ExNotFound(const char* msg) {
    this->msg = msg;
  }

  const char* what() const throw() {
    return msg;
  }

 private:
  const char* msg;
};

class ExAlreadyHave : public std::exception {
 public:
  explicit ExAlreadyHave(const char* msg) {
    this->msg = msg;
  }

  const char* what() const throw() {
    return msg;
  }

 private:
  const char* msg;
};

class ExNotHave : public std::exception {
 public:
  explicit ExNotHave(const char* msg) {
    this->msg = msg;
  }

  const char* what() const throw() {
    return msg;
  }

 private:
  const char* msg;
};
