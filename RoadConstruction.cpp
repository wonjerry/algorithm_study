#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool check[1001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) {
        int p1, p2;
        scanf("%d %d", &p1, &p2);

        check[p1] = true;
        check[p2] = true;
    }

    int center = 0;
    for(int i = 1; i <= n; i++) {
        if(!check[i]) {
            center = i;
            break;
        }
    }

    if(center == 0) {
        printf("0\n");
    }else {
        printf("%d\n", n - 1);
        for(int i = 1; i <= n; i++) {
            if(i != center) {
                printf("%d %d\n", center, i);
            }
        }
    }

    return 0;
}