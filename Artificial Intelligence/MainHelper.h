// Created: July 6, 2015
// File scoped functions to parse, to be called from main
#pragma once 
#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

#include "stdio.h"
#include "TicTacToe.h"

using namespace std;
  
bool isValidCommand(string &command);
void resetAI(int &playerWins, int &aiWins, clock_t &start, string &username);
string makeLowerCase(const string& input);
void showHelp();
void showSummary(clock_t & start,  int & playerWins, int & AiWins);
void exitAI(bool &exit, clock_t &start, int &playerWins, int &aiWins);
void playGame();

