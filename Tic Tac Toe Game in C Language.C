ayi#include <stdio.h>
#include <conio.h>

char board[3][3];
char currentPlayer = 'X';

void initializeBoard() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    
    printf("\n\tT I C  T A C  T O E\n");
    printf("\tPlayer 1 (X)  -  Player 2 (O)\n\n");

    printf("       0   1   2\n\n");
    for(int i = 0; i < 3; i++) {
        printf("   %d   ", i);
        for(int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if(j < 2) printf(" | ");
        }
        printf("\n");
        if(i < 2) printf("      -----------\n");
    }
}

int checkWin() {
    // Rows + Columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return 1;
        if(board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return 1;
    }
    // Diagonals
    if(board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return 1;
    if(board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return 1;

    return 0;
}

int checkDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] == ' ')
                return 0;
    return 1;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int row, col;
    initializeBoard();

    while(1) {
        printBoard();

        printf("\nPlayer %c, enter row and column (e.g., 0 2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check valid move
        if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("\nInvalid Move! Press any key to try again...");
            getch();
            continue;
        }

        board[row][col] = currentPlayer;

        if(checkWin()) {
            printBoard();
            printf("\n?? Player %c Wins!\n", currentPlayer);
            break;
        }

        if(checkDraw()) {
            printBoard();
            printf("\n?? Match Draw!\n");
            break;
        }

        switchPlayer();
    }

    printf("\nPress any key to exit...");
    getch();
    return 0;
}

