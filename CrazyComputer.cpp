#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, c, cnt = 0, lastTypedTime = 0;
    cin >> n >> c;

    vector<int> times(n);

    for(int i = 0; i < n; i++) {
        cin >> times[i];
    }

    for(int i = 0; i < n; i++ ) {
        if(times[i] - lastTypedTime > c) {
            cnt = 1;
        }else {
            cnt ++;
        }
        lastTypedTime = times[i];
    }

    cout << cnt << '\n';

    return 0;
}