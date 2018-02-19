#include <iostream>
#include <string>

using namespace std;

int main() {

    string str;
    cin >> str;
    int len = str.length();
    int left = len - 1, right = left;
    
    for(int i = 0; i < len; i++) {
        if(str[i] != 'a') {
            if(left == len - 1) {
                left = i;
            }
        }else if(str[i] == 'a') {
            if(left != len - 1) {
                right = i - 1;
                break;
            }
        }
    }

    for(int i = left; i <= right; i++) {
        if(str[i] == 'a') {
            str[i] = 'z';
        }else {
            str[i]--;
        }
    }

    cout << str << '\n';

    return 0;
}