#include <state_pattern_header.h>
#include <iostream>

using namespace std;

void State::refill()
{
	std::cout << "Refill doing nothing\n";
}

SoldOutState::SoldOutState(GumballMachine* gbM) : gbMachine{gbM}
{
}

void SoldOutState::insertQuarter()
{
	cout << "You inserted a quarter, but we are sold out\n";
}

void SoldOutState::ejectQuarter()
{
	cout << "Good you ejected the quarter coz we are sold out\n";
}

void SoldOutState::turnCrank()
{
	cout << "You turned crank, but we are sold out\n";
}

void SoldOutState::dispense()
{
	cout << "Cannot dispense, we are sold out\n";
}	

void SoldOutState::refill()
{
	gbMachine->setState(gbMachine->getNoQuarterState());
}

NoQuarterState::NoQuarterState(GumballMachine* gbM) : gbMachine{gbM}
{
}

void NoQuarterState::insertQuarter()
{
	cout << "Inserted a quarter\n";
	gbMachine->setState(gbMachine->getHasQuarterState());
}

void NoQuarterState::ejectQuarter()
{
	cout << "You haven't inserted a quarter\n";
}

void NoQuarterState::turnCrank()
{
	cout << "You turned, but there is no quarter\n";
}

void NoQuarterState::dispense()
{
	cout << "You need to pay first\n";
}	

HasQuarterState::HasQuarterState(GumballMachine* gbM) : gbMachine{gbM}
{
}

void HasQuarterState::insertQuarter()
{
	cout << "Quarter already inserted\n";
}

void HasQuarterState::ejectQuarter()
{
	cout << "Ejecting the inserted quarter\n";
	gbMachine->setState(gbMachine->getNoQuarterState());
}

void HasQuarterState::turnCrank()
{
	cout << "You turned...\n";

	int winner = rand() % 10 + 1; // random number between 1 to 10
	if(winner == 10 && gbMachine->getCount() > 1)
		gbMachine->setState(gbMachine->getWinnerState());
	else
		gbMachine->setState(gbMachine->getSoldState());
}

void HasQuarterState::dispense()
{
	cout << "No gubmall dispensed\n";
}	

SoldState::SoldState(GumballMachine* gbM) : gbMachine{gbM}
{
}

void SoldState::insertQuarter()
{
	cout << "Please wait...gubmall is already being given to you\n";
}

void SoldState::ejectQuarter()
{
	cout << "Sorry, you already turned the crank\n";
}

void SoldState::turnCrank()
{
	cout << "You turned crank twice\n";
}

void SoldState::dispense()
{
	gbMachine->releaseBall();
	if(gbMachine->getCount() > 0)
		gbMachine->setState(gbMachine->getNoQuarterState());
	else
	{
		cout << "Oops, out of gubmalls\n";
		gbMachine->setState(gbMachine->getSoldOutState());
	}
}	

WinnerState::WinnerState(GumballMachine* gbM) : gbMachine{gbM}
{
}

void WinnerState::insertQuarter()
{
	cout << "Please wait...gubmall is already being given to you\n";
}

void WinnerState::ejectQuarter()
{
	cout << "Sorry, you already turned the crank\n";
}

void WinnerState::turnCrank()
{
	cout << "You turned crank twice\n";
}

void WinnerState::dispense()
{
	gbMachine->releaseBall();
	if(gbMachine->getCount() == 0)
	{
		cout << "Oops, out of gubmalls\n";
		gbMachine->setState(gbMachine->getSoldOutState());
	}
	else
	{
		gbMachine->releaseBall();
		cout << "You're a winner! You got two balls\n";
		if(gbMachine->getCount() > 0)
			gbMachine->setState(gbMachine->getNoQuarterState());
		else
		{
			cout << "Oops, out of gubmalls\n";
			gbMachine->setState(gbMachine->getSoldOutState());
		}

	}
}

GumballMachine::GumballMachine()
{
	GumballMachine(0);
}

GumballMachine::GumballMachine(int numBalls) : count{numBalls}
{
	this->soldOutState = new SoldOutState(this);
	this->noQuarterState = new NoQuarterState(this);
	this->hasQuarterState = new HasQuarterState(this);
	this->soldState = new SoldState(this);
	this->winnerState = new WinnerState(this);

	if(numBalls > 0)
		this->state = noQuarterState;
	else
		this->state = soldOutState;
}

GumballMachine::~GumballMachine() = default;

void GumballMachine::insertQuarter()
{
	this->state->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
	this->state->ejectQuarter();
}

void GumballMachine::turnCrank()
{
	this->state->turnCrank();
	this->state->dispense();
}

void GumballMachine::setState(State* st)
{
	this->state = st;
}

void GumballMachine::releaseBall()
{
	cout << "A gumball comes rolling out the slot...\n";
	if(count != 0)
		count--;
}

int GumballMachine::getCount()
{
	return count;
}

State* GumballMachine::getSoldOutState()
{
	return soldOutState;
}

State* GumballMachine::getHasQuarterState()
{
	return hasQuarterState;
}

State* GumballMachine::getNoQuarterState()
{
	return noQuarterState;
}

State* GumballMachine::getSoldState()
{
	return soldState;
}

State* GumballMachine::getWinnerState()
{
	return winnerState;
}

void GumballMachine::refill(int refCount)
{
	count += refCount;
	cout << "The gumball machine has been refilled...new count : " << count << "\n";
	this->state->refill();
}