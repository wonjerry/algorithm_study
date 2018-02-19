#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int arr[1000000];

int calPivot(int start, int end) {
    return (start + end) / 2;
}

int partition(int start, int end) {
    int pivot = calPivot(start, end);
    int pivotValue = arr[pivot];
    swap(arr[pivot], arr[end]);
    
    int storedIndex = start;

    for(int i = start; i < end; i++) {
        if(arr[i] < pivotValue) {
            swap(arr[i], arr[storedIndex]);
            storedIndex++;
        }
    }

    swap(arr[storedIndex], arr[end]);

    return storedIndex;
}

void quickSort(int start, int end) {
    if(start < end) {
        int pivot = partition(start, end);
        quickSort(start, pivot - 1);
        quickSort(pivot + 1, end);
    }
}

int main() {
    int num;
    scanf("%d", &num);

    for(int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(0, num-1);

    for(int i = 0; i < num; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}