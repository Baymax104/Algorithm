/**
*@Description
*@Author Jake
*@email wzy1048168235@163.com
*@Date 2021/8/12 20:52
*@Version
*/

#ifndef ALGORITHM_SORTALGORITHM_H
#define ALGORITHM_SORTALGORITHM_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class SortAlgorithm {
public:
    vector<int> arr;

    SortAlgorithm(int arr[], int n);

    // 冒泡排序
    void bubbleSort();

    // 定向冒泡排序
    void cocktailSort();

    // 选择排序
    void selectionSort();

    // 插入排序
    void insertionSort();

    // 二分查找插入排序
    void binaryInsertionSort();

    // 希尔排序
    void shellSort();

    // 递归归并排序
    void merge(int left, int mid, int right);
    void mergeSort(int left, int right);

    // 计数排序
    void countingSort();

    // 基数排序
    void cardinalSort();

    // 堆排序
    void heapSort();
    void shiftDown(int index, int length);

    // 快速排序
    void quickSort(int left, int right);
    int getPivot(int left, int right);
};
ostream & operator<<(ostream &os, const SortAlgorithm &rhs);

#endif //ALGORITHM_SORTALGORITHM_H
