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

class NYCheesePizza : public Pizza
{
public:
	NYCheesePizza() {}
	~NYCheesePizza() {}
	void prepare()
	{
		std::cout << "NY Cheese Pizza prepare\n";
	}

	void box()
	{
		std::cout << "NY Cheese Pizza boxed\n";
	}
};

class NYPeperoniPizza : public Pizza
{
public:
	NYPeperoniPizza() {}
	~NYPeperoniPizza() {}
	void prepare()
	{
		std::cout << "NY Peperoni Pizza prepare\n";
	}

	void box()
	{
		std::cout << "NY Peperoni Pizza boxed\n";
	}	
};

class CHCheesePizza : public Pizza
{
public:
	CHCheesePizza() {}
	~CHCheesePizza() {}
	void prepare()
	{
		std::cout << "CH Cheese Pizza prepare\n";
	}

	void box()
	{
		std::cout << "CH Cheese Pizza boxed\n";
	}
};

class CHPeperoniPizza : public Pizza
{
public:
	CHPeperoniPizza() {}
	~CHPeperoniPizza() {}
	void prepare()
	{
		std::cout << "CH Peperoni Pizza prepare\n";
	}

	void box()
	{
		std::cout << "CH Peperoni Pizza boxed\n";
	}	
};

class PizzaStore
{
public:
	PizzaStore() {}

	~PizzaStore() {}

	virtual Pizza* createPizza(std::string) = 0;

	void orderPizza(std::string type)
	{
		Pizza* pizza = createPizza(type);
		pizza->prepare();
		pizza->box();
	}
};

class NYPizzaStore : public PizzaStore
{
public:
	NYPizzaStore() {}
	~NYPizzaStore() {}
	Pizza* createPizza(std::string type)
	{
		Pizza* pizza;
		if(type == "Cheese")
			pizza = new NYCheesePizza();
		else if (type == "Peperoni")
			pizza = new NYPeperoniPizza();
		return pizza;
	}
};

class CHPizzaStore : public PizzaStore
{
public:
	CHPizzaStore() {}
	~CHPizzaStore() {}
	Pizza* createPizza(std::string type)
	{
		Pizza* pizza;
		if(type == "Cheese")
			pizza = new CHCheesePizza();
		else if (type == "Peperoni")
			pizza = new CHPeperoniPizza();
		return pizza;
	}
};

int main(int argc, char const *argv[])
{
	PizzaStore* ny_store = new NYPizzaStore();
	ny_store->orderPizza("Cheese");

	PizzaStore* ch_store = new CHPizzaStore();
	ch_store->orderPizza("Peperoni");
	return 0;
}