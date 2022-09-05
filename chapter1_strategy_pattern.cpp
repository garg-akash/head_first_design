#include <iostream>

using namespace std;

class FlyBehaviour
{
public:
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehaviour
{
	void fly()
	{
		cout << "implements fly\n";
	}
};
class FlyRocketPowered : public FlyBehaviour
{
	void fly()
	{
		cout << "implements fly with rocket powered\n";
	}
};

class QuackBehaviour
{
public:
	virtual void quack() = 0;	
};

class Quack : public QuackBehaviour
{
	void quack()
	{
		cout << "implements quack\n";
	}
};

class Squeak : public QuackBehaviour
{
	void quack()
	{
		cout << "implements squeak\n";
	}
};

class MuteQuack : public QuackBehaviour
{
	void quack()
	{
		cout << "implements mute quack\n";
	}
};

class Duck
{
public:
	FlyBehaviour *flyBehaviour;
	QuackBehaviour *quackBehaviour;
	void performFly()
	{
		flyBehaviour->fly();
	}
	void performQuack()
	{
		quackBehaviour->quack();
	}
	void setFlyBehaviour(FlyBehaviour *fb) //setter function
	{
		flyBehaviour = fb;
	}
	virtual void display() = 0;
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
	{
		quackBehaviour = new Quack();
		flyBehaviour = new FlyWithWings();
	}
	void display()
	{
		cout << "I'm Mallard Duck \n";
	}
};

int main(int argc, char const *argv[])
{
	Duck *mallard = new MallardDuck();
	// Duck *mallard;
	// MallardDuck md;
	// mallard = &md;
	mallard->performQuack();
	mallard->performFly();
	mallard->setFlyBehaviour(new FlyRocketPowered); //dynamically setting behaviour
	mallard->performFly();
	mallard->display();
	return 0;
}