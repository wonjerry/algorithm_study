#include <iostream>
#include <cstdio>

using namespace std;

void merge(int start, int end, int *arr) {
    int mid = (start + end) / 2;
    int l = start;
    int r = mid + 1;
    int index = 0;
    int *result = new int[end - start + 1];

    while(l <= mid && r <= end) {
        if(arr[l] < arr[r]) {
            result[index++] = arr[l++];
        }else if(arr[l] > arr[r]) {
            result[index++] = arr[r++];
        }
    }

    while(l <= mid) result[index++] = arr[l++];
    while(r <= end) result[index++] = arr[r++];

    for(int i = start; i <= end; i++) {
        arr[i] = result[i - start];
    }

    delete[] result;
}

void sort(int start, int end, int *arr) {

    if(start == end) {
        return;
    }
    
    int mid = (start + end) / 2;

    sort(start, mid, arr);
    sort(mid + 1, end, arr);
    merge(start, end, arr);
}

int main(){
    int n;
    scanf("%d", &n);

    int *arr = new int[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(0, n-1 ,arr);

    for(int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    delete[] arr;

}