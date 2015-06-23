#include "stdio.h"
#include "TicTacToe.h"
#include <iostream>

using namespace std;

int tictactoe(bool firstTurn)
{
	//initialize the board, a 2D 3x3 array
	char board[3][3];
	char player;
	char ai;

	//note: rules of tic-tac-toe state that X goes first
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

	//make the board empty at the start of the game
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}

	//if ai goes first, it will always place the first piece on the middle of the board
	if (firstTurn == false)
	{
		board[1][1] = ai;
	}

	printBoard(board);

	while (boardFull(board) == false)
	{
		//beginning of human move
		int row;
		int column;

		cout << "Enter row and then column number where you want to place your mark (Top left is [1,1])" << endl;
		cin >> row >> column;

		if (board[row - 1][column - 1] == ' ')
		{
			board[row - 1][column - 1] = player;
			printBoard(board);
			cout << "You have placed your piece at [" << row - 1 << "][" << column - 1 << endl;
		}

		else
		{
			while (board[row - 1][column - 1] != ' ')
			{
				cout << "Invalid move, that location is not empty." << endl;
				cout << "Enter row and then column number where you want to place your mark (Top left is [1,1])" << endl;
				cin >> row >> column;

				if (board[row - 1][column - 1] == ' ')
				{
					board[row - 1][column - 1] = player;
					printBoard(board);
					cout << "You have placed your piece at [" << row - 1 << "][" << column - 1 << endl;
				}
			}
		}
		//end of human move

		if (boardFull(board) == false)
		{
			aiPlacePiece(board, ai);
		}
	}

	return 1;
}

bool boardFull(char  (&board)[3][3])
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

void printBoard(char(&board)[3][3])
{
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

void aiPlacePiece(char(&board)[3][3], char ai)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = ai;

				if (calculateLongestStreakAtThisLocation(board, i, j, ai) == 3)
				{
					return;
				}

				board[i][j] = ' ';
			}
		}
		cout << endl;
	}
	return;
}

int calculateLongestStreakAtThisLocation(char(&board)[3][3], int i, int j, char ai)
{
	
	return 1;
}