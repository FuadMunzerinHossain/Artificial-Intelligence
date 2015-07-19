// Created: July 6, 2015
// File scoped functions to parse, to be called from main

#include "MainHelper.h"

bool isValidCommand(string &command)
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

// prints out new initialization messages and returns username
void resetAI(int &playerWins, int &aiWins, clock_t &start, string &username)
{
	playerWins = 0;
	aiWins = 0;
	start = clock(); // Reset start time

	cout << "New AI initializing..." << endl;
	cout << "Hi, What is your name? " << endl;
	string userName;
	getline(std::cin, userName);
	cout << endl;
	cout << "It's nice to meet you " << userName << "!" << endl;

	return;
}

string makeLowerCase(const string &input)
{
	string output;

	transform(input.begin(), input.end(), back_inserter(output), ::tolower);
	return output;
}

void showHelp()
{
	cout << "Acceptable commands are: \nhelp, reset, summary, play/game, exit" << endl;
}

void showSummary(clock_t &start, int &playerWins, int &aiWins)
{
	double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Age of AI is " << duration << " seconds." << endl;
	cout << "Player has " << playerWins << " game win(s)." << endl;
	cout << "AI has " << aiWins << " game win(s)." << endl;
}

void exitAI(bool &exit, clock_t &start, int &playerWins, int &aiWins)
{
	exit = true;
	showSummary(start, playerWins, aiWins);
	cout << "Thanks for playing! ^_^" << endl;
	cout << "Exiting in 5 seconds...";
	clock_t exitStart = clock();
	double duration = (clock() - exitStart) / (double)CLOCKS_PER_SEC;

	// 5 second delay before program exits...
	while (duration < 5)
	{
		duration = (clock() - exitStart) / (double)CLOCKS_PER_SEC;
	}
}

void playGame()
{
	// The program enters the state to play a game. The game logic here should be isolated away in other .cpp files.

	string gameSelect;
	string gameSelectAdjusted;

	cout << "What game do you want to play? (Type in the number or the name of the game)" << endl;
	cout << "1. Tic-tac-toe" << endl;
	getline(std::cin, gameSelect);
	gameSelectAdjusted = makeLowerCase(gameSelect);

	//Checks if argument is valid
	while (isValidCommand(gameSelectAdjusted) == false)
	{
		cout << endl;
		cout << "Please enter a valid argument." << endl;
		getline(std::cin, gameSelect);
		gameSelectAdjusted = makeLowerCase(gameSelect);
	}

	if (gameSelectAdjusted == "1" || gameSelectAdjusted == "tic-tac-toe")
	{
		string firstTurn;
		string firstTurnAdjusted;

		cout << "Do you want to go first? (Y/N)" << endl;
		getline(std::cin, firstTurn);
		cout << endl;

		firstTurnAdjusted = makeLowerCase(firstTurn);

		if (firstTurnAdjusted == "y")
		{
			tictactoe(true);
		}

		else
		{
			tictactoe(false);
		}
	}
}













