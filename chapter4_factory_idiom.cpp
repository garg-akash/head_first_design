#include <iostream>

class Pizza
{
public:
	Pizza() {}
	~Pizza() {}
	virtual void prepare() = 0;
	void bake();
	void cut();
	virtual void box() = 0;
};

class CheesePizza : public Pizza
{
public:
	CheesePizza() {}
	~CheesePizza() {}
	void prepare()
	{
		std::cout << "Cheese Pizza prepare\n";
	}

	void box()
	{
		std::cout << "Cheese Pizza boxed\n";
	}
};

class PeperoniPizza : public Pizza
{
public:
	PeperoniPizza() {}
	~PeperoniPizza() {}
	void prepare()
	{
		std::cout << "Peperoni Pizza prepare\n";
	}

	void box()
	{
		std::cout << "Peperoni Pizza boxed\n";
	}	
};

class PizzaFactory
{
public:
	PizzaFactory() {}
	~PizzaFactory() {}
	Pizza* createPizza(std::string type)
	{
		Pizza* pizza;
		if(type == "cheese")
			pizza = new CheesePizza();
		else if (type == "Peperoni")
			pizza = new PeperoniPizza();
		return pizza;
	}
	
};

class PizzaStore
{
	PizzaFactory pf;
public:
	PizzaStore(PizzaFactory pf)
	{
		this->pf = pf;
	}

	~PizzaStore() {}

	void orderPizza(std::string type)
	{
		Pizza* pizza = pf.createPizza(type);
		pizza->prepare();
		pizza->box();
	}
};

int main(int argc, char const *argv[])
{
	PizzaFactory pf;
	// Pizza* p = pf.createPizza("Cheese"); // OK
	// Pizza* p = new Pizza() // Not OK
	PizzaStore ps(pf);
	ps.orderPizza("Peperoni");
	return 0;
}