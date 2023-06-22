#include <iostream>

using namespace std;

class CaffeineBeverage
{
public:
	void prepare()
	{
		boilWater();
		brew();
		pourInCup();
		if(customerWantsCondiment())
			addCondiments(); 
	}

	virtual void brew() = 0;
	virtual void addCondiments() = 0; 

	void boilWater()
	{
		cout << "Boiling water\n";
	}

	void pourInCup()
	{
		cout << "Pouring in cup\n";
	}

	virtual bool customerWantsCondiment()
	{
		char ans;
		cout << "Would you like to add condiments?(y/n)\n";
		cin >> ans;
		return ans == 'y';
	}
};

class Tea : public CaffeineBeverage
{
public:
	void brew()
	{
		cout << "Steeping the tea\n";
	}

	void addCondiments()
	{
		cout << "Adding lemon\n";
	}

	bool customerWantsCondiment()
	{
		return true;
	}
};

class Coffee : public CaffeineBeverage
{
public:
	void brew()
	{
		cout << "Dripping coffee through filter\n";
	}

	void addCondiments()
	{
		cout << "Adding sugar and milk\n";
	}
};

int main(int argc, char const *argv[])
{
	CaffeineBeverage* bev;
	Tea tea;
	Coffee coffee;
	bev = &tea;
	cout << "Beverage 1 : \n";
	bev->prepare();

	bev = &coffee;
	cout << "Beverage 2 : \n";
	bev->prepare();
	return 0;
}