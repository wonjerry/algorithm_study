#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    set<string> neverSeenHeard;
    vector<string> result;
    for(int i = 0; i < n; i++) {
        string name;
        cin >> name;
        neverSeenHeard.insert(name);
    }

    set<string>::iterator iter;
    for(int i = 0; i < m; i++) {
        string name;
        cin >> name;
        iter = neverSeenHeard.find(name);
        if(iter != neverSeenHeard.end()) {
            result.push_back(name);
        }
    }

    sort(result.begin(), result.end());
    int len = result.size();
    printf("%d\n", len);
    for(int i = 0; i < len; i++) {
        cout << result[i] << '\n';
    }
    return 0;
}