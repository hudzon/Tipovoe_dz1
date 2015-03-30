#include "Element.h"
#include <iomanip>
template<class T>
class List
{
protected:
	Element<T> *first;
	Element<T> *cur;
public:
	List(Element<T> *);

	void add(T);
	void del(T);
};