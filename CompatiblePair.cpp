#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    int *tommy = new int[n];
    int *banban = new int[m];

    for(int i = 0; i < n; i++) {
        scanf("%d", &tommy[i]);
    }

    for(int i = 0; i < m; i++) {
        scanf("%d", &banban[i]);
    }

    int index = 0;
    long long max = (long long) tommy[0] * banban[0];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            long long temp = (long long) tommy[i] * banban[j];

            if(max < temp) {
                max = temp;
                index = i;
            }
        }
    }

    max = (long long) tommy[index == 0 ? 1 : 0] * banban[0];
    for(int i = 0; i < n; i++) {
        if(i == index) continue;
        for(int j = 0; j < m; j++) {
            long long temp = (long long) tommy[i] * banban[j];

            if(max < temp) {
                max = temp;
            }
        }
    }

    printf("%I64d\n", max);

    return 0;
}