#include "PlacePieceHelper.h"

bool isDiagonalPossible(int posX, int posY, char piece, char(&board)[3][3])
{
	// First check if a diagonal is EVER possible from given position: 
	if ((posX + posY) % 2)	{	// if the sum is not divisible by 2
		// means it's not in any corner or the middle slot
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