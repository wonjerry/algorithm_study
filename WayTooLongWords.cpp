#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	int h = m / 2;
	int tempResult = h * n;
	int rest = n / 2;

	cout << tempResult + rest << '\n';
	return 0;
}