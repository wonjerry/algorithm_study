#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;
string pi;
int d[10000];

int classify(int start, int end) {
  bool isSame = true;
  for (int i = start; i < end; i++) {
    if (pi[i] != pi[i + 1]) {
      isSame = false;
      break;
    }
  }
  if(isSame) {
    return 1;
  }

  bool isMono = true;
  bool increase = (pi[start] - '0') + 1 == pi[start + 1] - '0';
  bool decrease = (pi[start] - '0') - 1 == pi[start + 1] - '0';
  for (int i = start; i < end; i++) {
    if (!((((pi[i] - '0') + 1 == pi[i + 1] - '0' ) && increase) || (((pi[i] - '0') - 1 == pi[i + 1] - '0' ) && decrease))) {
      isMono = false;
      break;
    }
  }

  if(isMono) {
    return 2;
  }

  bool isAlter = true;
  int diff = (pi[start] - '0') - (pi[start + 1] - '0');
  for (int i = start + 1; i < end; i++) {
    if ((pi[i] - '0') - (pi[i + 1] - '0') != -1 * diff) {
      isAlter = false;
      break;
    }
    diff = -1 * diff;
  }

  if(isAlter) {
    return 4;
  }

  bool isArithmetical = true;
  diff = (pi[start] - '0') - (pi[start + 1] - '0');
  for (int i = start + 1; i < end; i++) {
    if ((pi[i] - '0') - (pi[i + 1] - '0') != diff) {
      isArithmetical = false;
      break;
    }
  }

  if(isArithmetical) {
    return 5;
  }

  return 10;

}

int getDifficulty(int start) {
  if (start == pi.length()) {
    return 0;
  }

  if (d[start] != -1) {
    return d[start];
  }

  int difficulty = 987654321;
  for (int i = 3; i <= 5; i++) {
    if (start + i <= pi.length()) {
      difficulty = min(difficulty, getDifficulty(start + i) + classify(start, start + i - 1));
    }
  }

  return d[start] = difficulty;
}

int main() {
  int testCaseNum;
  scanf("%d", &testCaseNum);

  while(testCaseNum--) {
    memset(d, -1 ,sizeof(int) * 10000);
    cin >> pi;
    printf("%d\n", getDifficulty(0));
  }

  return 0;
}