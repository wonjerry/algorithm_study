#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

string w, s;
int cache[101][101];
vector<string> result;

bool match(int wPos, int sPos) {

  if (cache[wPos][sPos] != -1) {
    return cache[wPos][sPos];
  }

  while(wPos < w.length() && sPos < s.length()) {
    if (w[wPos] != s[sPos] && w[wPos] != '?') {
      break;
    }

    wPos++;
    sPos++;
  }

  if (wPos == w.length()) {
    return cache[wPos][sPos] = (sPos == s.length());
  }

  if (w[wPos] == '*') {
    for (int skip = 0; sPos + skip <= s.length(); skip++) {
      if (match(wPos + 1, sPos + skip)) {
        return cache[wPos][sPos] = 1;
      }
    }
  }

  return cache[wPos][sPos] = 0;
}

int main() {
  int testCaseNum;
  scanf("%d", &testCaseNum);

  while (testCaseNum--) {
    cin >> w;

    int filenameNum;
    scanf("%d", &filenameNum);

    for (int i = 0; i < filenameNum; i++) {
      for(int i=0; i < 101; i++) {
        memset(cache[i], -1, sizeof(int)*101);
      }
      cin >> s;
      if (match(0, 0)) {
        result.push_back(s);
      }
    }

    sort(result.begin(), result.end());

    int resultSize = result.size();
    for (int i = 0; i < resultSize; i++) {
      cout << result[i] << '\n';
    }

    result.clear();
  }

  return 0;
}
