#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

/*만약 queue를 직접 구현하고자 한다면 배열보다는 링크드리스트(vector)로 구현하는 편이 더 편리할 것이고 효율적일 것이다.*/

int main() {
    queue<int> q;

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    vector<int> result;
    while(!q.empty()) {
        for(int i = 0; i < m; i++) {
            if(i == m - 1) {
                result.push_back(q.front());
                q.pop();
                break;
            }

            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    printf("<");
    for(int i = 0; i < n; i++) {
        if(i == n - 1) {
            printf("%d", result[i]);
            break;
        }

        printf("%d, ", result[i]);
    }
    printf(">\n");

    return 0;
}