#include <iostream>
#include <cstdio>

using namespace std;

bool isSame(int *initial, int *rotated, int size) {
    for(int i = 0; i < size; i++) {
        if(initial[i] != rotated[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    int *initialGears = new int[n];
    int *rotatedGears = new int[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &initialGears[i]);
        rotatedGears[i] = initialGears[i];
    }

    bool result = true;

    do {
        result = true;

        for(int i = 0; i < n; i++) {
            if(i%2 == 0) {
                rotatedGears[i]++;
                if(rotatedGears[i] == n) {
                    rotatedGears[i] = 0;
                }
            }else {
                rotatedGears[i]--;
                if(rotatedGears[i] < 0) {
                    rotatedGears[i] = n - 1;
                }
            }

            if( i != rotatedGears[i]) {
                result = false;
            }
        }
    }while(!isSame(initialGears, rotatedGears, n) && !result);

    printf("%s\n", result ? "Yes" : "No");


    return 0;
}