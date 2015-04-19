// Copyright 2015 <Sergey Gudz>

#pragma once

template<class T>
Element<T>::Element() {
  pp = T();
  next = 0;
}

template<class T>
Element<T>::Element(T pp, Element *next) {
  this->pp = pp;
  this->next = next;
}

template<class T>
Element<T>::~Element() {}

template<class T>
Element<T> * Element<T>::get_next() const {
  return next;
}

template<class T>
void Element<T>::set_next(Element* next) {
  this->next = next;
}

template<class T>
T& Element<T>::get_p() {
  return pp;
}

////////////////////////////////////

template<class T>
List<T>::List() {
  first = new Element<T>;
  cur = first;
}

template<class T>
List<T>::List(Element<T>* first) {
  this->first = first;
  cur = first;
}

template<class T>
void List<T>::add(T pp) {
  cur = first;

  cur->set_next(new Element<T>(pp, cur->get_next()));
}

template<class T>
void List<T>::del(T el) {
  cur = first;

  while (!(cur->get_next()->get_p() == el)) {
    cur = cur->get_next();
  }
  cur->set_next(cur->get_next()->get_next());
}
