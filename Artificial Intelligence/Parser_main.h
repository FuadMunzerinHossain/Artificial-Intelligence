// Created: July 6, 2015
// File scoped functions to parse, to be called from main
#pragma once 
#include <time.h>
#include <string> 

using namespace std;
 
// prints out new-start messages and returns the starting time 
string resetAI(); 
void showHelp(); 
void showInvalidArgs(); 
void showSummary(clock_t start,  int playerWins, int AiWins);

