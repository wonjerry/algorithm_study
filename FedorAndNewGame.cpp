#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, k, cnt = 0, result = 0;
    cin >> n >> m >> k;

    vector<int> playerArmys(m+1 , 0);

    for(int i = 0; i < m + 1; i++ ) {
        cin >> playerArmys[i];
    }
    
    int critertia = playerArmys[m];

    for(int i = 0; i < m; i++ ) {
       int temp = playerArmys[i] ^ critertia;

       for(int j = 0; j < n; j++ ) {
           cnt += (temp >> j) & 1;
       }

       if(cnt <= k) result ++;
       cnt = 0;
    }

    cout << result << '\n';

    return 0;
}