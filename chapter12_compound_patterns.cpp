#include <iostream>

using namespace std;

// Duck classes
class Quackable
{
public:
	virtual void quack() {}
};

class MallardDuck : public Quackable
{
public:
	void quack()
	{
		cout << "Qack\n";
	}
};

class DuckCall : public Quackable
{
public:
	void quack()
	{
		cout << "Kwak\n";
	}
};

class RubberDuck : public Quackable
{
public:
	void quack()
	{	
		cout << "Squeak\n";
	}
};

// Decorator to count #quacks
class QuackCounter : public Quackable
{
	Quackable* d;
	static int numQuacks;
public:
	QuackCounter(Quackable* duck)
	{
		d = duck;
	}
	void quack()
	{
		d->quack();
		numQuacks++;
	}	
	static int getQuackCount()
	{
		return numQuacks;
	}
};
int QuackCounter::numQuacks = 0;

// Goose classes
class Goose
{
public:
	void honk()
	{
		cout << "Honk\n";
	}
};

// Adapter defined 
class GooseAdapter : public Quackable
{
	Goose* g;
public:
	GooseAdapter(Goose* goose)
	{
		g = goose;
	}
	void quack()
	{
		g->honk();
	}
};

class AbstractDuckFactory : public Quackable
{
public:
	virtual Quackable* createMallardDuck() = 0;
	virtual Quackable* createDuckCall() = 0;
	virtual Quackable* createRubberDuck() = 0;
};

class CountingDuckFactory : public AbstractDuckFactory
{
public:
	Quackable* createMallardDuck()
	{
		return new QuackCounter(new MallardDuck());
	}
	Quackable* createDuckCall()
	{
		return new QuackCounter(new DuckCall());
	}
	Quackable* createRubberDuck()
	{
		return new QuackCounter(new RubberDuck());
	}
	
};

class DuckSimulator
{
	void simulate(Quackable* q)
	{
		q->quack();
	}
public:
	void simulate(AbstractDuckFactory* factory)
	{
		cout << "Duck Simulator: with factory & decorator\n";
		Quackable* mallardDuck = factory->createMallardDuck();
		Quackable* duckCall = factory->createDuckCall();
		Quackable* rubberDuck = factory->createRubberDuck();
		Quackable* gooseDuck = new GooseAdapter(new Goose());

		simulate(mallardDuck);
		simulate(duckCall);
		simulate(rubberDuck);
		simulate(gooseDuck);

		cout << "Number of quacks : " << QuackCounter::getQuackCount() << "\n";
	}
};

int main(int argc, char const *argv[])
{
	DuckSimulator* sim = new DuckSimulator();
	AbstractDuckFactory* fact = new CountingDuckFactory();
	sim->simulate(fact);
	return 0;
}