#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>
#define MOD 1000000007 

using namespace std;

int cache[101];

/*
  비 대칭 타일링: https://algospot.com/judge/problem/read/ASYMTILING
  이 문제는 비 대칭인 타일들의 개수를 구하는 문제이다.
  다시 생각해 보면 저번에 풀었던 TILING2 문제에서 대칭인 타일을 제거하는 문제이다.
  내가 가장 먼저 들었던 생각은 모든 경우의 수 에서 대칭인 타일만 구하면 되겟다 그 다음에 빼면 되겠다는 생각이었다.
  - 저번에 만들었던 tiling 함수를 이용하여 해당 width에 대한 모든 경우의 수를 구했다.
  - 그 다음에 양쪽이 1개짜리로 채워지거나 2개짜리로 채워지는 방법의 경우의 수를 구했다.
  - 그 다음 그 둘을 뺐다.
  이 방법은 아직까지도 이론적으로 가능하다고 생각하지만 예제 테스트케이스도 통과하지 못했다. 뭔가 구현이 어렵다.

  이러한 시도 끝에 책을 보았고 다른 방법, 생각의 접근법을 생각 했다.
  타일을 채우는 방법의 수 중 대칭인 타일을 찾는 방법의 수는 크게 세가지로 나눌 수 있다.
  - width까 홀수인 경우, 가운데는 길쭉한 걸로 채우고 양쪽을 대칭이도록 채우는 경우의 수
  - width가 짝수인경우 정확히 반반 대칭인경우
  - width가 짝수인경우 정 가운데는 가로가 2인 타일 두개로 채우는 경우
  이렇게 세가지 경우에서 양쪽을 채울때, 한쪽만 채우면 다른쪽은 자연스럽게 결정된다고 생각하면 된다 왜냐하면 대칭이니까.
  따라서 저번에 만든 tiling 함수로 이 세가지를 구현하면 된다. 전체에서 나머지 반쪽을 채우는 방법의 수를 계산하여 뺀다.
*/

int tiling(int n) {
  if (cache[n] != -1) {
    return cache[n];
  }

  if (n == 0 || n == 1) {
    return 1;
  }

  return cache[n] = (tiling(n - 1) + tiling(n - 2)) % MOD;
}

int asymmetry(int width) {
  if (width % 2 == 1) {
    return (tiling(width) - tiling(width / 2) + MOD) % MOD;
  }

  int total = tiling(width);
  total = (total  - tiling(width / 2) + MOD) % MOD;
  total = (total - tiling(width/2 - 1) + MOD) % MOD;

  return total;
}

int main() {
  int testCaseNum;
  scanf("%d", &testCaseNum);

  memset(cache, -1, sizeof(int) * 101);

  while(testCaseNum--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", asymmetry(n));
  }
  return 0;
}