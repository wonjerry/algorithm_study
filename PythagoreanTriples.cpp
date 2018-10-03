#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if(n <= 2) cout << - 1 << '\n';
    else if(n % 2 == 0) {
        cout << (n * n / 4) - 1 << ' ' << (n * n / 4) + 1 << '\n';
    }else {
        cout << (n * n / 2) << ' ' << (n * n / 2) + 1 << '\n';
    }
    
    return 0;
}