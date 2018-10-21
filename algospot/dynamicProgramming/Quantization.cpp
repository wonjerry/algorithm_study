#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

vector<int> arr;

int quantize(int from, int parts) {
  cout << from << " , " << parts << endl;
  int size = arr.size();
  int sum = 0;
  int result = 987654321;
  int avg = 0;

  for (int i = from; i < size; i++) {
    sum += arr[i];
    avg = round(sum / (float)(i + 1));
    // 여기에 문제가 있는 것 같음
    // 일단 무식하게 풀고 dp로 최적화가 필요함.
    int squareSum = from < size ? arr[from] : 0;
    for (int j = from; j <= i; j++) {
      int value = arr[j] - avg;
      squareSum += value * value;
    }

    if (parts != 1) {
      result = min(result, squareSum + quantize(i + 1, parts - 1));
    } else {
      result = squareSum;
    }
  }

  return result;
}

int main() {
  int testCaseNum ;
  scanf("%d", &testCaseNum);

  while(testCaseNum--) {
    int len, S;
    arr.clear();
    scanf("%d %d", &len, &S);

    for (int i = 0; i < len; i++) {
      int num;
      scanf("%d", &num);
      arr.push_back(num);
    }

    sort(arr.begin(), arr.end());
    printf("%d", quantize(0, S));
  }
  return 0;
}