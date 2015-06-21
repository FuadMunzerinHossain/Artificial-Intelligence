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