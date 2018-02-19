#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
  public:
    int nodeNum, weight, sum;
    Node(int nodeNum, int weight)
    {
        this->nodeNum = nodeNum;
        this->weight = weight;
        this->sum = 0;
    }
};

vector<Node> graph[100001];
vector<bool> isChecked(100001, false);
vector<Node> parent;

Node bfs(Node firstNode, int nodeNum)
{
    Node longiestNode(0, 0);
    queue<Node> q;
    q.push(firstNode);

    while (!q.empty())
    {
        Node current = q.front();
        q.pop();

        isChecked[current.nodeNum] = true;

        for (int i = 0, len = graph[current.nodeNum].size(); i < len; i++)
        {
            Node &element = graph[current.nodeNum][i];
            if (!isChecked[element.nodeNum])
            {
                element.sum = element.weight + current.sum;
                q.push(element);
            }
        }
    }

    for (int i = 1; i <= nodeNum; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (graph[i][j].sum > longiestNode.sum)
            {
                longiestNode = graph[i][j];

            }
            isChecked[graph[i][j].nodeNum] = false;
            graph[i][j].sum = 0;
        }
    }
    return longiestNode;
}

int main()
{
    int n, node, target, weight;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> node;

        while (true)
        {
            cin >> target;
            if (target == -1)
                break;
            cin >> weight;

            graph[node].push_back(Node(target, weight));
        }
    }

    Node longiestNode = bfs(Node(1, 0), n);
    longiestNode.sum = 0;

    Node result = bfs(longiestNode, n);
    cout << result.sum << '\n';

    return 0;
}