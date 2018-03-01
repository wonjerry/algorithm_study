#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool check[26];

int main() {
    int n;
    scanf("%d", &n);
    string str;
    cin >> str;

    int cnt = 0;
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] - 'A' < 26) {
            for(int j = 0; j < 26; j++) {
                check[j] = false;
            }
            cnt = 0;
        }else if(!check[str[i] - 'a']) {
            check[str[i] - 'a'] = true;
            cnt++;
        }

        if(max < cnt) {
            max = cnt;
        }
    }

    printf("%d\n", max);
    return 0;
}