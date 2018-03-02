#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    for(int i = 1; i <= n; i++) {
        int haveToWorkTime;
        scanf("%d", &haveToWorkTime);

        t -= 86400 - haveToWorkTime;
        
        if(t <= 0) {
            printf("%d\n", i);
            break;
        }
    }
    
    return 0;
}