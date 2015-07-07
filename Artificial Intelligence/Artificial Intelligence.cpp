// Artificial Intelligence.cpp : Defines the entry point for the console application.
// CONTAINS MAIN FUNCTION
//

#include "stdio.h"
#include "MakeLowerCase.h"
#include "TicTacToe.h"
#include "IsValidCommand.h"
#include "Parser_main.h"

#include <string>
#include <vector>
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
	int playerWins = 0;
	int aiWins = 0;
	start = clock();	// sets the start time at now. 


	// Introduction for the first time: 
	userName = resetAI(); 
	// above function took username but does not store it beyond scope
	// need to modify it if we want to display username later.
	
	//keep looping until the user wants to end the program
	while (exit == false)
	{

		//get the command from the user
		cout << endl;
		cout << "How may I help you?" << endl;
		getline(std::cin, command);
		cout << endl;

		commandAdjusted = makeLowerCase(command);

		if (commandAdjusted == "reset")
		{
			playerWins = 0;
			aiWins = 0;
			start = clock(); // reset start time 
			userName = resetAI(); 
		}

		else if (commandAdjusted == "summary")
		{
			showSummary(start,  playerWins, aiWins);
		}

		else if (commandAdjusted == "exit"){
			exit = true;
			showSummary(start, playerWins, aiWins);
			cout << "Thanks for playing! :)" << endl;
		} 

		else if (commandAdjusted == "help"){
			showHelp(); 
		}

		else if (commandAdjusted == "game" || commandAdjusted == "play")
		{
			// The program enters the state to play game. 
			// The logic here should be isolated away from main func.

			string gameSelect;
			string gameSelectAdjusted;

			cout << "What game do you want to play? (Type in the number or the name of the game)" << endl;
			cout << "1. Tic-tac-toe" << endl;
			getline(std::cin, gameSelect);
			gameSelectAdjusted = makeLowerCase(gameSelect);

			//checks if argument is valid
			while (!isValidCommand(gameSelectAdjusted)){
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
		else {	// invalid command 
			cout << "Invalid Command!\n"; 
			showHelp(); 
		}



	}
	return 0;
}