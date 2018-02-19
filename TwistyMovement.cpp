#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int *dragon = new int[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &dragon[i]);
    }

    int cnt = 1;
    vector<int> points;
    
    for(int i = 1; i < n; i++) {
        if(dragon[i - 1] <= dragon[i]) {
            cnt++;
            
            if(i == n - 1) {
                points.push_back(cnt);
            }
        }else if(dragon[i - 1] > dragon[i]) {
            points.push_back(cnt);
            cnt = 1;
        }
    }

    cout << "=====" << endl;
    for(int i = 0; i < points.size(); i++) {
        cout << points[i] << endl;
    }
    cout << "=====" << endl;

    int max = 0;
    for(int i = 0, len = points.size(); i < len - 1; i++) {
        int point1 = points[i];
        int point2 = points[i + 1];

        if(max < point1 + point2) {
            max = point1 + point2;
        }
    }

    printf("%d\n", max);

    return 0;
}