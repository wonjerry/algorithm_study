#include <iostream>
#include <cstdio>

bool isHole[1000001];

using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i < m; i++) {
        int temp;
        scanf("%d", &temp);

        isHole[temp] = true;
    }

    int bonePosition = 1;
    bool isDropped = false;
    for(int i = 0; i < k; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        
        if(isDropped) continue;
        
        if(start == bonePosition) {
            isDropped = isHole[end];
            if(!isHole[start]) bonePosition = end;
        } else if(end == bonePosition) {
            isDropped = isHole[start];
            if(!isHole[end]) bonePosition = start;
        }
    }

    printf("%d\n", bonePosition);
    return 0;
}