#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

/*
  이 문제는 그냥 맞는 경우만 생각하면 도저히 왜 중복되는 부분이 있는건지 모른다.
  하지만 안돼는 경우를 생각해보면 매우매우 많이 중복된다는 것을 찾을 수 있다.
  만약 ******a와 aaaaaab를 생각 해 보면
  *을 만났을 때 마다 aaaaaab, aaaaab, aaaab, ... ,b를 반복해야 한다는 것을 알 수 있다.
  따라서 이러한 경우를 cache[패턴의 위치][주어진 문자열의 위치] = match 여부 로 두고 메모이제이션 한다면
  중복되는 경우에 대해 매우 빠르게 처리할 수 있다.
*/

string w, s;
int cache[101][101];
vector<string> result;

bool match(int wPos, int sPos) {

  // caching이 되어있다면 바로 끝낸다.
  if (cache[wPos][sPos] != -1) {
    return cache[wPos][sPos];
  }

  // 패턴과 문자열을 돌면서 같은 문자가 아니거나 ?가 아니라면 break하고 검사한다.
  while(wPos < w.length() && sPos < s.length()) {
    if (w[wPos] != s[sPos] && w[wPos] != '?') {
      break;
    }

    wPos++;
    sPos++;
  }

  // 만약 두 문자열 모두 끝에 도달했다면 true, 패턴만 끝이라면 false
  if (wPos == w.length()) {
    return cache[wPos][sPos] = (sPos == s.length());
  }

  if (w[wPos] == '*') {
    // *을 만났을 경우 sPos이상의 문자열과 wPos + 1이상의 문자열에 대해 match가 되면 true
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
      // 2차원 배열은 이렇게 초기화 해야한다.
      for(int i=0; i < 101; i++) {
        memset(cache[i], -1, sizeof(int) * 101);
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
