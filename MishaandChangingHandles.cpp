#include <iostream>
#include <cstdio>
#include <utility>
#include <string>
#include <vector>
using namespace std;

bool check[1001] = {false,};

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<string, string> > handleChangeLog(n);

    string oldHandle, newHandle;
    for(int i = 0; i < n; i++) {
        cin >> oldHandle >> newHandle;
        handleChangeLog[i] = make_pair(oldHandle ,newHandle);
    }

    vector<pair<string, string> > result;

    for(int i = 0; i < n; i++) {
        if(check[i]) continue;
        pair<string, string> ele = handleChangeLog[i];
        string searchString = ele.second;
        check[i] = true;

        for(int j = i + 1; j < n; j++) {
            if(check[j]) continue;
            if(searchString.compare(handleChangeLog[j].first) == 0) {
                check[j] = true;
                ele.second = handleChangeLog[j].second;
                searchString = handleChangeLog[j].second;
            }
        }

        result.push_back(ele);
    }

    int len = result.size();
    printf("%d\n", len);
    for(int i = 0; i < len; i++) {
        cout << result[i].first << " " << result[i].second << '\n';
    }

    return 0;
}