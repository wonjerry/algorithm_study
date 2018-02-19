#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<int> graph[100001];
vector<bool> isChecked(100001 , false);
vector<int> result(100001);
queue< vector<int> > q;

int main() {
	int n = 0, start , end;
    cin >> n;
    
    for(int i = 0; i < n - 1; i++) {
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    queue<int> index;
    index.push(1);
    q.push(graph[index.front()]);

    while(!q.empty()){
        vector<int> node = q.front();
        q.pop();
        int currentNodeIndex = index.front();
        index.pop();
        for( int i = 0, len = node.size(); i < len; i++ ) {
            if(!isChecked[node[i]]) {
                result[node[i]] = currentNodeIndex;
                isChecked[node[i]] = true;
                q.push(graph[node[i]]);
                index.push(node[i]);
            }
        }
    }

    for (int i = 2; i <= n; i++ ) {
        cout << result[i] << '\n';
    }
	return 0;
}