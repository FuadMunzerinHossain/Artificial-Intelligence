// Artificial Intelligence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MakeLowerCase.h"

#include <iostream>

using namespace std;

//int _tmain(int argc, _TCHAR* argv[])
int main(int argc, const char* argv[])
{
	string userName;
	string command;
	bool newAI = true;
	bool exit = false;
	
	//keep looping until the user wants to end the program
	while (exit == false)
	{
		//this if statement executes when the AI program first starts, and also if the user wishes to reset the AI
		if (newAI == true)
		{
			cout << "New AI initializing..." << endl;
			cout << "Hi, What is your name? " << endl;
			getline(std::cin, userName);
			cout << endl;

			cout << "It's nice to meet you " << userName << "!" << endl;
			cout << endl;

			newAI = false;
		}

		//get the command from the user
		cout << "How may I help you?" << endl;
		getline(std::cin, command);
		cout << endl;

		if (makeLowerCase(command) == "reset")
		{
			newAI = true;
		}

	}
	return 0;
}

