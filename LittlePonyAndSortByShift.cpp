#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* arr;
    arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int temp = arr[0];
    int result = 0;

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (temp <= arr[i]) {
            temp = arr[i];
            count++;
        }else {
            break;
        }
    }

    if (count == n) {
        result = 0;
    }else {
        temp = arr[0];
        for (int i = n - 1; i >= count; i--) {
            if (arr[i] <= temp) {
                temp = arr[i];
                result++;
            }else {
                result = -1;
                break;
            }
        }
    }

    cout << result << endl;

    return 0;
}