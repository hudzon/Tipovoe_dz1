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
List<T>::~List() {
  while (first) {
    cur = first->get_next();
    delete first;
    first = cur;
  }
}

template<class T>
int List<T>::get_houses_num() {
  return houses_num;
}

template<class T>
void List<T>::add(T pp) {
  cur = first;
  while (cur->get_next())
    cur = cur->get_next();

  cur->set_next(new Element<T>(pp, 0));
  ++houses_num;
}

template<class T>
void List<T>::del(T el) {
  Element<T> *buf;
  cur = first;

  while (!(cur->get_next()->get_p() == el)) {
    cur = cur->get_next();
  }
  buf = cur->get_next();
  cur->set_next(cur->get_next()->get_next());

  --houses_num;

  delete buf;
}

template<class T>
const List<T>& List<T>::operator =(const List<T>& list) {
  if (this != &list) {
    while (first) {
      cur = first->get_next();
      delete first;
      first = cur;
    }
    first = new Element<T>();
    Element<T>* curr = list.first->get_next();
    while (curr) {
      add(curr->get_p());
      curr = curr->get_next();
    }
  }

  return *this;
}

