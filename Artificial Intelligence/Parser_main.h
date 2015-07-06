// Created: July 6, 2015
// File scoped functions to parse, to be called from main
#pragma once 
#include <time.h>

using namespace std;
 
// prints out new-start messages and returns the starting time 
clock_t resetAI(); 
void showHelp(); 
void showInvalidArgs(); 
void showSummary(clock_t start, clock_t end, int playerWins, int AiWins);

