#include <iostream>
#include <cstdio>

int tree[18][1<<17];

using namespace std;

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    long long size = 1 << n;

    for(int i = 0; i < size; i++) {
        scanf("%d", &tree[n][i]);
    }

    bool isOr = true;
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < size; j+=2) {
            if(isOr) tree[i - 1][j/2] = tree[i][j] | tree[i][j + 1];
            if(!isOr) tree[i - 1][j/2] = tree[i][j] ^ tree[i][j + 1];
        }
        isOr = !isOr;
    }

    for(int i = 0; i < m; i++) {
        int pos, val;
        scanf("%d %d", &pos, &val);

        tree[n][pos - 1] = val;
        isOr = true;
        int j = pos - 1;
        for(int i = n; i > 0; i--) {
            int parent;
            int p1, p2;

            parent = j / 2;
            if(j % 2 == 0) {
                p1 = j;
                p2 = j + 1;
            }else {
                p1 = j - 1;
                p2 = j;
            }

            if(isOr) tree[i - 1][j / 2] = tree[i][p1] | tree[i][p2];
            if(!isOr) tree[i - 1][j / 2] = tree[i][p1] ^ tree[i][p2];
            isOr = !isOr;
            j = j / 2;
        }

        printf("%d\n", tree[0][0]);
    }

    return 0;
}