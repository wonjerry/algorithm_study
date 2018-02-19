#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[50001];
vector<int> depth(50001 , 0);
vector<int> parent(50001 , 0);
vector<bool> isChecked(50001, false);

int main()
{
    int nodeNum, LCAProblemNum;
    cin >> nodeNum;

    for(int i = 0; i < nodeNum - 1; i++){
        int start, end;
        cin >> start >> end;

        tree[start].push_back(end);
        tree[end].push_back(start);
    }

    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        isChecked[current] = true;

        for(auto ele : tree[current]){
            if(!isChecked[ele]) {
                depth[ele] = depth[current] + 1;
                parent[ele] = current;
                q.push(ele);
            }
        }
    }

    cin >> LCAProblemNum;

    for(int i = 0; i < LCAProblemNum; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        int node1Depth = depth[node1];
        int node2Depth = depth[node2];

        while(node1Depth != node2Depth) {
            if(node1Depth > node2Depth) {
                node1 = parent[node1];
                node1Depth = depth[node1];
            }else if(node1Depth < node2Depth){
                node2 = parent[node2];
                node2Depth = depth[node2];
            }
        }

        if(node1 == node2) {
            cout << node1 << '\n';
        }else {
            while(parent[node1] != parent[node2]) {
                node1 = parent[node1];
                node2 = parent[node2];
            }
            cout << parent[node1] << '\n';
        }
    }

    return 0;
}