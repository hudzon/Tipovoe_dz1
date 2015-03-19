class element
{
	void *pp;
	element *next;
public:
	element(void *, element *);
	~element();

	element *getnext();
	void setnext(element*);
	void *getp();
};

///////////////////////////////////////////////////

class list
{
	element *first;
	element *cur;
public:
	list(element*);

	void add(int, void *);
	void del(void *);
	element *getcur();
	void setcur(element *);
};