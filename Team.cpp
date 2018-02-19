#include <iostream>

using namespace std;

int main() {
	int problems, result = 0;

    cin >> problems;

    while(problems--){
        int p,v,t;
        cin>> p >> v >> t;
        result += (p + v + t >= 2) ? 1 : 0;
    }

    cout << result << '\n';
	
    return 0;
}