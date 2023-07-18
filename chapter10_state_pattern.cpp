#include <iostream>
#include <state_pattern_header.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int count = 1;
	GumballMachine gbm(count);
	gbm.insertQuarter();
	gbm.turnCrank();

	gbm.refill(100);

	return 0;
}