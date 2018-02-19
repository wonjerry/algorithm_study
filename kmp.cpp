#include <iostream>
#include <string>

using namespace std;

int* getPi(string str) {
    int len = str.length(), j = 0;
    int *pi = new int[len];

    for(int i = 1; i< len ; i++){ 
        while(j > 0 && str[i] != str[j]) {
            j = pi[j-1]; 
        }
        if(str[i] == str[j]) {
            pi[i] = ++j;
        }
    } 
    
    return pi;
}

int main() {

    return 0;
}