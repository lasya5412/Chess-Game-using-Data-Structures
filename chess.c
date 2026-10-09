
#include <stdio.h>

#define SIZE 8

void displayBoard(char board[SIZE][SIZE]) {
    printf("\n  a b c d e f g h\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", 8 - i);

        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }

        printf("%d\n", 8 - i);
    }

    printf("  a b c d e f g h\n");
}

int main(void) {
    char board[SIZE][SIZE] = {
        {'r','n','b','q','k','b','n','r'},
        {'p','p','p','p','p','p','p','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'P','P','P','P','P','P','P','P'},
        {'R','N','B','Q','K','B','N','R'}
    };

    int sr, sc, dr, dc;
    char choice;

    printf("===== CHESS GAME =====\n");
    printf("White pieces: Uppercase letters\n");
    printf("Black pieces: Lowercase letters\n");
    printf("Empty square: .\n");

    while (1) {
        displayBoard(board);

        printf("\nEnter source row and column (0-7),");
        printf(" or -1 to quit: ");

        if (scanf("%d", &sr) != 1) {
            printf("Invalid input.\n");
            break;
        }

        if (sr == -1) {
            printf("Thanks for playing!\n");
            break;
        }

        if (scanf("%d", &sc) != 1) {
            printf("Invalid input.\n");
            break;
        }

        printf("Enter destination row and column (0-7): ");

        if (scanf("%d %d", &dr, &dc) != 2) {
            printf("Invalid input.\n");
            break;
        }

        if (sr < 0 || sr >= SIZE ||
            sc < 0 || sc >= SIZE ||
            dr < 0 || dr >= SIZE ||
            dc < 0 || dc >= SIZE) {
            printf("Invalid coordinates! Try again.\n");
            continue;
        }

        if (board[sr][sc] == '.') {
            printf("The source square is empty!\n");
            continue;
        }

        if (sr == dr && sc == dc) {
            printf("Source and destination cannot be the same!\n");
            continue;
        }

        board[dr][dc] = board[sr][sc];
        board[sr][sc] = '.';

        printf("\nMove completed!\n");
    }

    return 0;
}
