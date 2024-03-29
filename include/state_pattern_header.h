// state_pattern_header.h
#ifndef STATE_PATTERN_H
#define STATE_PATTERN_H

class State
{
public:
	virtual void insertQuarter() = 0;
	virtual void ejectQuarter() = 0;
	virtual void turnCrank() = 0;
	virtual void dispense() = 0;
	virtual void refill();
};

class GumballMachine;

class SoldOutState : public State
{
	GumballMachine* gbMachine;
public:
	SoldOutState(GumballMachine* gbM);

	void insertQuarter();

	void ejectQuarter();

	void turnCrank();

	void dispense();
	
	void refill();
};

class NoQuarterState : public State
{
	GumballMachine* gbMachine;
public:
	NoQuarterState(GumballMachine* gbM);

	void insertQuarter();

	void ejectQuarter();

	void turnCrank();

	void dispense();
};

class HasQuarterState : public State
{
	GumballMachine* gbMachine;
public:
	HasQuarterState(GumballMachine* gbM);
	
	void insertQuarter();

	void ejectQuarter();

	void turnCrank();

	void dispense();
};

class SoldState : public State
{
	GumballMachine* gbMachine;
public:
	SoldState(GumballMachine* gbM);
	
	void insertQuarter();

	void ejectQuarter();

	void turnCrank();

	void dispense();	
};

class WinnerState : public State
{
	GumballMachine* gbMachine;
public:
	WinnerState(GumballMachine* gbM);
	
	void insertQuarter();

	void ejectQuarter();

	void turnCrank();

	void dispense();	
};

class GumballMachine
{
	State* soldOutState;
	State* noQuarterState;
	State* hasQuarterState;
	State* soldState;
	State* winnerState;

	State* state;
	int count;
public:
	GumballMachine();

	GumballMachine(int);

	~GumballMachine();

	void insertQuarter();

	void ejectQuarter();

	void turnCrank();

	void setState(State* st);
	
	void releaseBall();

	int getCount();
	
	State* getSoldOutState();

	State* getHasQuarterState();

	State* getNoQuarterState();

	State* getSoldState();

	State* getWinnerState();

	void refill(int);
};

#endif