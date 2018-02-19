#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    long long haveToBuyNum = (4 - (n % 4)) % 4;
    long long result = 0;

    if(haveToBuyNum == 1) {
        result = (a < 3 * c) ? a : (3 * c);
        result = (result < b + c) ? result : (b + c);
    }else if(haveToBuyNum == 2) {
        result = (a * 2 < b) ? (a * 2) : b;
        result = (result < 2 * c) ? result : (2 * c);
        result = (result < a + 3 * c) ? result : (a + 3 * c);
        result = (result < b + 4 * c) ? result : (b + 4 * c);
    }else if(haveToBuyNum == 3) {
        result = (a * 3 < c) ? (a * 3) : c;
        result = (result < a + b) ? result : (a + b);
        result = (result < a + 3 * c) ? result : (a + 3 * c);
        result = (result < 2 * b + c) ? result : (2 * b + c);
    }

    cout << result << '\n';

    return 0;
}