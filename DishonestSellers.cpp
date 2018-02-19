#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int now, next, diff;
};

void merge(int start, int end, vector<Item> &items) {
    int mid = (start + end) / 2;
    int l = start;
    int r = mid + 1;
    int index = 0;
    vector<Item> result(end - start + 1);

    while(l <= mid && r <= end) {
        if(items[l].diff < items[r].diff) {
            result[index++] = items[l++];
        }else if(items[l].diff > items[r].diff) {
            result[index++] = items[r++];
        }else {
            if(items[l].now < items[r].now) {
                result[index++] = items[l++];
            }else if(items[l].now > items[r].now) {
                result[index++] = items[r++];
            }else {
                result[index++] = items[l++];
                result[index++] = items[r++];
            }
        }
    }

    while(l <= mid) result[index++] = items[l++];
    while(r <= end) result[index++] = items[r++];

    for(int i = start; i <= end; i++) {
        items[i] = result[i - start];
    }
}

void _sort(int start, int end, vector<Item> &items) {

    if(start == end) {
        return;
    }
    
    int mid = (start + end) / 2;

    _sort(start, mid, items);
    _sort(mid + 1, end, items);
    merge(start, end, items);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<Item> items(n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &items[i].now);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &items[i].next);
    }

    for(int i = 0; i < n; i++) {
        items[i].diff = items[i].now - items[i].next;
    }

    _sort(0, n - 1, items);

    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(items[i].diff <= 0) {
            sum += items[i].now;
            k--;
        }else if(items[i].diff > 0 && k > 0) {
            sum += items[i].now;
            k--;
        }else {
            sum += min(items[i].now, items[i].next);
        }
    }

    printf("%d\n", sum);
    return 0;
}