#include <bits/stdc++.h>
using namespace std;

int mem(int* arr, int left, int mid, int right) {
    int l = arr[left], m = arr[mid], r = arr[right];
    if ((l > m && m > r) || (r > m && m > l)) return mid;
    if ((l > r && r > m) || (m > r && r > l)) return right;
    return left;
}

int partition(int* arr, int left, int right) {
    int mid = left + ((right - left) >> 1);
    int mem = (arr, left, mid, right);
    swap(arr[left], arr[mem]);
    int i = left, j = right;
    int piovt = arr[left];
    while (i < j) {
        while (i < j && arr[j] >= piovt) j--;
        arr[i] = arr[j];
        while (i < j && arr[i] <= piovt) i++;
        arr[j] = arr[i];
    }
    arr[i] = piovt;
    return i;
}

void quick_sort(int* arr, int left, int right) {
    while (left < right) {
        int idx = partition(arr, left, right);
        if (idx - left < right - idx) {
            quick_sort(arr, left, idx - 1);
            left = idx + 1;
        } else {
            quick_sort(arr, idx + 1, right);
            right = idx - 1;
        }
    }
}

int main() {
    int arr[15] = {4, 3, 2, 5, 6, 1, 7, 11, 0, 8, 2, -1, -9, 20, 9};
    quick_sort(arr, 0, 14);
    for (int i = 0; i < 15; ++i) {
        cout << arr[i] << ",";
    }
    return 0;
}