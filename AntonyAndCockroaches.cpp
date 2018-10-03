#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    char *cocks = new char[n];
    bool isRed = false;

    for(int i = 0; i < n; i++) {
        cin >> cocks[i];
        if(i == 0) {
            if(cocks[i] == 'b') isRed = true;
        }
    }

    int swapCnt = 0, colorChangeCnt = 0;
    for(int i = 1; i < n; i++) {
        if(!isRed && cocks[i] == 'r') {
            bool isFind = false;
            for(int j = i + 1; j < n; j++) {
                if(cocks[j] == 'b') {
                    cocks[j] = 'r';
                    swapCnt++;
                    isFind = true;
                    break;
                }
            }
            if(!isFind) {
                colorChangeCnt += (n - i) / 2;
                if((n - i) % 2 != 0) {
                    colorChangeCnt++;
                }
                break;
            }
        }else if(isRed && cocks[i] == 'b') {
            bool isFind = false;
            for(int j = i + 1; j < n; j++) {
                if(cocks[j] == 'r') {
                    cocks[j] = 'b';
                    swapCnt++;
                    isFind = true;
                    break;
                }
            }
            if(!isFind) {
                colorChangeCnt += (n - i) / 2;
                if((n - i) % 2 != 0) {
                    colorChangeCnt++;
                }
                break;
            }
        }
        isRed = !isRed;
    }

    cout << swapCnt + colorChangeCnt << '\n';
    return 0;
}