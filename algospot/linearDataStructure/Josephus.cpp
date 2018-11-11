#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

queue<int> q;

void initSoldiers (int n) {
  while(!q.empty()) q.pop();

  for (int i = 1; i <= n; i++) {
    q.push(i);
  }
}

void josephus(int k) {
  int cnt = 0;

  while(q.size() != 2) {
    int soldier = q.front();
    q.pop();
    if (cnt-- == 0) {
      cnt = k - 1;
      continue;
    }
    q.push(soldier);
  }
}

void printSoldiers() {
  vector<int> result;
  while(!q.empty()) {
    result.push_back(q.front());
    q.pop();
  }

  sort(result.begin(), result.end());

  for(auto ele : result) {
    printf("%d ", ele);
  }
  printf("\n");
}

int main() {
  int testCaseNum;
  scanf("%d", &testCaseNum);

  while(testCaseNum--) {
    int n, k;
    scanf("%d %d", &n, &k);

    initSoldiers(n);
    josephus(k);
    printSoldiers();
  }
  return 0;
}