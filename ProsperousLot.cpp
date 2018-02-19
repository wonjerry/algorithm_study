#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    if(n > 36) {
        printf("-1\n");
        return 0;
    }

    int eightNum = n / 2;
    int elseNum = n % 2;
    string result = "";

    for(int i = 0; i < eightNum; i++) {
        result += "8";
    }

    for(int i = 0; i < elseNum; i++) {
        result += "4";
    }

    cout << result << '\n';

    return 0;
}