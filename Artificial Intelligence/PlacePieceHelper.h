#pragma once 

// Given a position (0 to 2 values are valid, cartesian), returns if 
// there is a chance of win diagonally or not. 
bool isDiagonalPossible(int posX, int posY, char piece, char(&board)[3][3]);