#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

/*
  TRAVERSAL: https://algospot.com/judge/problem/read/TRAVERSAL
  이 문제는 tree의 재귀적인 속성을 이해하고 있으면 풀 수 있다.
  preorder의 맨 처음 원소는 무조건 root이고 indorder에서 root원소의 왼쪽에 있는 원소들은 왼쪽 서브트리에
  오른쪽에 있는 원소들은 오른쪽 서브트리에 있으며, 각각을 또다른 tree라고 생각하면 재귀적으로 문제 해결이 가능하다.
*/

void traversal (vector<int> &preorder, vector<int> &inorder) {
  if (preorder.size() == 0 || inorder.size() == 0) {
    return;
  }

  int root = preorder[0];
  int rootIndex = 0;
  int rightTreeIndex = 0;
  vector<int> leftPreorder;
  vector<int> leftInorder;

  preorder.erase(preorder.begin());

  for (int i = 0; i < inorder.size(); i++) {
    if (root == inorder[i]) {
      rootIndex = i;
      break;
    }

    leftInorder.push_back(inorder[i]);
  }

  for(int i = 0; i < preorder.size(); i++) {
    bool isLeft = false;
    for (int j = 0; j < rootIndex; j++) {
      if (preorder[i] == inorder[j]) {
        isLeft = true;
        break;
      }
    }

    if (!isLeft) {
      rightTreeIndex = i;
      break;
    }

    leftPreorder.push_back(preorder[i]);
  }

  inorder.erase(inorder.begin(), inorder.begin() + rootIndex + 1);
  preorder.erase(preorder.begin(), preorder.begin() + rightTreeIndex);

  traversal(leftPreorder, leftInorder);
  traversal(preorder, inorder);

  printf("%d ", root);
}

int main() {
  int testCaseNum;
  scanf("%d", &testCaseNum);

  while(testCaseNum--) {
    int treeSize;
    scanf("%d", &treeSize);

    vector<int> preorder(treeSize);
    vector<int> inorder(treeSize);

    for (int i = 0; i < treeSize; i++) {
      scanf("%d", &preorder[i]);
    }

    for (int i = 0; i < treeSize; i++) {
      scanf("%d", &inorder[i]);
    }

    traversal(preorder, inorder);
  }
  return 0;
}