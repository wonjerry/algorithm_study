#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n; 
    bool result = false;
    scanf("%d", &n);
    
    for(int i = 0; i <= n; i += 1234567) {
        for(int j = 0; j <= n - i; j += 123456) {
            if( (n - (i + j)) % 1234 == 0) {
                result = true;
                break;
            }
        }
        if(result) break;
    }

    printf("%s\n", result ? "YES" : "NO");

    return 0;
}