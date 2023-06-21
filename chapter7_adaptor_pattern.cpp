#include <iostream>

using namespace std;

class Duck
{
public:
	virtual void fly() = 0;
	virtual void quack() = 0;
};

class Turkey
{
public:
	virtual void fly() = 0;
	virtual void gobble() = 0;
};

class MallardDuck : public Duck
{
public:
	void fly()
	{
		cout << "flying long distance\n";
	}
	void quack()
	{
		cout << "quacking\n";
	}
};

class WildTurkey : public Turkey
{
public:
	void fly()
	{
		cout << "flying short distance\n";
	}
	void gobble()
	{
		cout << "gobbling\n";
	}
};

class TurkeyAdaptor : public Duck
{
private:
	Turkey* t;
public:
	TurkeyAdaptor(Turkey* tt) : t(tt)
	{}
	void fly()
	{
		for(int i = 0; i < 5; i++)
			t->fly();
	}
	void quack()
	{
		t->gobble();
	}
};

static void testFunc(Duck* d)
{
	d->fly();
	d->quack();
}

int main(int argc, char const *argv[])
{
	MallardDuck* md = new MallardDuck();
	WildTurkey* wt = new WildTurkey();
	TurkeyAdaptor* adap = new TurkeyAdaptor(wt);

	cout << "Turkey says : \n";
	wt->fly();
	wt->gobble();

	cout << "Duck says : \n";
	testFunc(md);

	cout << "TurkeyAdaptor says : \n";
	testFunc(adap);

	return 0;
}