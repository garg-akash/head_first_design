#include <iostream>
#include "state_pattern_header.cpp"

using namespace std;

// class State
// {
// public:
// 	void insertQuarter();
// 	void ejectQuarter();
// 	void turnCrank();
// 	void dispense();
// };

// class GumballMachine;

// class SoldOutState : public State
// {
// 	GumballMachine* gbMachine;
// public:
// 	SoldOutState(GumballMachine* gbM) : gbMachine{gbM}
// 	{
// 	}
	
// 	void insertQuarter()
// 	{
// 		cout << "You inserted a quarter, but we are sold out\n";
// 	}

// 	void ejectQuarter()
// 	{
// 		cout << "Good you ejected the quarter coz we are sold out\n";
// 	}

// 	void turnCrank()
// 	{
// 		cout << "You turned crank, but we are sold out\n";
// 	}

// 	void dispense()
// 	{
// 		cout << "Cannot dispense, we are sold out\n";
// 	}	
// };

// class NoQuarterState : public State
// {
// 	GumballMachine* gbMachine;
// public:
// 	NoQuarterState(GumballMachine* gbM) : gbMachine{gbM}
// 	{
// 	}
	
// 	void insertQuarter()
// 	{
// 		cout << "Inserted a quarter\n";
// 		gbMachine->setState(gbMachine->getHasQuarterState());
// 	}

// 	void ejectQuarter()
// 	{
// 		cout << "You haven't inserted a quarter\n";
// 	}

// 	void turnCrank()
// 	{
// 		cout << "You turned, but there is no quarter\n";
// 	}

// 	void dispense()
// 	{
// 		cout << "You need to pay first\n";
// 	}	
// };

// class HasQuarterState : public State
// {
// 	GumballMachine* gbMachine;
// public:
// 	HasQuarterState(GumballMachine* gbM) : gbMachine{gbM}
// 	{
// 	}
	
// 	void insertQuarter()
// 	{
// 		cout << "Quarter already inserted\n";
// 	}

// 	void ejectQuarter()
// 	{
// 		cout << "Ejecting the inserted quarter\n";
// 		gbMachine->setState(gbMachine->getNoQuarterState());
// 	}

// 	void turnCrank()
// 	{
// 		cout << "You turned...\n";
// 		gbMachine->setState(gbMachine->getSoldState());
// 	}

// 	void dispense()
// 	{
// 		cout << "No gubmall dispensed\n";
// 	}	
// };

// class SoldState : public State
// {
// 	GumballMachine* gbMachine;
// public:
// 	SoldState(GumballMachine* gbM) : gbMachine{gbM}
// 	{
// 	}
	
// 	void insertQuarter()
// 	{
// 		cout << "Please wait...gubmall is already being given to you\n";
// 	}

// 	void ejectQuarter()
// 	{
// 		cout << "Sorry, you already turned the crank\n";
// 	}

// 	void turnCrank()
// 	{
// 		cout << "You turned crank twice\n";
// 	}

// 	void dispense()
// 	{
// 		gbMachine->releaseBall();
// 		if(gbMachine->getCount() > 0)
// 			gbMachine->setState(gbMachine->getNoQuarterState());
// 		else
// 		{
// 			cout << "Oops, out of gubmalls\n";
// 			gbMachine->setState(gbMachine->getSoldOutState())
// 		}
// 	}	
// };

// class GumballMachine
// {
// 	State* soldOutState;
// 	State* noQuarterState;
// 	State* hasQuarterState;
// 	State* soldState;

// 	State* state;
// 	int count;
// public:
// 	GumballMachine()
// 	{
// 		GumballMachine(0);
// 	}

// 	GumballMachine(int numBalls) : count{numBalls}
// 	{
// 		soldOutState = new SoldOutState(this);
// 		noQuarterState = new NoQuarterState(this);
// 		hasQuarterState = new HasQuarterState(this);
// 		soldState = new SoldState(this);

// 		if(numBalls > 0)
// 			state = noQuarterState;
// 		else
// 			state = soldOutState;
// 	}

// 	void insertQuarter()
// 	{
// 		state->insertQuarter();
// 	}

// 	void ejectQuarter()
// 	{
// 		state->ejectQuarter();
// 	}

// 	void turnCrank()
// 	{
// 		state->turnCrank();
// 		state->dispense();
// 	}

// 	void setState(State* st)
// 	{
// 		this->state = st;
// 	}
	
// 	void releaseBall()
// 	{
// 		cout << "A gumball comes rolling out the slot...\n";
// 		if(count != 0)
// 			count--;
// 	}

// 	State* getHasQuarterState()
// 	{
// 		return hasQuarterState;
// 	}

// 	State* getNoQuarterState()
// 	{
// 		return noQuarterState;
// 	}

// 	State* getSoldState()
// 	{
// 		return soldState;
// 	}
// };

int main(int argc, char const *argv[])
{
	int count = 10;
	GumballMachine gbm(count);

	return 0;
}