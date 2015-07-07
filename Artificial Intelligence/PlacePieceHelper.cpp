#include "PlacePieceHelper.h"
#include "TicTacToe.h"

// If a given position is out of bounds, it fixes:
int adjustIndex(int pos){
	// max allowable index = 2
	// min allowable index = 0

	if (pos > 2)
		return adjustIndex(pos - 3);
	else if (pos < 0)
		return adjustIndex(pos + 3);
	else
		return pos;
}


/*	Loops through all the slots. If a slot is empty AND two slots slots in line (vertically,
*	horizontally or diagonally) are occupied with the same piece, then the slot is deemed
*	as an immediate win. The position is passed by reference, and returns true if found.
*	This can be used to determine immediate win move for both player & AI 					 */
bool findImmediateWin(int& winPosi, int& winPosj, char piece, char(&board)[3][3])
{
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			// if the slot is not empty, it is *not* a win move
			if (board[i][j] == ' '){
				// Place the piece temporarily 
				board[i][j] = piece; 
				// Now determine if this move wins the game. 
				bool immediateWinHere = isGameWon(board, piece); 
				board[i][j] = ' ';	// Make the board as it was .

				// break, only if there is a win. 
				if (immediateWinHere){
					winPosi = i;
					winPosj = j;
					return true;
				}

		/*
		Commented these out because I was dumb and now I thought of a more
		optimal way of calculating immediate win chance in 3 lines above. 
				//// Check for immediate vertical win: 
				//int y1 = adjustIndex(i + 1);	// index of row span vertically
				//int y2 = adjustIndex(i - 1);
				//if (board[y1][j] == piece && board[y2][j] == piece){
				//	winPosi = i;
				//	winPosj = j;
				//	return true;	// vertical win
				//}

				//// Check for immediate horizontal win: 
				//int x1 = adjustIndex(j + 1);	// index of column span horizontally
				//int x2 = adjustIndex(j - 1);
				//if (board[i][x1] == piece && board[i][x2] == piece){
				//	winPosi = i;
				//	winPosj = j;
				//	return true;	// horizontal win. 
				//}

				//if (isCornerOrMid(i, j)){	// check for immediate diagonal win
				//	if ((board[y1][x1] == piece && board[y2][x2] == piece)
				//		|| (board[y1][x2] == piece && board[y2][x1] == piece)){
				//		winPosi = i;
				//		winPosj = j;
				//		return true;	// diagonal win
				//	}
				//}

	*/		
			}// blank slot checking if-statement braces
		}// end of 2nd for-loop 
	}// end of 1st for-loop
	// Looped the entire board. No immediate win found.
	return false;
}


bool isDiagonalPossible(int posX, int posY, char piece, char(&board)[3][3])
{
	// First check if a diagonal is EVER possible from given position: 
	if (!isCornerOrMid(posX,posY))	{	
		// not in any corner or the middle slot
		return false; 
	}
	// If the middle one is lost, diagonal is not possible
	char inspecting = board[1][1]; // the char we are currently inspecting, middle one in this case
	if (inspecting != piece && inspecting != ' '){
		return false;
	}


// 	Assume that the middle is valid from now on.
	if (posX == posY){
		// (0,0) , (1,1) and (2, 2) are acceptable
		// Lets evaluate the (0,0) and (2,2) corners: 
		inspecting = board[0][0]; 
		if (inspecting == piece || inspecting == ' '){
			inspecting = board[2][2]; 
			if (inspecting == piece || inspecting == ' '){
				return true;
			}
			// else this line is not valid
		}
	}
	else {	// check bottom-left and top-right corner
		inspecting = board[2][0];
		if (inspecting == piece || inspecting == ' '){
			inspecting = board[0][2];
			if (inspecting == piece || inspecting == ' '){
				return true;
			}
			// else this line is not valid
		}
	}
	// else
	return false; 
}


bool isHorizontalPossible(int row, char piece, char(&board)[3][3])
{
	for (int col = 0; col < 3; ++col){
		char inspecting = board[row][col];
		if (inspecting != ' ' && inspecting != piece)
			return false;
	}
	return true;
}

bool isVerticalPossible(int col, char piece, char(&board)[3][3])
{
	for (int row = 0; row < 3; ++row){
		char inspecting = board[row][col];
		if (inspecting != ' ' && inspecting != piece)
			return false;
	}
	return true;
}


bool isCornerOrMid(int i, int j)
{
	// check if a diagonal is EVER possible from given position: 
	return !((i + j) % 2);
}
