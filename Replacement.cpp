#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    string str;
    cin >> str;

    vector<pair<int, int> > terms;
    bool isDot = false;
    int start = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == '.' && isDot == false) {
            isDot = true;
            start = i;
        } else {
            if(i - start >= 2) {
                terms.push_back(make_pair<int, int>(start, i - 1));
            }
            isDot = false;
        }
    }

    for(int i = 0; i < m; i++) {
        int pos;
        char letter;
        scanf("%d %c", &pos, &letter);

        for(int j = 0, len = terms.size(); j < len; j++) {
            pair<int, int> boundary = terms[j];

            if(boundary.first <= pos && pos <= boundary.second) {
                
            }
        }

        printf("%d\n", result);
    }


    return 0;
}