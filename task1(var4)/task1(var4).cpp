#include <iostream>

using namespace std;

class Base
{
private:
	int A;
public:
	Base() : A(0)
	{
		cout << "Base const." << endl;
	}

	virtual ~Base()
	{
		cout << "Base dest." << endl;
	}
};

class D1 : public Base
{
public:
	int d1;
public:
	D1() : d1(0)
	{
		cout << "D1 const." << endl;
	}

	~D1()
	{
		cout << "D1 dest." << endl;
	}
};

class D2 : public Base, public D1
{
private:
	int d2;
public:
	D2() : d2(0)
	{
		cout << "D2 const." << endl;
	}
	~D2()
	{
		cout << "D2 dest." << endl;
	}
};

class D3 : public Base, D1
{
private:
	int d3;
public:
	D3() : d3(0)
	{
		cout << "D3 const." << endl;
	}

	~D3()
	{
		cout << "D3 dest." << endl;
	}
};

class D4 : public D2, public D3
{
private:
	int d4;
public:
	D4() : d4(0)
	{
		cout << "D4 const." << endl;
	}

	~D4()
	{
		cout << "D4 dest." << endl;
	}
};

//virtual
class D1V : virtual public Base
{
public:
	int d1;
public:
	D1V() : d1(0)
	{
		cout << "D1 const." << endl;
	}

	~D1V()
	{
		cout << "D1 dest." << endl;
	}
};

class D2V : virtual public Base, virtual public D1V
{
private:
	int d2;
public:
	D2V() : d2(0)
	{
		cout << "D2 const." << endl;
	}
	~D2V()
	{
		cout << "D2 dest." << endl;
	}
};

class D3V : virtual public Base, virtual public D1V
{
private:
	int d3;
public:
	D3V() : d3(0)
	{
		cout << "D3 const." << endl;
	}

	~D3V()
	{
		cout << "D3 dest." << endl;
	}
};

class D4V : public D2V, public D3V
{
private:
	int d4;
public:
	D4V() : d4(0)
	{
		cout << "D4 const." << endl;
	}

	~D4V()
	{
		cout << "D4 dest." << endl;
	}
};

int main()
{
	cout << "Without virtual:\n";
	cout << "sizeof(Base)" << sizeof(Base) << endl;
	cout << "sizeof(D1)" << sizeof(D1) << endl;
	cout << "sizeof(D2)" << sizeof(D2) << endl;
	cout << "sizeof(D3)" << sizeof(D3) << endl;
	cout << "sizeof(D4)" << sizeof(D4) << endl;

	cout << "\n--------------------------------------------------\n";
	cout << "With virtual:\n";
	cout << "sizeof(Base virtual)" << sizeof(Base) << endl;
	cout << "sizeof(D1 virtual)" << sizeof(D1V) << endl;
	cout << "sizeof(D2 virtual)" << sizeof(D2V) << endl;
	cout << "sizeof(D3 virtual)" << sizeof(D3V) << endl;
	cout << "sizeof(D4 virtual)" << sizeof(D4V) << endl;
}