// Created: July 6, 2015
// File scoped functions to parse, to be called from main
#include "Parser_main.h"
#include <iostream> 
#include <string> 


string resetAI()
{
	cout << "New AI initializing..." << endl;
	cout << "Hi, What is your name? " << endl;
	string userName;
	getline(std::cin, userName);
	cout << endl;
	cout << "It's nice to meet you " << userName << "!" << endl;

	return userName;
}


void showHelp() {
	cout << "Acceptable commands are: \nhelp, reset, summary, play, exit" << endl;
}

void showInvalidArgs(){
	cout << "Please enter a valid argument." << endl;
}

void showSummary(clock_t start, int playerWins, int aiWins)
{
	double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Age of AI is " << duration << " seconds." << endl;
	cout << "Player has " << playerWins << " game win(s)." << endl;
	cout << "AI has " << aiWins << " game win(s)." << endl;
}














