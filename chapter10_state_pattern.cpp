#include <iostream>
#include <state_pattern_header.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int count = 10;
	GumballMachine gbm(count);
	gbm.insertQuarter();
	gbm.turnCrank();

	return 0;
}