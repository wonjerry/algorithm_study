#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

struct TreeNode {
  vector<TreeNode*> children;
};

int main() {
  int testCaseNum;
  scanf("%d", &testCaseNum);

  while(testCaseNum--) {
    int nodeNum;
    scanf("%d", &nodeNum);

    TreeNode* root = new TreeNode();
    for (int i = 0; i < nodeNum; i++) {
      int x, y, r;
      scanf("%d %d %d", &x, &y, &r);
    }
  }
  return 0;
}