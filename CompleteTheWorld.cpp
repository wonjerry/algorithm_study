#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    bool alphabets[26] = {false,};
    string str;
    cin >> str;

    int len = str.length();
    bool check = true;
    int start = 0, end = start + 26;

    for(int i = 0; i <= len - 26; i++) {
        start = i;
        end = start + 26;
        check = true;
        for(int j = 0; j < 26; j++) {
            alphabets[j] = false;
        }

        for(int j = i; j < i + 26; j++) {
            if(str[j] == '?') continue;

            if(!alphabets[str[j] - 'A']) {
                alphabets[str[j] - 'A'] = true;
            }else {
                check = false;
            }
        }
        if(check) break;
    }

    if(!check || len < 26) {
        cout << -1 << '\n';
    }else {
        for(int i = 0; i < len; i++) {
            if(start <= i && i < end) {
                if(str[i] == '?') {
                    for(int j = 0; j < 26; j++) {
                        if(!alphabets[j]) {
                            str[i] = j + 'A';
                            alphabets[j] = true;
                            break;
                        }
                    }
                }
            }else {
                if(str[i] == '?') {
                    str[i] = 'A';
                }
            }
        }

        cout << str << '\n';
    }

    return 0;
}