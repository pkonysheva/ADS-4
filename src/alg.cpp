// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                cnt++;
            }
        }
    }
    return cnt;
}

int countPairs2(int* arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        int task = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        int pos = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == task) {
                pos = mid;
                right = mid - 1;
            } else if (arr[mid] < task) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (pos != -1) {
            int j = pos;
            while (j < len && arr[j] == task) {
                ++cnt;
                ++j;
            }
        }
    }
    return cnt;
}

int countPairs3(int* arr, int len, int value) {
    int left = 0, cnt = 0;
    int right = len - 1;

    while (left < right) {
        if (arr[left] + arr[right] < value) {
            ++left;
        } else if (arr[left] + arr[right] > value) {
            --right;
        } else {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                cnt += n * (n - 1) / 2;
                break;
            }

            int leftCnt = 0, leftv = arr[left];
            while (left < right && arr[left] == leftv) {
                ++left;
                ++leftCnt;
            }

            int rightCnt = 0, rightv = arr[right];
            while (left <= right && arr[right] == rightv) {
                --right;
                ++rightCnt;
            }
            cnt += leftCnt * rightCnt;
        }
    }
    return cnt;
}
