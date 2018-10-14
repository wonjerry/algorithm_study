#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

/*
  이 문제는 변형된 LIS문제이다.
  이 문제에서는 A, B 모든 원소를 돌면서 증가하는 부분수열을 찾아서 그중 가장 긴 길이를 출력해야 한다.
  LIS문제에서는 단순히 다음 원소가 현재 원소보다 크다면 재귀를 실행했다.
  하지만 이 문제에서는 현재 위치에서 A와 B의 원소 중 큰 원소에 대해 A, B의 다음 원소가 커야지만 재귀를 실행하게 되면서
  계속해서 두 배열에 대해 가장 긴 증가하는 부분수열의 길이를 찾게된다.
*/

int arrA[101];
int arrB[101];
int d[101][101]; // d[인덱스A][인덱스B] = 인덱스A, 인덱스B에서 증가하는 부분수열의 최대 길이
const long long NEGINF = numeric_limits<long long>::min();

int getLISLength (int indexA, int indexB, int sizeA, int sizeB) {
  if (d[indexA + 1][indexB + 1] != -1) {
    return  d[indexA + 1][indexB + 1];
  }

  long long a = indexA == -1 ? NEGINF : arrA[indexA];
  long long b = indexB == -1 ? NEGINF : arrB[indexB];
  // 둘의 현재 위치에서의 원소 중 큰것을 선택한다.
  long long maxValue = max(a, b);

  // 두 배열에서 하나씩 선택하면 증가하는 부분수열의 길이가 2 이므로 초기값을 설정 해 준다.
  d[indexA + 1][indexB + 1] = 2;
  
  for (int nextA = indexA + 1; nextA < sizeA; nextA++) {
    if (maxValue < arrA[nextA]) {
      d[indexA + 1][indexB + 1] = max(d[indexA + 1][indexB + 1], getLISLength(nextA, indexB, sizeA, sizeB) + 1);
    }
  }

  for (int nextB = indexB + 1; nextB < sizeB; nextB++) {
    if (maxValue < arrB[nextB]) {
      d[indexA + 1][indexB + 1] = max(d[indexA + 1][indexB + 1], getLISLength(indexA, nextB, sizeA, sizeB) + 1);
    }
  }

  return d[indexA + 1][indexB + 1];
}

int main() {
  int testCaseNum;
  scanf("%d", &testCaseNum);

  while(testCaseNum--) {
    memset(arrA, 0, sizeof(int) * 101);
    memset(arrB, 0, sizeof(int) * 101);
    for (int i = 0; i <= 100; i++) {
      memset(d[i], -1, sizeof(int) * 101);
    }

    int sizeA;
    int sizeB;
    scanf("%d", &sizeA);
    scanf("%d", &sizeB);

    for (int i = 0; i < sizeA; i++) {
      scanf("%d", &arrA[i]);
    }
      
    for (int i = 0; i < sizeB; i++) {
      scanf("%d", &arrB[i]);
    }

    // 2를 빼는 이유는 d[-1][-1]의 경우는 제외해줘야 하는데 이 값이 2 이기 때문이다.
    printf("%d\n", getLISLength(-1, -1, sizeA, sizeB) - 2);
  }
  return 0;
}