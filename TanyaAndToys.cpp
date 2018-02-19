#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;

int main() {
    scanf("%d %d", &n, &m);

    vector<int> isChecked(n);
    vector<int> result;

    for(int i = 0; i < n; i++) {
        scanf("%d", &isChecked[i]);
    }

    int index = 1;
    int checkIndex = 0;

    sort(isChecked.begin(), isChecked.end());

    while( m >= index) {
        if(isChecked[checkIndex] == index) {
            checkIndex++;
        } else {
            m -= index;
            result.push_back(index);
        }
        index++;
    }

    printf("%d\n", result.size());
    for(int i = 0, len = result.size(); i < len; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}