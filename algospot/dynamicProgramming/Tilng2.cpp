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
  https://algospot.com/judge/problem/read/TILING2
  나는 맨 처음에 이 문제를 접근할 때
  어떤 n에서 2x1, 2x2 블록을 선택 했을 때 나머지 영역을 가지고 재귀를 돈다고 생각했다.
  즉 현재의 선택을 제외한 나머지에서 완벽한 부분 문제가 성립하였다.
  그래서 return 값을 2 + tiling(n - 1) + tiling (n - 2)로 했었다.
  그러나 2는 더할 필요가 없다. 왜냐하면 n이 1 또는 2가 남는 부분까지 재귀를 타고 갔을 때 그 과정들이 1가지 경우의 수이기 때문이다.
  따라서 tiling(n - 1) + tiling (n - 2) 를 return 하고, n이 0 또는 1일때 1(경우의수 성립)만 return 하면 된다.
*/

int cache[101];

int tiling(int n) {
  if (cache[n] != -1) {
    return cache[n];
  }

  if ( n == 0 || n == 1 ) {
    return 1;
  }

  return cache[n] = (tiling(n - 1) + tiling(n - 2)) % 1000000007;
}

int main() {
  int testCaseNum;
  scanf("%d", &testCaseNum);

  while (testCaseNum--) {
    memset(cache, -1, sizeof(int) * 101);
    int n;
    scanf("%d", &n);

    printf("%d\n", tiling(n));
  }

  return 0;
}