#include <iostream>
#include <cstdio>

using namespace std;

int board[3][3];

void toggleBoard(int x, int y) {
    board[y][x] = 1 - board[y][x];

    if(x - 1 >= 0) {
        board[y][x - 1] = 1 - board[y][x - 1];
    }

    if(x + 1 < 3) {
        board[y][x + 1] = 1 - board[y][x + 1];
    }

    if(y - 1 >= 0) {
        board[y - 1][x] = 1 - board[y - 1][x];
    }

    if(y + 1 < 3) {
        board[y + 1][x] = 1 - board[y + 1][x];
    }
}

int main() {

    for(int i = 0; i < 3; i++ ) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = 1;
        }
    }

    for(int i = 0; i < 3; i++ ) {
        for(int j = 0; j < 3; j++) {
            int num;
            scanf("%d", &num);

            if(num % 2 == 1) {
                toggleBoard(j, i);
            }
        }
    }

    for(int i = 0; i < 3; i++ ) {
        for(int j = 0; j < 3; j++) {
            printf("%d",  board[i][j]);
        }
        printf("\n");
    }
    return 0;
}