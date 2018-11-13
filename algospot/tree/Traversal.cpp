#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

void temp (vector<int> &preorder, vector<int> &inorder) {
  int root = preorder[0];
  int pos = 0;
  for (int i = 0; i < inorder.size(); i++) {
    if (inorder[i] == root) {
      pos = i;
      break;
    }
  }

  for (int i = 1; i < preorder.size(); i++) {
    for (int j = 0; j < inorder.size(); j++) {
      if (preorder[i] == inorder[j]) {
        
      }
    }
  }
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


  }
  return 0;
}