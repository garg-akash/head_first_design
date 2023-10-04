#include <iostream>

class Beverage
{
public:
	std::string description;
	Beverage()
	{
		description = "unknown Beverage";
	}
	~Beverage() {}
	virtual std::string getDescription()
	{
		return description;
	}
	virtual double cost() = 0;
	// double cost()
	// {
	// 	return 0;
	// }
};

class CondimentDecorator : public Beverage
{
public:
	virtual std::string getDescription() = 0;
};

class Espresso : public Beverage
{
public:
	Espresso()
	{
		description = "Espresso";
	}
	double cost()
	{
		return 1.99;
	}
};

class HouseBlend : public Beverage
{
public:
	HouseBlend()
	{
		description = "HouseBlend";
	}
	double cost()
	{
		return 0.89;
	}
};

class Mocha : public CondimentDecorator
{
private: Beverage* beverage;
public:
	Mocha(Beverage* b)
	{
		beverage = b;
	}
	~Mocha() {}
	std::string getDescription()
	{
		return beverage->getDescription() + ", Mocha";
	}

	double cost()
	{
		return beverage->cost() + 0.20;
	}
};

class Whip : public CondimentDecorator
{
private: Beverage* beverage;
public:
	Whip(Beverage* b)
	{
		beverage = b;
	}
	~Whip();
	std::string getDescription()
	{
		return beverage->getDescription() + ", Whip";
	}

	double cost()
	{
		return beverage->cost() + 0.40;
	}
};

int main(int argc, char const *argv[])
{
	Beverage* b1 = new Espresso();
	Beverage* b2 = new Mocha(b1);
	std::cout << b2->getDescription() << "\n";
	std::cout << b2->cost() << "\n";  
	return 0;
}