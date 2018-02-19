#include <iostream>
#include <vector>

using namespace std;

struct chessPin {
	char role;
    int weight;
	chessPin(char role, int weight) : role(role), weight(weight) {
	}
};

vector<chessPin> white;
vector<chessPin> black;

int whiteSum = 0, blackSum = 0;

void calculateWeightSum(char pin) {

    for( int i = 0; i < 6; i++) {
        if(white[i].role == pin)  whiteSum += white[i].weight;
        else if(black[i].role == pin) blackSum += black[i].weight;
    }
}

int main(){
    char board[8][8];
    white.push_back(chessPin('Q' , 9));
    white.push_back(chessPin('R' , 5));
    white.push_back(chessPin('B' , 3));
    white.push_back(chessPin('N' , 3));
    white.push_back(chessPin('P' , 1));
    white.push_back(chessPin('K' , 0));

    black.push_back(chessPin('q' , 9));
    black.push_back(chessPin('r' , 5));
    black.push_back(chessPin('b' , 3));
    black.push_back(chessPin('n' , 3));
    black.push_back(chessPin('p' , 1));
    black.push_back(chessPin('k' , 0));


    for ( int i = 0; i < 8; i++ ) {
        for( int j = 0; j < 8; j++ ) {
            cin >> board[i][j];
            calculateWeightSum(board[i][j]);
        }
    }

    if(whiteSum > blackSum ) cout << "White" <<'\n';
    else if(whiteSum < blackSum ) cout << "Black" <<'\n';
    else cout << "Draw" <<'\n';

    return 0;
}