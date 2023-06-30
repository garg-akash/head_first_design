#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*Menu Component base class*/
class MenuComponent
{
public:
	virtual void add(MenuComponent* menuComp)
	{
		throw std::runtime_error("add() is unsupported");
	}

	virtual void remove(MenuComponent* menuComp)
	{
		throw std::runtime_error("remove() is unsupported");
	}

	virtual MenuComponent* getChild(int i)
	{
		throw std::runtime_error("getChild() is unsupported");
	}

	virtual string getName()
	{
		throw std::runtime_error("getName() is unsupported");
	}

	virtual string getDescription()
	{
		throw std::runtime_error("getDescription() is unsupported");
	}

	virtual double getPrice()
	{
		throw std::runtime_error("getPrice() is unsupported");
	}

	virtual bool isVeg()
	{
		throw std::runtime_error("isVeg() is unsupported");
	}

	virtual void print()
	{
		throw std::runtime_error("print() is unsupported");
	}	
};

/*Menu item (derived) class*/
class MenuItem : public MenuComponent
{
	string name;
	string des;
	bool veg;
	double price;
public:
	MenuItem() 
	{}

	MenuItem(string name, string des, bool veg, double price) : name{name}, des{des}, veg{veg}, price{price}
	{}

	string getName()
	{
		return name;
	}

	string getDescription()
	{
		return des;
	}

	bool isVeg()
	{
		return veg;
	}

	double getPrice()
	{
		return price;
	}

	void print()
	{
		cout << "\n " << getName();
		if(isVeg())
			cout << "(v)";
		cout << " " << getPrice();
		cout << " --" << getDescription() << "\n";
	}
};

/*Menu (derived) class*/
class Menu : public MenuComponent
{
	vector<MenuComponent*>* menuComp;
	string name;
	string description;

public:
	Menu(string nm, string des) : name{nm}, description{des}
	{
		menuComp = new vector<MenuComponent*>();
	}
	
	void add(MenuComponent* mc)
	{
		menuComp->push_back(mc);
	}

	MenuComponent* getChild(int i)
	{
		return (*menuComp)[i];
	}

	string getName()
	{
		return name;
	}

	string getDescription()
	{
		return description;
	}

	void print()
	{
		cout << "\n" << getName();
		cout << ", " << getDescription();
		cout << "\n----------------";
		for(auto it = menuComp->begin(); it != menuComp->end(); it++)
		{
			MenuComponent* mc = *it;
			mc->print();
		}
	}
};

class Waitress
{
	MenuComponent* allMenus;

public:
	Waitress(MenuComponent* menuz) : allMenus(menuz)
	{}
	void printMenu()
	{
		allMenus->print();
	}
};

/***************Waitress definition over**************/

int main(int argc, char const *argv[])
{
	MenuComponent* pancakeMenu = new Menu("Pancake House Menu", "Breakfast");
	MenuComponent* dinerMenu = new Menu("Diner Menu", "Lunch");
	MenuComponent* cafeMenu = new Menu("Cafe Menu", "Dinner");
	MenuComponent* dessertMenu = new Menu("Dessert Menu", "Dessert of course!");

	MenuComponent* allMenus = new Menu("All Menus", "All menus combined");
	allMenus->add(pancakeMenu);
	allMenus->add(dinerMenu);
	allMenus->add(cafeMenu);

	pancakeMenu->add(new MenuItem(
		"Berries PC","lele",true,8.99));

	dinerMenu->add(new MenuItem(
		"Pasta",
		"Spaghetti with Mariana Souce",
		true,
		3.99));

	dinerMenu->add(new MenuItem(
		"Apple Pie",
		"AP topped with ice cream",
		true,
		1.99));

	dinerMenu->add(dessertMenu);

	dessertMenu->add(new MenuItem(
		"Rasgulla",
		"lele",true
		,0.99));

	cafeMenu->add(new MenuItem(
		"Curry",
		"chicken",false
		,5.99));

	Waitress* waitress = new Waitress(allMenus);
	waitress->printMenu();

	return 0;
}