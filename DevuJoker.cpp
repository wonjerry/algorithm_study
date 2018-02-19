#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, d, songTimeSum = 0;
    scanf("%d %d", &n, &d);

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        songTimeSum += num;
    }

    int needLeastJokeNum = (n - 1) * 2;
    int rest = d - songTimeSum - (needLeastJokeNum * 5);

    if( rest >= 0) {
        printf("%d\n", rest/5 + needLeastJokeNum);
    }else {
        printf("%d\n", -1);
    }

    return 0;
}