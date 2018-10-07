#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

/*
  1. 완전탐색으로 풀어보기
    이 문제를 그냥 무식하게 풀고 각 경로가 어떻게 이루어져있는지 쭉 써보면
    어떤 부분이 중복되는지 보일 것 이다. 즉 어떤 경로가 중복되고 있는지 보인다.

  2. 중복을 제거하는 메모이제이션으로 풀기
    d[y][x]: x,y에서 다음 경로들 까지 가는 것 중 경로의 합의 최대 값.
    이렇게 다이나믹 배열을 설정 한 후에 caching을 해 두면 중복되는 문제들을 잡을 수 있다.
    문제를 풀 때는 해당 위치에서 (y + 1, x), (y + 1, x + 1)의 위치로 이동했을 때
    즉 x, y를 시작점으로 하는 또 다른 삼각형에서의 최대 경로의 합을 구하고 그것을 d에 저장하는 방식으로 생각했다.
*/

int triangle[100][100];
int d[100][100];
int triangleSize;

int getMaximumPath(int y, int x) {
  if (d[y][x] != -1) {
    return d[y][x];
  }
  if (y >= triangleSize || x >= triangleSize) {
    return triangle[y][x];
  }

  int left = getMaximumPath(y + 1, x);
  int right = getMaximumPath(y + 1, x + 1);

  return d[y][x] = triangle[y][x] + max(left, right);
}

int main() {
  int testCaseNum;
  scanf("%d", &testCaseNum);

  while (testCaseNum--) {
    for (int i = 0; i < 100; i++) {
      memset(triangle[i], 0, sizeof(int) * 100);
      memset(d[i], -1, sizeof(int) * 100);
    }

    scanf("%d", &triangleSize);

    for (int y = 0; y < triangleSize; y++) {
      for (int x = 0; x <= y; x++) {
        scanf("%d", &triangle[y][x]);
      }
    }
    cout << getMaximumPath(0, 0) << '\n';
  }
  
  return 0;
}