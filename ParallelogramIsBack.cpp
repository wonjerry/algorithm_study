#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

void calPoint(int p1, int p2, int p3, vector<pair<int, int> > &points) {
    int r1, r2;

    r1 = points[p1].first + points[p2].first - points[p3].first;
    r2 = points[p1].second + points[p2].second - points[p3].second;
    printf("%d %d\n", r1, r2);
}

int main() {
    vector< pair<int, int> > points;

    for(int i = 0; i < 3; i++) {
        int p1, p2;
        scanf("%d %d", &p1, &p2);

        points.push_back(make_pair(p1, p2));
    }

    printf("3\n");
    calPoint(2, 0, 1, points);
    calPoint(0, 1, 2, points);
    calPoint(1, 2, 0, points);

    return 0;
}