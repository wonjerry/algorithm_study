#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool check[10];
vector< vector<int> > friends(10);

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void resetCheck() {
  for(int i = 0; i < 10; i ++) {
    check[i] = false;
  }
}

void printVector(vector<int> list) {
  for (auto e: list)
    cout << e << endl;
}

int findCase(int n, int floor, int cnt) {
  if (n == floor) {
    return cnt == n / 2 ? 1 : 0;
  }

  if(check[floor]) {
    return findCase(n, floor + 1, cnt);
  }

  check[floor] = true;

  vector<int> ele = friends[floor];
  int temp = 0;
  for (auto p : ele) {
    if (check[p]) {
      continue;
    }
    check[p] = true;
    temp += findCase(n, floor + 1, cnt + 1);
    check[p] = false;
  }

  check[floor] = false;

  return temp;
}

void sortFriends() {
  for(auto &ele : friends)
    sort(ele.begin(), ele.end());
}

void resetFriends() {
  for(auto &ele : friends)
    ele.clear();
}

int main() {
    int testCaseNum;
    scanf("%d", &testCaseNum);

    for(int i = 0; i < testCaseNum; i++) {
      int n, m, result = 0;
      scanf("%d %d", &n, &m);

      resetFriends();

      for(int j = 0; j < m; j++) {
        int p1, p2;
        scanf("%d %d", &p1, &p2);

        if (p1 > p2) {
          swap(p1, p2);
        }

        friends[p1].push_back(p2);
      }

      sortFriends();

      int numOfFirstOne = friends[0].size();
      for(int k = 0; k < numOfFirstOne; k++) {
        resetCheck();
        check[0] = check[friends[0][k]] = true;
        result += findCase(n, 1, 1);
      }

      printf("%d\n", result);
    }

    return 0;
}