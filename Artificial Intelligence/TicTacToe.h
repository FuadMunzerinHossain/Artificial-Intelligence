int tictactoe(bool firstTurn);

bool boardFull(char(&board)[3][3]);

void printBoard(char(&board)[3][3]);

void aiPlacePiece(char(&board)[3][3], char ai);

int calculateLongestStreakAtThisLocation(char(&board)[3][3], int i, int j, char ai);