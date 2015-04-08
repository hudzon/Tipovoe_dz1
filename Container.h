// Copyright 2015 <Sergey Gudz>

#pragma once

template<class T>
class Element {
  T pp;
  Element *next;
 public:
  Element();
  Element(T, Element *);
  ~Element();

  Element *getnext();
  void setnext(Element* a);
  T & getp();
};

/////////////////////////////////

template<class T>
class List {
 protected:
  Element<T> *first;
  Element<T> *cur;
 public:
  List();
  explicit List(Element<T> *);

  void add(T);
  void del(T);
};
