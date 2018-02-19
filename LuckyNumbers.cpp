#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    long long result = 2;
    long long square = 2;

    for(int i = 2; i <= n; i++) {
        square *= 2;
        result += square;
    }

    printf("%I64d\n", result);

    return 0;
}