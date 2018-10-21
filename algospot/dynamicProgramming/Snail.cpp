#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

int n, m;
double cache[1000][2001];

/*
  https://algospot.com/judge/problem/read/SNAIL
  이 문제는 경우의 수 문제 중 확률을 구하는 문제이다.
  원래 확률이란 "(해당하는 경우의 갯수 / 전체 경우의수의 갯수)" 로 연산할 수 있다.
  만약 이 문제에서 1칸 올라가는 확률 2칸 올라가는 확률이 같았다면 
  (11111...2), (1111...22), (11111...222), (11111...2222) ... 이런식의 경우의 수들 중 우물의 길이 n만큼 올라간 경우의 갯수를 찾으면 되었다.
  하지만 이 문제에서는 1과 2의 출현 확률이 달라서 1 * 0.25, 1* 0.75 이렇게 연산할 필요가 있다.
  따라서 각 재귀함수의 결과에 해당 경우의 확률을 곱한 값을 결과값으로 생각하여 경우의 수의 갯수가 아닌 확률을 구하는 방식으로 구현하였다.

  맨 처음에는 이걸 어떻게 작은 부분 문제로 쪼갤지 감이 안왔다. 천천히 생각해보니
  현재 달팽이는 1일차일때 1칸 올라갈수도, 2칸 올라갈 수도 있다.
  1칸 올라갔을 때 1칸 올라갈 수도 2칸 올라갈 수도 있으며, 2칸 올라갔을 때 1칸 올라갈 수도 2칸 올라갈 수도 있다.
  결국 1칸 올라가거나 2칸 올라가는 부분 문제로 나눌 수 있다.
  따라서 climb(day, climbed) = climb(day + 1, climbed + 1) + climb(day + 1, climbed + 2) 이렇게 연산이 가능하였다.
  그리고 재귀함수를 돌릴 때 기저 조건은 day(m)이 다 되었을 때 우물의 높이(n)만큼 올라왔냐 안 올라왔냐로 판가름 할 수 있다.

  그런데 조금 더 생각해보면 저 재귀함수 시퀀스에서 day + 1, climbed + 1 인 경우의 끝에 도달 한 다음 day + 1, climbed + 2인 경우를 만나면서
  타고 올라 올 텐데, 이때 중복되는 부분문제들이 생긴다. 그림으로 그려보면 TRIANGLE 문제와 같은 모양이 나오며, day * (day + 1) / 2 만큼의 중복되는 부분 문제가 발생한다.

  따라서 이런 부분문제들을 위해 cache로 저장 해 두면 중복되는 재귀 시퀀스를 돌지 않으므로 모든 노드를 1번만 돌게되어 O(N)으로 시간 복잡도를 줄일 수 있다.
*/

double climb (int day, int climbed) {
  if (day == m) {
    return climbed >= n ? 1 : 0;
  }

  if (cache[day][climbed] != -1.0) {
    return cache[day][climbed];
  }

  // 1만큼 올라가는걸로 n day만큼 갈꺼니까 2만큼 가는건이미 계산되어있을 수 있음.
  return cache[day][climbed] = (climb(day + 1, climbed + 1) * 0.25) + (climb(day + 1, climbed + 2) * 0.75);
}

int main() {
  int testCaseNum;
  scanf("%d", &testCaseNum);

  while(testCaseNum--) {
    for (int i = 0; i < 1000; i++) {
      for (int j = 0; j < 2001; j++) {
        cache[i][j] = -1.0;
      }
    }
    scanf("%d %d", &n, &m);
    printf("%0.10lf\n", climb(0, 0));
  }
  return 0;
}