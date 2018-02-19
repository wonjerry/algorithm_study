#include <iostream>
#include <cstdio>
#include <string>


using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    string problem;
    cin >> problem;
    
    int cnt = 0;
    int doorKeys[26] = {0,};

    for(int i = 0, len = problem.size(); i < len; i+=2) {
        int key = (int)problem[i] - 97;
        int door = (int)problem[i + 1] - 65;
        
        doorKeys[key]++;

        if(doorKeys[door] == 0) {
            cnt++;
        }else {
            doorKeys[door]--;
        }
    }
    printf("%d\n", cnt);

    return 0;
}