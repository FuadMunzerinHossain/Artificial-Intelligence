#include "stdio.h"
#include "TicTacToe.h"

#include <iostream>

using namespace std;

int tictactoe(bool firstTurn)
{
	// Initialize the board, a 2D 3x3 array
	char board[3][3];
	char player;
	char ai;

	// Note: rules of tic-tac-toe state that X goes first
	if (firstTurn == true)
	{
		player = 'X';
		ai = 'O';
	}

	else
	{
		player = 'O';
		ai = 'X';
	}

	// Make the board empty at the start of the game
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}

	// If AI goes first, it will always place the first piece on the middle of the board
	if (firstTurn == false)
	{
		board[1][1] = ai;
		printBoard(board);
		cout << "I have placed my mark at [2,2]" << endl;
	}
	
	else
	{
		printBoard(board);
	}
	

	while (boardFull(board) == false)
	{
		// Beginning of human move
		int row;
		int column;

		cout << "Enter row and column # where you want to place your mark (Top left is [1,1])" << endl;
		cin >> row >> column;

		if (board[row - 1][column - 1] == ' ')
		{
			board[row - 1][column - 1] = player;
			printBoard(board);
			cout << "You have placed your piece at [" << row << "][" << column << "]" << endl;
		}

		else
		{
			bool exitLogicLoop = false;

			while (exitLogicLoop == false)
			{
				cout << "Invalid move, that location is either not empty or not valid." << endl;
				cout << "Enter row and column # where you want to place your mark (Top left is [1,1])" << endl;
				cin >> row >> column;

				if (board[row - 1][column - 1] == ' ')
				{
					board[row - 1][column - 1] = player;
					printBoard(board);
					cout << "You have placed your mark at [" << row << "][" << column <<"]"<< endl;
					exitLogicLoop = true;
				}
			}
		}
		// End of human move
		
		// Check if the player has won the game
		if (isGameWon(board, player) == true)
		{
			cout << "Game Over. You win." << endl;
			cout << "______________________________________________________________________________" << endl;
			return 1;
		}

		// Check if the AI has won the game
		else if (isGameWon(board, ai) == true)
		{
			cout << "Game Over. I win." << endl;
			cout << "______________________________________________________________________________" << endl;
			return 2;
		}

		// If the board is not full, the AI will make a move
		if (boardFull(board) == false)
		{
			aiPlacePiece(board, ai, player);
			// printBoard(board);

			// Check if the player has won the game
			if (isGameWon(board, player) == true)
			{
				cout << "Game Over. You win." << endl;
				cout << "______________________________________________________________________________" << endl;
				return 1;
			}

			// Check if the AI has won the game
			else if (isGameWon(board, ai) == true)
			{
				cout << "Game Over. I win." << endl;
				cout << "______________________________________________________________________________" << endl;
				return 2;
			}
		}
	}
	cout << "Game Over. It is a draw." << endl;
	cout << "______________________________________________________________________________" << endl;
	return 0;
}

// Function to check if the board is full; will return false if any unoccupied spaces are found
bool boardFull(char (&board)[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

// Function to visualize the board; will print the board on the console
void printBoard(char(&board)[3][3])
{
	cout << "______________________________________________________________________________" << endl;
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << '[';
			cout << board[i][j];
			cout << ']';
		}
		cout << endl;
	}
	cout << endl;
}

void aiPlacePiece(char(&board)[3][3], char ai, char player)
{
	int besti;
	int bestj;
	bool streak = true;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = ai;

				if (calculateLongestStreakAtThisLocation(board, i, j, ai) == 3)
				{
					printBoard(board);
					cout << "I placed my mark at [" << i + 1 << "][" << j + 1 << "]" << endl;
					cout << endl;
					return;
				}

				board[i][j] = ' ';
			}

			if (board[i][j] == ' ')
			{
				board[i][j] = player;

				if (calculateLongestStreakAtThisLocation(board, i, j, player) == 3)
				{
					board[i][j] = ai;
					printBoard(board);
					cout << "I placed my mark at [" << i + 1 << "][" << j + 1 << "]" << endl;
					cout << endl;
					return;
				}

				board[i][j] = ' ';
			}

			if (board[i][j] == ' ')
			{
				board[i][j] = ai;

				if (calculateLongestStreakAtThisLocation(board, i, j, ai) == 2)
				{
					besti = i;
					bestj = j;
					streak = false;
				}

				board[i][j] = ' ';
			}

			if (board[i][j] == ' ')
			{
				board[i][j] = player;

				if (calculateLongestStreakAtThisLocation(board, i, j, player) == 2 && streak == true)
				{
					besti = i;
					bestj = j;
				}

				board[i][j] = ' ';
			}
		}
		cout << endl;
	}
	streak = true;
	board[besti][bestj] = ai;
	printBoard(board);
	cout << "I placed my mark at [" << besti + 1 << "][" << bestj + 1 << "]" << endl;
	cout << endl;

	return;
}

int calculateLongestStreakAtThisLocation(char(&board)[3][3], int i, int j, char piece)
{
	int score = 1;
	int verticalScore = calculateVerticalScore(board, i, j, piece);

	if (verticalScore > score)
	{
		score = verticalScore;
	}

	int horizontalScore = calculateHorizontalScore(board, i, j, piece);

	if (horizontalScore > score)
	{
		score = horizontalScore;
	}

	int diagonalScore1 = calculateDiagonalScore1(board, i, j, piece);

	if (diagonalScore1 > score)
	{
		score = diagonalScore1;
	}

	int diagonalScore2 = calculateDiagonalScore2(board, i, j, piece);

	if (diagonalScore2 > score)
	{
		score = diagonalScore2;
	}

	return score;
}

int calculateVerticalScore(char(&board)[3][3], int i, int j, char piece)
{
	int score = 1;

	int tempi = i;

	while (tempi > 0 && board[tempi - 1][j] == piece)
	{
		tempi--;
		score++;
	}

	tempi = i;

	while (tempi < 2 && board[tempi + 1][j] == piece)
	{
		tempi++;
		score++;
	}

	return score;
}

int calculateHorizontalScore(char(&board)[3][3], int i, int j, char piece)
{
	int score = 1;

	int tempj = j;

	while (tempj > 0 && board[i][tempj-1] == piece)
	{
		tempj--;
		score++;
	}

	tempj = i;

	while (tempj < 2 && board[i][tempj+1] == piece)
	{
		tempj++;
		score++;
	}

	return score;
}

int calculateDiagonalScore1(char(&board)[3][3], int i, int j, char piece)
{
	int score = 1;

	int tempi = i;
	int tempj = j;

	while (tempi > 0 && tempj>0 && board[tempi - 1][tempj-1] == piece)
	{
		tempi--;
		tempj--;
		score++;
	}

	tempi = i;
	tempj = j;

	while (tempi < 2 && tempj<2 && board[tempi + 1][tempj + 1] == piece)
	{
		tempi++;
		tempj++;
		score++;
	}

	return score;
}

int calculateDiagonalScore2(char(&board)[3][3], int i, int j, char piece)
{
	int score = 1;

	int tempi = i;
	int tempj = j;

	while (tempi > 0 && tempj<2 && board[tempi - 1][tempj + 1] == piece)
	{
		tempi--;
		tempj++;
		score++;
	}

	tempi = i;
	tempj = j;

	while (tempi < 2 && tempj>0 && board[tempi + 1][tempj - 1] == piece)
	{
		tempi++;
		tempj--;
		score++;
	}

	return score;
}

bool isGameWon(char(&board)[3][3], char piece)
{
	if (board[0][0] == piece && board[0][1] == piece && board[0][2] == piece)
	{
		return true;
	}

	if (board[1][0] == piece && board[1][1] == piece && board[1][2] == piece)
	{
		return true;
	}

	if (board[2][0] == piece && board[2][1] == piece && board[2][2] == piece)
	{
		return true;
	}

	if (board[0][0] == piece && board[1][0] == piece && board[2][0] == piece)
	{
		return true;
	}

	if (board[0][1] == piece && board[1][1] == piece && board[2][1] == piece)
	{
		return true;
	}

	if (board[0][2] == piece && board[1][2] == piece && board[2][2] == piece)
	{
		return true;
	}

	if (board[0][0] == piece && board[1][1] == piece && board[2][2] == piece)
	{
		return true;
	}
	
	if (board[2][0] == piece && board[1][1] == piece && board[0][2] == piece)
	{
		return true;
	}

	return false;
}