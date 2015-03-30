template<class T>
class Element
{
	T pp;
	Element *next;
public:
	Element(T, Element *);
	~Element();

	Element *getnext();
	void setnext(Element*);
	T getp();
};
