#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int arr[500];
int d[500];

int getLISLength (int now, int arrSize) {
  if (d[now] != -1) {
    return d[now];
  }
  cout << now << endl;
  int result = 0;
  for (int i = now; i < arrSize; i++) {
    if (arr[now] < arr[i]) {
      result = max(result, getLISLength(i, arrSize));
    }
  }

  return d[now] = result + 1;
}

int main() {
  int testCaseNum;
  scanf("%d", &testCaseNum);

  while(testCaseNum--) {
    memset(arr, 0, sizeof(int) * 500);
    memset(d, -1, sizeof(int) * 500);
    int arraySize;
    scanf("%d", &arraySize);

    for (int i = 0; i < arraySize; i++) {
      scanf("%d", &arr[i]);
    }

    printf("%d\n", getLISLength(0 ,arraySize));
  }
  return 0;
}