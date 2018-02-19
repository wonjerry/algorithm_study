#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    long long rgb[3];
    cin >> rgb[0] >> rgb[1] >> rgb[2];

    sort(rgb, rgb + 3);

    long long result = rgb[0];
    rgb[1] -= result;
    rgb[2] -= result;
    int temp = rgb[1] / 3;
    result += temp * 2;
    rgb[1] = rgb[1] % 3;
    rgb[2] = rgb[2] % 3;

    if(rgb[1] > 0 && rgb[2] > 0) {
        if(rgb[1] * 2 <= rgb[2]) { // rgb[1]이 0이되므로 더이상 연산 불가
            result += rgb[1];
        } else {
            int pairNum = rgb[2] / 2;

            // 만약 rgb[2] % 2 == 1이라면 g가 2 이상이면 또 페이를 만들 수 있으므로 ++ 해 준다.
            if(rgb[2] % 2 == 1 && rgb[1] - pairNum >= 2) {
                pairNum++;
            }

            result += pairNum;
        }
    }

    cout << result <<'\n';
    
    return 0;
}