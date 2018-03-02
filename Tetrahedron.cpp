#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    long long temp, numOfthree = 1, numOftwo = 0;

    for(int i = 1; i < n; i++) {
        temp = numOftwo;
        numOftwo = (3ll * numOfthree + 2ll * numOftwo) % 1000000007;
        numOfthree = temp;
    }

    cout << numOftwo << '\n';
    return 0;
}