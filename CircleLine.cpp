#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, s, t, result = 0;
    cin >> n;

    int* stations = new int[n + 1];

    for(int i = 1; i <= n; i++) {
        scanf("%d", &stations[i]);
    }

    scanf("%d %d", &s, &t);

    if( s > t ) swap(s ,t);

    for(int i = s; i < t; i++) {
        result += stations[i];
    }

    int tempSum = 0;

    for(int i = t; i <= n; i++) {
        tempSum += stations[i];
    }

    for(int i = 1; i < s; i++) {
        tempSum += stations[i];
    }

    result = result < tempSum ? result : tempSum;
    
    printf("%d\n", result);

    return 0;
}