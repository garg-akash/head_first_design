#include <iostream>
#include <string>

using namespace std;

template <typename T>

class Iterator
{
public:
	virtual bool hasNext() = 0;
	virtual T next() = 0;
};

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

class DinnerMenuIterator : public Iterator
{
	MenuItem* items;
	int position{0};
public:
	DinnerMenuIterator(MenuItem* items) : items(items)
	{}

	bool hasNext()
	{
		if(position >= items->size() || items[position] == NULL)
			return false;
		else
			return true;
	}

	MenuItem next()
	{
		return items[position++];
	}
};

class DinnerMenu
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

	DinnerMenuIterator* createIterator()
	{
		return new DinnerMenuIterator(menuItems);
	}
};

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

void printMenu(DinnerMenu* dmenu)
{
	DinnerMenuIterator* diter = dmenu->createIterator();
	cout << "Printing Dinner Menu : \n";
	printMenu(diter);
}

int main(int argc, char const *argv[])
{
	DinnerMenu* dmenu = new DinnerMenu;
	printMenu(dmenu);

	return 0;
}