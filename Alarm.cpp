#include <iostream>
using namespace std;

int main() {
	int n, h ,m , cnt = 0;
	cin >> n;
    cin >> h >> m;

    while(true){
        if(m % 10 == 7 || (m / 10) % 10 == 7 || h % 10 == 7 || (h / 10)%10 == 7) {
            break;
        }

        if( m - n < 0) {
            int temp = n - m;
            h = (h - 1 < 0) ? 23 : h - 1;
            m = 60 - temp;
        }else{
            m = m - n;
        }
        cnt++;
    }
    
    cout << cnt << '\n';
	return 0;
}