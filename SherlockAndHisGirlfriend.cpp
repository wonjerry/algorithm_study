#include <iostream>
#include <cstdio>

using namespace std;

bool isPrime[100001];

int main() {
    for(int i = 2; i <= 100001; i++) {
        if(isPrime[i]) continue;
        for(int j = i + i; j <= 100001; j+= i) {
            isPrime[j] = true;
        }
    }

    int n;
    scanf("%d", &n);
    
    int max = 1;
    for(int i = 2; i <= n + 1; i++) {
        if(isPrime[i]) {
            max = 2;
            break;
        }
    }

    printf("%d\n", max);
    for(int i = 2; i <= n + 1; i++) {
        printf("%d ", isPrime[i] ? 2 : 1);
    }
    printf("\n");

    return 0;
}