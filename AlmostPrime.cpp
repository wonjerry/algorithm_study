#include <iostream>

using namespace std;

bool isNotPrime[3001];

int main() {
    for(int i = 2; i < 55; i++) {
        if(isNotPrime[i]) continue;
        for(int j = i + i; j < 3001; j+=i) {
            isNotPrime[j] = true;
        }
    }

    int n;
    cin >> n;

    int result = 0;
    for(int i = 6; i <= n; i++) {
        if(isNotPrime[i]) {
            int cnt = 0;
            for(int j = 2; j < i; j++) {
                if(!isNotPrime[j] && i % j == 0) {
                    cnt++;
                }
            }

            if(cnt == 2) {
                result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}