// Copyright 2021 NNTU-CS
#include <iostream>

int countPairs1(int* arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                cnt++;
            }
        }
    }
    return cnt;
}

int countPairs2(int* arr, int len, int value) {
    int cnt = 0;
    int l = 0;
    int r = len - 1;

    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == value) {
            cnt++;
            l++;
            r--;
        } else if (sum < value) {
            l++;
        } else {
            r--;
        }
    }
    return cnt;
}

int countPairs3(int* arr, int len, int value) {
    int cnt = 0;

    for (int i = 0; i < len; i++) {
        int set = value - arr[i];
        int l = i + 1;
        int r = len - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == set) {
                cnt++;
                break;
            } else if (arr[mid] < set) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return cnt;
}
