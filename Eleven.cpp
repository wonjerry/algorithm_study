#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int fiboCheck[1001];

int main() {
    int n;
    scanf("%d", &n);
    
    int index = 3;
    fiboCheck[1] = 1;
    fiboCheck[2] = 1;

    while(fiboCheck[index - 1] + fiboCheck[index - 2] <= n) {
        fiboCheck[index] = fiboCheck[index - 1] + fiboCheck[index - 2];
        index++;
    }

    string result = "";
    index = 2;
    for(int i = 1; i <= n; i++) {
        if(fiboCheck[index] == i) {
            result += "O";
            index++;
        }else {
            result += "o";
        }
    }
    cout << result << '\n';
    return 0;
}