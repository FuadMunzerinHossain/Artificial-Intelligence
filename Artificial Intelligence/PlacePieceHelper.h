#pragma once 

// Finds if a slot is an immediate win ( wins by placing there in next move)
// The position is passed by reference. 
bool findImmediateWin(int& winPosi, int& winPosj, char piece, char(&board)[3][3]);

// Finds if a slot is fork opportunity
// The position is passed by reference. 
bool isForkPossible(int& forkPosi, int&forkPosj, char piece, char(&board)[3][3]);


