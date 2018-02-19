#include <iostream>
#include <vector>
using namespace std;
vector<int> piles(100001 , 0);

int main()
{
    int numOfPiles;
    cin >> numOfPiles;

    for(int i = 1; i <= numOfPiles; i++) {
        cin >> piles[i];
        piles[i] += piles[i - 1];
    }

    int numOfJuicyWorms;
    cin >> numOfJuicyWorms;

    for(int i = 0; i < numOfJuicyWorms; i++) {
        int target;
        cin >> target;

        for(int j = 1; j <= numOfPiles; j++) {
            if( target <= piles[j] ) {
                cout << j << '\n';
                break;
            }
        }
    }

    return 0;
}