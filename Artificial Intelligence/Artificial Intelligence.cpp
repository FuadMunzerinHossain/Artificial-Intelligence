// Artificial Intelligence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MakeLowerCase.h"

#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, const char* argv[])
{
	string userName;
	string command;
	string commandAdjusted;
	bool newAI = true;
	bool exit = false;
	clock_t start;
	
	//keep looping until the user wants to end the program
	while (exit == false)
	{
		//this if statement executes when the AI program first starts, and also if the user wishes to reset the AI
		if (newAI == true)
		{
			cout << "New AI initializing..." << endl;
			start = clock();
			cout << "Hi, What is your name? " << endl;
			getline(std::cin, userName);
			cout << endl;

			cout << "It's nice to meet you " << userName << "!" << endl;

			newAI = false;
		}

		//get the command from the user
		cout << endl;
		cout << "How may I help you?" << endl;
		getline(std::cin, command);
		cout << endl;

		commandAdjusted = makeLowerCase(command);

		if (commandAdjusted == "reset")
		{
			newAI = true;
		}

		else if (commandAdjusted == "summary")
		{
			double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Age of AI is " << duration << " seconds." << endl;
		}
	}
	return 0;
}

