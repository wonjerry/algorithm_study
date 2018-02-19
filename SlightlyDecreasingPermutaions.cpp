#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void permutate(int *arr, int quotient, int n) {
    for(int i = 0; i < quotient; i++) {
        swap(arr[i], arr[(n - 1) - i]);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int *result = new int[n];
    int quotient = k / 2;
    int rest = k % 2;

    for(int i = 0; i < n; i++) {
        result[i] = i + 1;
    }

    if(rest == 0) {
        permutate(result, quotient, n);
    }else {
        quotient++;
        permutate(result, quotient, n);

        if(n % 2 != 0 || k != n - 1) {
            int temp = result [n - 1];
            for(int i = n - 1; i >= 2; i--) {
                result[i] = result[i - 1];
            }
            result[1] = temp;
        }   
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}