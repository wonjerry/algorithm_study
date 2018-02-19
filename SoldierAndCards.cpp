#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, p1CardNum, p2CardNum;
    scanf("%d", &n);
    
    scanf("%d", &p1CardNum);
    queue<int> p1Cards;

    for(int i = 0; i < p1CardNum; i++) {
        int num;
        scanf("%d", &num);
        p1Cards.push(num);
    }

    scanf("%d", &p2CardNum);
    queue<int> p2Cards;

    for(int i = 0; i < p2CardNum; i++) {
        int num;
        scanf("%d", &num);
        p2Cards.push(num);
    }

    int cnt = 0;

    while(!p1Cards.empty() && !p2Cards.empty() && cnt <= 200) {
        int p1 = p1Cards.front();
        int p2 = p2Cards.front();

        p1Cards.pop();
        p2Cards.pop();

        if( p1 > p2 ) {
            p1Cards.push(p2);
            p1Cards.push(p1);
        } else {
            p2Cards.push(p1);
            p2Cards.push(p2);
        }
        cnt++;
    }

    if(p1Cards.size() == 0) {
        printf("%d %d\n", cnt, 2);
    } else if(p2Cards.size() == 0) {
        printf("%d %d\n", cnt, 1);
    } else {
        printf("%d\n", -1);
    }

    return 0;
}