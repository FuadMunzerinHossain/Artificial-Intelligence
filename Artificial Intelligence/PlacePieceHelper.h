#pragma once 

// Given a position (0 to 2 values are valid, cartesian), returns if 
// there is a chance of win diagonally,horizontally,vertically or not. 
bool isDiagonalPossible(int posX, int posY, char piece, char(&board)[3][3]);
bool isVerticalPossible(int col, char piece, char(&board)[3][3]);
bool isHorizontalPossible(int row, char piece, char(&board)[3][3]);

// Finds if a slot is an immediate threat (opponent wins by placing there in next move)
// The position is passed by reference. 
bool findImmediateWin(int& winPosi, int& winPosj, char piece, char(&board)[3][3]);

// If a given position is out of bounds, it fixes. 
int adjustIndex(int pos);

bool isCornerOrMid(int i, int j);

