// Artificial Intelligence.cpp : Defines the entry point for the console application.
// CONTAINS MAIN FUNCTION

#include "MainHelper.h"

int playerWins;
int aiWins;

int main(int argc, const char* argv[])
{
	string command;
	string commandAdjusted;
	bool exit = false;
	clock_t start;
	string userName;

	// Player initial introductions
	resetAI(playerWins, aiWins, start, userName); 
	
	// Keep looping until the user wants to end the program
	while (exit == false)
	{
		// Get the command from the user
		cout << endl;
		cin.clear();
		fflush(stdin);
		cout << "How may I help you?" << endl;
		getline(std::cin, command);
		cout << endl;

		commandAdjusted = makeLowerCase(command);

		if (commandAdjusted == "reset")
		{
			resetAI(playerWins, aiWins, start, userName);
		}

		else if (commandAdjusted == "summary")
		{
			showSummary(start,  playerWins, aiWins);
		}

		else if (commandAdjusted == "game" || commandAdjusted == "play")
		{
			playGame();
		}

		else if (commandAdjusted == "help")
		{
			showHelp();
		}

		else if (commandAdjusted == "exit")
		{
			exitAI(exit, start, playerWins, aiWins);
		}

		// invalid command
		else 
		{
			showHelp(); 
		}
	}
	return 0;
}