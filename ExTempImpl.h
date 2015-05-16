// Copyright 2015 <Sergey Gudz>

#pragma once

template <class T>
ExListFind<T>::ExListFind(const T& el) {
  std::ostringstream s;
  s << "This container not have element\n" << el << "\n";

  msg += s.str();
}

template <class T>
const char* ExListFind<T>::what() const throw() {
  return msg.c_str();
}

/////////////////////////////

template <class T>
ExListDel<T>::ExListDel(const T& el) {
  std::ostringstream s;
  s <<
    "This container can't del this element, because it not have this element\n"
    << el << "\n";

  msg += s.str();
}

template <class T>
const char* ExListDel<T>::what() const throw() {
  return msg.c_str();
}
