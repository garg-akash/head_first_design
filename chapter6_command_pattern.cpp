#include <iostream>

class Light
{
public:
	void on()
	{
		std::cout << "Light turned on\n";
	}
};

class command
{
public:
	command(){}
	virtual void execute() = 0;	
};

class LightOn : public command
{
	Light* l;
public:
	LightOn(Light* lt)
	{
		l = lt;
	}
	void execute()
	{
		l->on();
	}	
};

class remoteControl
{
	command* c;
public:
	remoteControl(){}
	void setCommand(command* cd)
	{
		c = cd;
	}
	void press()
	{
		c->execute();
	}	
};

int main(int argc, char const *argv[])
{
	remoteControl* rc = new remoteControl();
	Light* light = new Light();
	LightOn* lon = new LightOn(light);
	rc->setCommand(lon);
	rc->press();
	return 0;
}