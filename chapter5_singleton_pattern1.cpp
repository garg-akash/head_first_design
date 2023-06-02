#include <iostream>

class Singleton
{
private:
	static Singleton* ins;
	Singleton()
	{
		std::cout << "Constructor called\n";
	}
	// ~Singleton();
public:
	static Singleton* getInstance()
	{
		if(ins == NULL)
			ins = new Singleton();
		return ins;
	} 
};

class B : public Singleton
{
public:
	B();
	~B();
};

Singleton* Singleton::ins = NULL; // important

int main(int argc, char const *argv[])
{
	Singleton* obj = Singleton::getInstance();
	std::cout << "Address of obj: " << obj << std::endl;
	Singleton* obj2 = Singleton::getInstance();
	std::cout << "Address of obj2: " << obj2 << std::endl;
	// Singleton* obj3 = new Singleton(); // error because constructor is private
	return 0;
}