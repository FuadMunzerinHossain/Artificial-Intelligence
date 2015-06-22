#include <string>
#include <vector>

#include "IsValidCommand.h"

using namespace std;

bool isValidCommand(string command)
{
	//add more as necessary
	vector<string> validArg{
		"1",
		"tic-tac-toe"
	};

	bool found = false;

	for (int i = 0; i < validArg.size() && !false; ++i){
		if (validArg[i] == command) found = true;
	}

	return found;
}