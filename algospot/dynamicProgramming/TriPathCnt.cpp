#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

int cache[100][100];
int pathCache[100][100];
int triangle[100][100];
int n;

/*
  https://algospot.com/judge/problem/read/TRIPATHCNT
  이 문제는 저번에 풀었던 TRIANGLE 에서 최대 경로의 갯수를 구하는 문제로 발전된 문제이다.
  Triangle에서 최대 경로를 구하는 방법은 동일하게 가져가는데, 단지 pathCache를 추가해서
  pathCache[y][x] = 어떤 x,y 까지 올 때 각 경로의 합이 최대일 때, 해당 좌표까지 오는 경로의 갯수 라고 정의하고 문제를 해결하였다.

  맨 처음엔 pathCache를 추가할까 말까 고민했지만 어떤 좌표까지 가는 경로의 최대 합을 캐싱하는 것이 필요했고, 각 좌표까지 가는데 경로의 경우의수가 몇가지인지
  저장하는 캐시가 또 필요하다고 판단되어 추가하였다.
*/

int getTriangleMax (int y, int x) {
  if (y >= n - 1 || x >= n - 1) {
    pathCache[y][x] = 1;
    return cache[y][x] = triangle[y][x];
  }

  if (cache[y][x] != -1) {
    return cache[y][x];
  }

  int left = getTriangleMax(y + 1, x);
  int right = getTriangleMax(y + 1, x + 1);

  int now = 0;
  if (left == right) {
    pathCache[y][x] += pathCache[y + 1][x] + pathCache[y + 1][x + 1];
    now = triangle[y][x] + left;
  } else if (left < right) {
    pathCache[y][x] += pathCache[y + 1][x + 1];
    now = triangle[y][x] + right;
  } else if (left > right) {
    pathCache[y][x] += pathCache[y + 1][x];
    now = triangle[y][x] + left;
  }

  return cache[y][x] = now;
}

int main() {
  int testCaseNum;
  scanf("%d", &testCaseNum);

  while(testCaseNum--) {
    for (int i = 0; i < 100; i++) {
      memset(cache[i], -1, sizeof(int) * 100);
      memset(pathCache[i], 0, sizeof(int) * 100);
      memset(triangle[i], 0, sizeof(int) * 100);
    }

    scanf("%d", &n);

    for (int y = 0; y < n; y++) {
      for (int x = 0; x <= y; x++) {
        scanf("%d", &triangle[y][x]);
      }
    }

    getTriangleMax(0, 0);

    printf("%d\n", pathCache[0][0]);
  }
  return 0;
}