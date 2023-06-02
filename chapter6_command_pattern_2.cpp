#include <iostream>

class Light
{
public:
	void on()
	{
		std::cout << "Light turned on\n";
	}
	void off()
	{
		std::cout << "Light turned off\n";
	}
};

//**************************************/
class Garage
{
public:
	void up()
	{
		std::cout << "Garage door up\n";
	}
	void down()
	{
		std::cout << "Garage door down\n";
	}
};

/**************************************/
class command
{
public:
	command(){}
	virtual void execute() = 0;	
	virtual void undo() = 0;
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
	void undo()
	{
		l->off();
	}	
};

class LightOff : public command
{
	Light* l;
public:
	LightOff(Light* lt)
	{
		l = lt;
	}
	void execute()
	{
		l->off();
	}
	void undo()
	{
		l->on();
	}	
};

/*************************************/
class GarageUp : public command
{
	Garage* g;
public:
	GarageUp(Garage* g)
	{
		this->g = g;
	}
	void execute()
	{
		g->up();
	}	
	void undo()
	{
		g->down();
	}
};

class GarageDown : public command
{
	Garage* g;
public:
	GarageDown(Garage* g)
	{
		this->g = g;
	}
	void execute()
	{
		g->down();
	}	
	void undo()
	{
		g->up();
	}
};

/**********************************/

class remoteControl
{
	command** con;
	command** coff;
	command* lastCommand;
public:
	remoteControl()
	{
		con = new command*[4];
		coff = new command*[4];
	}
	~remoteControl()
	{
		delete [] con;
		delete [] coff;
	}
	void setCommand(int slot, command* c_on, command* c_off)
	{
		con[slot] = c_on;
		coff[slot] = c_off;
	}
	void onButtonPress(int slot)
	{
		con[slot]->execute();
		lastCommand = con[slot];
	}
	void offButtonPress(int slot)
	{
		coff[slot]->execute();
		lastCommand = coff[slot];
	}	
	void undoButtonPresses()
	{
		lastCommand->undo();
	}
};

int main(int argc, char const *argv[])
{
	remoteControl* rc = new remoteControl();
	Light* light = new Light();
	LightOn* lon = new LightOn(light);
	LightOff* loff = new LightOff(light);

	Garage* garage = new Garage();
	GarageUp* gup = new GarageUp(garage);
	GarageDown* gdown = new GarageDown(garage);
	
	rc->setCommand(0,lon,loff);
	rc->setCommand(1,gup,gdown);

	rc->onButtonPress(0);
	rc->offButtonPress(0);
	rc->undoButtonPresses();

	rc->onButtonPress(1);
	rc->offButtonPress(1);
	return 0;
}