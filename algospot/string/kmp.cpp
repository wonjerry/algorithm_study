#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

vector<int> getPartialMatch(const string& N) {
  int m = N.size();
  vector<int> pi(m, 0);

  // 자기 자신 이후부터 처리해야하므로 begin = 1로 처리함.
  int begin = 1, matched = 0;
  while (begin + matched < m) {
     if (N[begin + matched] == N[matched]) {
       ++matched;
       pi[begin + matched] = matched;
     } else {
       if (matched == 0) {
         ++begin;
       } else {
         begin += matched - pi[matched - 1];
         matched = pi[matched - 1];
       }
     }
  }
  return pi;
}

// H가 total, N이 pattern
vector<int> kmpSearch(const string& H, const string& N) {
  int n = H.size(), m = N.size();
  vector<int> ret;
  // kmp 알고리즘은 접두사도 되며 접미사도 되는 위치들을 미리 구해두어야 한다.
  vector<int> pi = getPartialMatch(N);
  int begin = 0, matched = 0;
  // 시작부분은 total string에서 pattern string의 길이를 뺀부분까지여야 한다. 그 이상이면 overflow.
  while(begin <= n - m) {
    if (matched < m && H[begin + matched] == N[matched]) {
      if (++matched == m) ret.push_back(begin);
    } else {
      if (matched == 0) {
        ++begin;
      } else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }

  return ret;
}

int main() {

  return 0;
}