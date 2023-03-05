//
// Created by Berk Ozkan on 5.03.2023.
//

#ifndef HW1_SORTING_H
#define HW1_SORTING_H


void swap(int& a, int& b, int& moveCount);


void insertionSort(int *arr, const int size, int &compCount, int &moveCount);

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);

void merge (int *arr, int first, int mid, int last, int& compCount, int& moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);

void partition(int *arr, int first, int last, int& pivotIndex, int& compCount,  int& moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);

void hybridSort(int *arr, const int size, int &compCount, int &moveCount);

void reverseArr(int* arr, const int size);

#endif //HW1_SORTING_H
