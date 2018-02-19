#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector< pair<int, int> > diplomas(3);
    vector<int> result(3);

    for(int i = 0; i < 3; i++) {
        int min, max;
        scanf("%d %d", &min, &max);
        diplomas[i] = make_pair(min, max);
        result[i] = min;
        n -= min;
    }

    for(int i = 0; i < 3; i++) {
        int diff = diplomas[i].second - diplomas[i].first;

        if(n - diff >= 0) {
            result[i] += diff;
        } else if (n >= 0) {
            result[i] += n;
        }

        n -= diff;
    }

    for(auto ele : result) {
        printf("%d ", ele);
    }
    printf("\n");
    
    return 0;
}