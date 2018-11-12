#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>
#include <stack>
#define SMALL_BRACKET_OPEN 40
#define SMALL_BRACKET_CLOSE 41
#define MIDDLE_BRACKET_OPEN 91
#define MIDDLE_BRACKET_CLOSE 93
#define LARGE_BRACKET_OPEN 123
#define LARGE_BRACKET_CLOSE 125

using namespace std;

/*
  BRACKETS2: https://algospot.com/judge/problem/read/BRACKETS2
  그냥 스택을 사용하면 되는 간단한 문제이다.

  여기서 잘 체크해야하는 엣지 케이스는
  - 여는 괄호만 들어오는 경우 또는 닫는 괄호만 들어오는 경우 ([{ 또는 })] 이 경우를 잘 처리해야 한다.
*/

int main() {
  vector< pair<char, char> > bracketPairs;
  bracketPairs.push_back(make_pair(SMALL_BRACKET_OPEN, SMALL_BRACKET_CLOSE));
  bracketPairs.push_back(make_pair(MIDDLE_BRACKET_OPEN, MIDDLE_BRACKET_CLOSE));
  bracketPairs.push_back(make_pair(LARGE_BRACKET_OPEN, LARGE_BRACKET_CLOSE));

  int testCaseNum;
  scanf("%d", &testCaseNum);

  while(testCaseNum--) {
    stack<int> s;
    bool result = true;
    string brackets;
    cin >> brackets;

    for (auto bracket : brackets) {
      for (auto pair : bracketPairs) {
        if (pair.first == bracket) {
          s.push(bracket);
          break;
        }

        if (pair.second == bracket) {
          if (!s.empty() && pair.first == s.top()) {
            s.pop();
          } else {
            result = false;
          }
        }
      }
    }

    printf("%s\n", result && s.empty() ? "YES" : "NO");
  }
  return 0;
}