#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>    // std::swap
using namespace std;
const int MAX = 40001;

struct Node {
	int to, cost;
    Node(){
	}
	Node(int to, int cost) : to(to), cost(cost) {
	}
};

vector<Node> tree[MAX];
vector<int> depth(MAX , 0);
vector<Node> parent(MAX);
vector<bool> isChecked(MAX, false);

int main()
{
    int nodeNum, LCAProblemNum;
    cin >> nodeNum;

    for(int i = 0; i < nodeNum - 1; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;

        tree[start].push_back(Node(end, cost));
        tree[end].push_back(Node(start, cost));
    }

    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        isChecked[current] = true;

        for(Node ele : tree[current]){
            if(!isChecked[ele.to]) {
                depth[ele.to] = depth[current] + 1;
                parent[ele.to] = Node(current, ele.cost);
                q.push(ele.to);
            }
        }
    }

    cin >> LCAProblemNum;

    for(int i = 0; i < LCAProblemNum; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        int node1Depth = depth[node1];
        int node2Depth = depth[node2];

        int node1Costsum = 0;
        int node2Costsum = 0;

        if( node2Depth < node1Depth ) {
            swap(node2, node1);
            swap(node2Depth, node1Depth);
        }

        while(node1Depth != node2Depth) {
            node2Costsum += parent[node2].cost;
            node2 = parent[node2].to;
            node2Depth = depth[node2];
        }
        
        if(node1 == node2) {
            cout << node2Costsum << '\n';
        }else {
            while(node1 != node2) {
                node1Costsum += parent[node1].cost;
                node1 = parent[node1].to;
                node2Costsum += parent[node2].cost;
                node2 = parent[node2].to;
            }
            cout << node1Costsum + node2Costsum<< '\n';
        }
    }

    return 0;
}