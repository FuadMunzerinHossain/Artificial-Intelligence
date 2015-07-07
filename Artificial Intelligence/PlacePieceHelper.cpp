#include "PlacePieceHelper.h"
#include "TicTacToe.h"


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

			}// blank slot checking if-statement braces
		}// end of 2nd for-loop 
	}// end of 1st for-loop
	// Looped the entire board. No immediate win found.
	return false;
}


/*	A brute force algorithm to determine if there is a position available that can
*	create a fork in the next move. This can be used to determine AI's next move
*	or anticipate the player's next move												*/
bool isForkPossible(int& forkPosi, int&forkPosj, char piece, char(&board)[3][3])
{
	// Assumes there is no immediate win. 
	char opponentPiece;
	if (piece == 'X')
		opponentPiece = 'O';
	else
		opponentPiece = 'X';


	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			if (board[i][j] == ' '){
				// Place the piece temporarily 
				board[i][j] = piece;

				int nextMoveWinRow, nextMoveWinCol;
				bool twoWinPosAhead = false;
				bool oneWinPosAhead = findImmediateWin(nextMoveWinRow, nextMoveWinCol, piece, board);

				if (oneWinPosAhead){
					board[nextMoveWinRow][nextMoveWinCol] = opponentPiece;
					int thorwawayA, throwawayB;
					twoWinPosAhead = findImmediateWin(thorwawayA, throwawayB, piece, board);

					// return board to original state for this scope:
					board[nextMoveWinRow][nextMoveWinCol] = ' ';
				}
				board[i][j] = ' ';	// return board to original state for this scope

				if (twoWinPosAhead){
					forkPosi = i;
					forkPosj = j;
					return true;
				}
			}
		} // end of 2nd for-loop
	} // end of 1st for-loop

	// looped the entire board, no fork opportunities found:
	return false;
}
