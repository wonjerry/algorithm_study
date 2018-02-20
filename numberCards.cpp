#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int isHaveCard(int target, int *cards, int size) {
    int start = 0;
    int end = size - 1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(cards[mid] == target) {
            return 1;
        }else if(cards[mid] < target) {
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int *cards = new int[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }

    sort(cards, cards + n);

    int m;
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        int target;
        scanf("%d", &target);
        printf("%d ", isHaveCard(target, cards, n));
    }
    printf("\n");

    return 0;
}