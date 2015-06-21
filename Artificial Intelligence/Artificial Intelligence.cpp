// Artificial Intelligence.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "MakeLowerCase.h"
#include "TicTacToe.h"
#include <string>
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

bool validCommand(string command);

int main(int argc, const char* argv[])
{
	string userName;
	string command;
	string commandAdjusted;
	bool newAI = true;
	bool exit = false;
	clock_t start;
	int playerWins = 0;
	int aiWins = 0;
	
	//keep looping until the user wants to end the program
	while (exit == false)
	{
		//this if statement executes when the AI program first starts, and also if the user wishes to reset the AI
		if (newAI == true)
		{
			playerWins = 0;
			aiWins = 0;

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
			cout << "Player has " << playerWins << " game win(s)." << endl;
			cout << "AI has " << aiWins << " game win(s)." << endl;
		}

		else if (commandAdjusted == "game" || commandAdjusted == "play")
		{
			string gameSelect;
			string gameSelectAdjusted;

			cout << "What game do you want to play? (Type in the number or the name of the game)" << endl;
			cout << "1. Tic-tac-toe" << endl;
			getline(std::cin, gameSelect);
			gameSelectAdjusted = makeLowerCase(gameSelect);

			//checks if argument is valid
			while (!validCommand(gameSelectAdjusted)){
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
	}
	return 0;
}

bool validCommand(string command)
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