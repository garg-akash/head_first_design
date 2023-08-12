#include <iostream>

using namespace std;

class Quackable
{
public:
	virtual void quack() = 0;
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

class Goose
{
public:
	void honk()
	{
		cout << "Honk\n";
	}
};

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

class DuckSimulator
{
	void simulate(Quackable* q)
	{
		q->quack();
	}
public:
	void simulate()
	{
		cout << "Duck Simulator:\n";
		Quackable* mallardDuck = new MallardDuck();
		Quackable* duckCall = new DuckCall();
		Quackable* rubberDuck = new RubberDuck();
		Quackable* gooseDuck = new GooseAdapter(new Goose());

		simulate(mallardDuck);
		simulate(duckCall);
		simulate(rubberDuck);
		simulate(gooseDuck);
	}
};

int main(int argc, char const *argv[])
{
	DuckSimulator* sim = new DuckSimulator();
	sim->simulate();
	return 0;
}