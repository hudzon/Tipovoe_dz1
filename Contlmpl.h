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
Element<T> * Element<T>::getnext() {
  return next;
}

template<class T>
void Element<T>::setnext(Element *next) {
  this->next = next;
}

template<class T>
T & Element<T>::getp() {
  return pp;
}

////////////////////////////////////

template<class T>
List<T>::List() {
  first = new Element<T>;
  cur = first;
}

template<class T>
List<T>::List(Element<T> *first) {
  this->first = first;
  cur = first;
}

template<class T>
void List<T>::add(T pp) {
  cur = first;

  cur->setnext(new Element<T>(pp, cur->getnext()));
}

template<class T>
void List<T>::del(T el) {
  cur = first->getnext();

  while (!(cur->getnext()->getp() == el)) {
    cur = cur->getnext();
  }
  cur->setnext(cur->getnext()->getnext());
}
