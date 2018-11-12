#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

// H가 total, N이 pattern
vector<int> kmpSearch(const string& H, const string& N) {
  int n = H.size(), m = N.size();
  vector<int> ret;
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