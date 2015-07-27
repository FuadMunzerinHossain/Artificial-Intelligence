int tictactoe(bool firstTurn);

bool boardFull(char(&board)[3][3]);

void printBoard(char(&board)[3][3]);

void aiPlacePiece(char(&board)[3][3], char ai, char player);

int calculateLongestStreakAtThisLocation(char(&board)[3][3], int i, int j, char piece);

int calculateVerticalScore(char(&board)[3][3], int i, int j, char piece);

int calculateHorizontalScore(char(&board)[3][3], int i, int j, char piece);

int calculateDiagonalScore1(char(&board)[3][3], int i, int j, char piece);

int calculateDiagonalScore2(char(&board)[3][3], int i, int j, char piece);

bool isGameWon(char(&board)[3][3], char piece);

bool isLegalMove(char(&board)[3][3], int i, int j);