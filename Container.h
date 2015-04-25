// Copyright 2015 <Sergey Gudz>

#pragma once

template<class T>
class Element {
  T pp;
  Element* next;
 public:
  Element();
  Element(T, Element*);
  ~Element();

  Element* get_next() const;
  void set_next(Element* a);
  T& get_p();
};

/////////////////////////////////

template<class T>
class List {
 protected:
  Element<T>* first;
  Element<T>* cur;
  int houses_num;
 public:
  List();
  explicit List(Element<T>*);
  ~List();

  void add(T);
  void del(T);

  int get_houses_num();

  const List<T>& operator =(const List<T>&);
};
