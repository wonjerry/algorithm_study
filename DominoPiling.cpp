#include <iostream>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	cout << (m / 2 * n) + ((m % 2 != 0) ? n / 2 : 0) << '\n';
	return 0;
}