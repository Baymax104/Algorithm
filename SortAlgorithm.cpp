/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/8/12 20:52
*@Version
*/

#include "SortAlgorithm.h"
ostream & operator<<(ostream &os, const SortAlgorithm &rhs) {
    for_each(rhs.arr.begin(),  rhs.arr.end(), [&os](int x){os << x << " ";});
    os << endl;
    return os;
}
SortAlgorithm::SortAlgorithm(int *arr, int n) {
    this->arr = vector<int>(arr, arr + n);
}

void SortAlgorithm::bubbleSort() {
    int temp;
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void SortAlgorithm::cocktailSort() {
    int left = 0;
    int right = arr.size() - 1;
    int temp;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (arr[i - 1] > arr[i]) {
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
            }
        }
        left++;
    }
}

void SortAlgorithm::selectionSort() {
    int min;
    int temp;
    for (int i = 0; i < arr.size() - 1; i++) {
        min = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void SortAlgorithm::insertionSort() {
    for (int i = 1; i < arr.size(); i++) {
        int getNumber = arr[i];
        int insIndex = i;
        while (insIndex > 0 && arr[insIndex - 1] > getNumber) {
            arr[insIndex] = arr[insIndex - 1];
            insIndex--;
        }
        arr[insIndex] = getNumber;
    }
}

void SortAlgorithm::binaryInsertionSort() {
    for (int i = 1; i < arr.size(); i++) {
        int getNumber = arr[i];
        int left = 0;
        int right = i - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < getNumber) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }
        arr[left] = getNumber;
    }
}

void SortAlgorithm::shellSort() {
    for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < arr.size(); i++) {
            int getNumber = arr[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
                if (getNumber < arr[j - gap]) {
                    arr[j] = arr[j - gap];
                } else {
                    break;
                }
            }
            arr[j] = getNumber;
        }
    }
}

void SortAlgorithm::merge(int left, int mid, int right) {
    int length = right - left + 1;
    int *temp = new int[length];
    int leftIndex = left;
    int rightIndex = mid + 1;
    int i = 0;
    while (leftIndex <= mid && rightIndex <= right) {
        if (arr[leftIndex] <= arr[rightIndex]) {
            temp[i++] = arr[leftIndex++];
        } else {
            temp[i++] = arr[rightIndex++];
        }
    }
    while (leftIndex <= mid) {
        temp[i++] = arr[leftIndex++];
    }
    while (rightIndex <= right) {
        temp[i++] = arr[rightIndex++];
    }
    copy(temp, temp + length, arr.begin() + left);
    delete[] temp;
}

void SortAlgorithm::mergeSort(int left, int right) {
    if (left == right) return;
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

void SortAlgorithm::countingSort() {
    vector<int> counting;
    vector<int>::iterator max = max_element(arr.begin(), arr.end());
    counting = vector<int>(*max + 1);
    for (int i = 0; i < arr.size(); i++) {
        counting[arr[i]]++;
    }
    for (int i = 0, j = 0; i < *max + 1; i++) {
        while (counting[i] > 0) {
            arr[j] = i;
            j++;
            counting[i]--;
        }
    }
}

void SortAlgorithm::cardinalSort() {
    vector<int>::iterator maxIndex = max_element(arr.begin(),  arr.end());
    int bit = 0;
    int max = *maxIndex; // 直接对迭代器操作会修改原数据
    while (max != 0) {
        max /= 10;
        bit++;
    }
    int *bucket[10] = {nullptr};
    for (int i = 0; i < 10; i++) {
        bucket[i] = new int[arr.size()];
    }
    int everyBucketNumber[10] = {0};
    int base = 1;
    for (int i = 0; i < bit; i++) {
        // 装桶
        for (int j = 0; j < arr.size(); j++) {
            int digit = arr[j] / base % 10;
            bucket[digit][everyBucketNumber[digit]] = arr[j];
            everyBucketNumber[digit]++;
        }
        // 出桶
        int arrIndex = 0;
        for (int j = 0; j < 10; j++) {
            if (everyBucketNumber[j] != 0) {
                for (int k = 0; k < everyBucketNumber[j]; k++) {
                    arr[arrIndex++] = bucket[j][k];
                }
                everyBucketNumber[j] = 0;
            }
        }
        base *= 10;
    }
    for (int *b : bucket) {
        delete[] b;
    }
}

void SortAlgorithm::heapSort() {
    // 建最大堆
    for (int i = arr.size() / 2; i >= 0; i--) {
        shiftDown(i, arr.size());
    }
    // 将首元素与尾元素交换，再调整为最大堆
    for (int i = arr.size() - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        shiftDown(0, i);
    }
}

void SortAlgorithm::shiftDown(int index, int length) {
    int temp = arr[index];
    for (int child = 2 * index + 1; child < length; child = 2 * child + 1) {
        // 若右孩子比左孩子大，则指向右孩子
        if (child != length - 1 && arr[child + 1] > arr[child]) {
            child++;
        }
        if (temp < arr[child]) {
            arr[index] = arr[child];
            index = child;
        } else {
            break;
        }
    }
    arr[index] = temp;
}