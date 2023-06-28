#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*iterator base class*/
template <typename T>
class Iterator
{
public:
	virtual bool hasNext() = 0;
	virtual T next() = 0;
};

/*Menu item base class*/
class MenuItem
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
};

/*Menu base class*/
class Menu
{
public:
	virtual void addItem(string,string, bool, double) = 0;
	virtual Iterator<MenuItem>* createIterator() = 0;
};

/*Base classes definition over*/

template<typename T>
class DinnerMenuIterator : public Iterator<T>
{
	MenuItem* items;
	int len;
	int position{0};
public:
	DinnerMenuIterator(MenuItem* items, int len) : items(items), len(len)
	{}

	bool hasNext()
	{
		// if(position >= len || items[position] == NULL)
		if(position >= len)
			return false;
		else
			return true;
	}

	MenuItem next()
	{
		return items[position++];
	}
};

template<typename T>
class PancakeMenuIterator : public Iterator<T>
{
	vector<MenuItem> items;
	int len;
	int position{0};
public:
	PancakeMenuIterator(vector<MenuItem>& it, int len)
	{
		this->len = len;
		// items.resize(it.size());
		items = it;
	}

	bool hasNext()
	{
		if(position >= len)
			return false;
		else
			return true;
	}

	MenuItem next()
	{
		return (items[position++]);
	}
};

/**************iterator definitions over****************/

class DinnerMenu : public Menu
{
	const static int max_size{10};
	int numItems{0};
	MenuItem* menuItems;

public:
	DinnerMenu()
	{
		menuItems = new MenuItem[max_size];
		addItem("Burger","lele",true,2.99);	
		addItem("Hot Dog","lele",false,3.99);
	}

	void addItem(string n, string d, bool v, double p)
	{
		MenuItem* m = new MenuItem(n,d,v,p);
		if(numItems >= max_size)
			throw("Max size exceeded\n");
		else
		{
			menuItems[numItems++] = *m;
		} 
	}

	// void getMenu(MenuItem* mi, int& sz)
	// {
	// 	mi = menuItems;
	// 	sz = numItems;	
	// }

	DinnerMenuIterator<MenuItem>* createIterator()
	{
		DinnerMenuIterator<MenuItem>* diter  = new DinnerMenuIterator<MenuItem>(menuItems,numItems);
		return diter; 
	}
};

/***************Dinner menu definition over**************/

class PancakeMenu : public Menu
{
	const static int max_size{10};
	int numItems{0};
	vector<MenuItem> menuItems;

public:
	PancakeMenu()
	{
		menuItems.resize(max_size);		
		addItem("Berries PC","lele",true,8.99);	
		addItem("Egg PC","lele",false,9.99);
	}

	void addItem(string n, string d, bool v, double p)
	{
		MenuItem* m = new MenuItem(n,d,v,p);
		if(numItems >= max_size)
			throw("Max size exceeded\n");
		else
			menuItems[numItems++] = *m;
	}

	PancakeMenuIterator<MenuItem>* createIterator()
	{
		PancakeMenuIterator<MenuItem>* piter  = new PancakeMenuIterator<MenuItem>(menuItems,numItems);
		return piter; 
	}
};

/***************Pancake menu definition over**************/

class Waitress
{
	Menu* dmenu;
	Menu* pmenu;

	void printMenu(Iterator<MenuItem>* iter)
	{
		while(iter->hasNext())
		{
			MenuItem item = iter->next();
			cout << item.getName() << "\n";
			cout << item.getDescription() << "\n";
			cout << item.isVeg() << "\n";
			cout << item.getPrice() << "\n";
			cout << "----\n";
		}
	}

public:
	Waitress(Menu* dm, Menu* pm) : dmenu(dm), pmenu(pm)
	{}
	void printMenu()
	{
		Iterator<MenuItem>* diter = dmenu->createIterator();
		cout << "Printing Dinner Menu : \n";
		printMenu(diter);

		Iterator<MenuItem>* piter = pmenu->createIterator();
		cout << "Printing Pancake Menu : \n";
		printMenu(piter);
	}
};

/***************Waitress definition over**************/

int main(int argc, char const *argv[])
{
	Menu* dmenu = new DinnerMenu;
	Menu* pmenu = new PancakeMenu;

	Waitress* waitress = new Waitress(dmenu,pmenu);
	waitress->printMenu();

	return 0;
}