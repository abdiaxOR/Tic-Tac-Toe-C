#include <stdio.h>

char board[3][3];
char player = 'X';

void initializeBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if(j < 2)
                printf("|");
        }
        printf("\n");
        if(i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    for(int i = 0; i < 3; i++) {
        if((board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player) ||

           (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player))
            return 1;
    }

    if((board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player) ||

       (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player))
        return 1;

    return 0;
}

int isBoardFull() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void switchPlayer() {
    if(player == 'X')
        player = 'O';
    else
        player = 'X';
}

int main() {
    int row, col;

    initializeBoard();

    while(1) {
        displayBoard();

        printf("Player %c, enter row and column (0-2): ", player);
        scanf("%d %d", &row, &col);

        if(row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid position! Try again.\n");
            continue;
        }

        if(board[row][col] != ' ') {
            printf("Cell already occupied! Try again.\n");
            continue;
        }

        board[row][col] = player;

        if(checkWin()) {
            displayBoard();
            printf("Player %c wins!\n", player);
            break;
        }

        if(isBoardFull()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }

        switchPlayer();
    }

    return 0;
}