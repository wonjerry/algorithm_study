#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

vector<int> tree[100001];
bool isChecked[100001];
int depth[100001];
int parent[100001];
int memoiztion[100001][500];

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u,v);
    }
    int log = 1;
    for (log=1; (1<<log) <= depth[u]; log++);
    log-=1;
    for (int i=log; i>=0; i--) {
        if (depth[u] - (1<<i) >= depth[v]) {
            u = memoiztion[u][i];
        }
    }
    if (u == v) {
        return u;
    } else {
        for (int i=log; i>=0; i--) {
            if (memoiztion[u][i] != 0 && memoiztion[u][i] != memoiztion[v][i]) {
                u = memoiztion[u][i];
                v = memoiztion[v][i];
            }
        }
        return parent[u];
    }
}

int main()
{
    int nodeNum;
    scanf("%d", &nodeNum);
    // cin >> nodeNum;

    for(int i = 0; i < nodeNum - 1; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        // cin >> start >> end;

        tree[start].push_back(end);
        tree[end].push_back(start);
    }

    depth[1] = 0;
    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        isChecked[current] = true;

        for(int i = 0, len = tree[current].size(); i < len; i++) {
            int child = tree[current][i];
            if(!isChecked[child]) {
                depth[child] = depth[current] + 1;
                parent[child] = current;
                q.push(child);
            }
        }
    }

    for (int i=1; i<=nodeNum; i++) {
        memoiztion[i][0] = parent[i];
    }

    for(int j = 1; (1<<j) < nodeNum; j++) {
        for(int i = 1; i <= nodeNum; i++) {
            if(memoiztion[i][j - 1] != 0 ) {
                memoiztion[i][j] = memoiztion[memoiztion[i][j - 1]][j - 1];
            }
        }
    }

    int problemNum;
    // cin >> problemNum;
    scanf("%d", &problemNum);

    while(problemNum--) {
        int node1, node2;
        scanf("%d %d",&node1, &node2);
        
        printf("%d\n",lca(node1, node2));
    }

    return 0;
}