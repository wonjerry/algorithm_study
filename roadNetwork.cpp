#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

struct Node {
    int to, cost;
    Node(){

    }
    Node(int to, int cost): to(to), cost(cost) {

    }
};

const int MAX = 100001;
vector<Node> tree[MAX];
bool isChecked[MAX];
Node parent[MAX];
int depth[MAX];
int p[MAX][18];
int maxRoad[MAX][18];
int minRoad[MAX][18];

// 째째하게 한칸씩 올리는 것이 아니라 팍팍 2^k 개씩 올린다.
// 이렇게 하면 O(logN)로 복잡도가 줄어든다.
pair<int, int> lca(int u, int v) {

    int maxNum = 0 , minNum = 10000000;

    if(depth[v] > depth[u]) {
        swap(u , v);
    }

    int log = 1;
    for(log = 1; (1<<log) <= depth[u]; log++);
    log -= 1;

    for(int i = log; i >=0; i-- ) {
        if(depth[u] - (1<<i) >= depth[v]) {
            if(minNum > minRoad[u][i]) {
                minNum = minRoad[u][i];
            }

            if(maxNum < maxRoad[u][i]) {
                maxNum = maxRoad[u][i];
            }
            u = p[u][i];
        }
    }

    if(u == v) {
        return make_pair(minNum, maxNum);
    } else {
        for(int i = log; i >= 0; i--) {
            if(p[u][i] != 0 && p[u][i] != p[v][i]) {
                if(minNum > minRoad[u][i]) {
                    minNum = minRoad[u][i];
                }

                if(maxNum < maxRoad[u][i]) {
                    maxNum = maxRoad[u][i];
                }

                if(minNum > minRoad[v][i]) {
                    minNum = minRoad[v][i];
                }

                if(maxNum < maxRoad[v][i]) {
                    maxNum = maxRoad[v][i];
                }
                
                u = p[u][i];
                v = p[v][i];
            }
        }

        if(minNum > minRoad[u][0]) {
            minNum = minRoad[u][0];
        }
        if(maxNum < maxRoad[u][0]) {
            maxNum = maxRoad[u][0];
        }

        if(minNum > minRoad[v][0]) {
            minNum = minRoad[v][0];
        }

        if(maxNum < maxRoad[v][0]) {
            maxNum = maxRoad[v][0];
        }

        return make_pair(minNum, maxNum);
    }
}

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n - 1; i++) {
        int start, end, cost;
        scanf("%d %d %d" ,&start ,&end ,&cost);

        tree[start].push_back(Node(end,cost));
        tree[end].push_back(Node(start,cost));
    }

    queue<int> q;
    q.push(1);
    isChecked[1] = false;
    parent[1] = Node(0,0);
    depth[1] = 0;

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        isChecked[current] = true;

        for(int i = 0, len = tree[current].size(); i < len; i++) {
            Node child = tree[current][i];
            if(!isChecked[child.to]) {
                parent[child.to] = Node(current,child.cost);
                depth[child.to] = depth[current] + 1;
                q.push(child.to);
            }
        }
    }

    for(int i = 1; i <= n; i ++) {
        p[i][0] = parent[i].to;
        maxRoad[i][0] = parent[i].cost;
        minRoad[i][0] = parent[i].cost;
    }

    for(int j = 1; (1<<j) < n; j++) {
        for(int i = 1; i <= n; i++) {
            if(p[i][j-1] != 0) {
                p[i][j] = p[p[i][j-1]][j-1];
                maxRoad[i][j] = maxRoad[i][j-1];
                minRoad[i][j] = minRoad[i][j-1];

                if(p[p[i][j-1]][j-1] != 0) {
                    maxRoad[i][j] = max(maxRoad[i][j-1], maxRoad[p[i][j-1]][j-1]);
                    minRoad[i][j] = min(minRoad[i][j-1], minRoad[p[i][j-1]][j-1]);
                }
            }
        }
    }

    int problemNum;
    scanf("%d", &problemNum);

    while(problemNum--) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);

        pair<int, int> result = lca(node1, node2);
        printf("%d %d\n",result.first, result.second);

    }

    return 0;
}