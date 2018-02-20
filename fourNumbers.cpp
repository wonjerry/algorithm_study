#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    int numbers[4];
    scanf("%d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3]);
    
    char buffer[8];
    sprintf(buffer, "%d", numbers[0]);
    string strA = buffer;

    sprintf(buffer, "%d", numbers[1]);
    string strB = buffer;

    sprintf(buffer, "%d", numbers[2]);
    string strC = buffer;

    sprintf(buffer, "%d", numbers[3]);
    string strD = buffer;

    string numStr1 = strA + strB;
    string numStr2 = strC + strD;

    long long num1 = 0, num2 = 0;

    int tenSquare = 10;
    for(int i =  0, len = numStr1.length(); i < len; i++) {
        num1 += (long long)(numStr1[i] - '0');
        if(i == len - 1) break;
        num1 *= tenSquare;
    }

    tenSquare = 10;
    for(int i = 0, len = numStr2.length(); i < len; i++) {
        num2 += (long long)(numStr2[i] - '0');
        if(i == len - 1) break;
        num2 *= tenSquare;
    }

    cout << num1 + num2 << '\n';

    return 0;
}