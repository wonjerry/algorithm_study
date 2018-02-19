#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

int calPivot(int start, int end) {
    return start + ( end - start ) / 2;
}

int partition(int start, int end, vector< pair<int, int> > &arr) {
    int pivot = calPivot(start, end);
    int pivotValue = arr[pivot].first;
    swap(arr[end], arr[pivot]);

    int storedIndex = start;

    for(int i = start; i < end; i++) {
        if(arr[i].first < pivotValue) {
            swap(arr[i], arr[storedIndex]);
            storedIndex += 1;
        }
    }

    swap(arr[storedIndex], arr[end]);

    return storedIndex;
}

void quickSort(int start, int end, vector< pair<int, int> > &arr) {
    if(start < end) {
        int pivot = partition(start, end, arr);
        quickSort(start, pivot - 1, arr);
        quickSort(pivot + 1, end, arr);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    vector< pair<int, int> > leftTrees;
    vector< pair<int, int> > rightTrees;

    for(int i = 0; i < n; i++) {
        int position, apples;
        scanf("%d %d", &position, &apples);
        
        if(position > 0 ) {
            rightTrees.push_back(make_pair(position, apples));
        }else {
            leftTrees.push_back(make_pair(position, apples));
        }
    }

    int leftSize = leftTrees.size();
    int rightSize = rightTrees.size();

    quickSort(0, leftSize - 1, leftTrees);
    quickSort(0, rightSize - 1, rightTrees);

    reverse(leftTrees.begin(), leftTrees.end());

    // for(int i = 0; i < leftTrees.size(); i++) {
    //     cout << i << " , " << leftTrees[i].first << endl;
    // }
    int result = 0;
    if(leftSize == rightSize && leftSize != 0) {
        for(auto ele : leftTrees) {
            result += ele.second;
        }

        for(auto ele : rightTrees) {
            result += ele.second;
        }
    } else if(leftSize > rightSize) {
        for(int i = 0; i < rightSize; i++) {
            result += leftTrees[i].second;
            result += rightTrees[i].second;
        }

        result += leftTrees[rightSize].second;
    }else if(leftSize < rightSize) {
        for(int i = 0; i < leftSize; i++) {
            result += leftTrees[i].second;
            result += rightTrees[i].second;
        }

        result += rightTrees[leftSize].second;
    }

    printf("%d\n", result);
    return 0;
}
