//
// Created by Berk Ozkan on 8.02.2023.
//
#include "sorting.h"

const int ALPHABET_SIZE = 10 + 2*26; // digits and upper and lower case char

std::ostream& operator<< (std::ostream& stream, const Array& array){

    int size = array.size;
    for (int i = 0; i < size-1; i++) {
        stream << array.array[i] << ", ";
    }

    stream << array.array[size-1] << std::endl;
    if (array.compCount > 0 && array.moveCount > 0){
        stream << "Comparison Count: " << array.compCount << std::endl;
        stream << "Move Count: " << array.moveCount << std::endl;
    }

    return stream;
}



void insertionSort(int *arr, const int size, int &compCount, int &moveCount){
    Timer timer;

    for (int i = 1; i < size; i++) {
        int j = i;
        compCount += 1; // comparison from while
        while (arr[j] < arr[j-1]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            moveCount += 3; //swap operation
            compCount += 1; // comparison from while
            j--;
        }
    }

}

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount){
    Timer timer;

    int unsortedPos = size;
    while (unsortedPos != 0) {
        for (int i = 0; i < unsortedPos-1; i++) {
            compCount += 1; // comparison from while
            while (arr[i] > arr[i + 1] && i < unsortedPos) {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                moveCount += 3; //swap operation
            }
        }
        unsortedPos--;
    }
}

void merge (int* arr, int first, int mid, int last){

    //initialize
    int f1 = first;
    int l1 = mid - 1;
    int f2 = mid;
    int l2 = last;
    int index = f1;
    int nSize = last+1;
    int newArr[nSize];

    //merge
    for(; f1<=l1 && f2<=l2; index++){
        if (arr[f1] < arr[f2]){
            newArr[index] = arr[f1];
            f1++;
        } else {
            newArr[index] = arr[f2];
            f2++;
        }
    }

    //empty both arrays
    for(; f1 <= l1; f1++, index++){
        newArr[index] = arr[f1];
    }
    for(; f2 <= l2; f2++, index++){
        newArr[index] = arr[f2];
    }

    //copy new array to int* arr
    for (index = first; index <= last; index++){
        arr[index] = newArr[index];
    }


}

void mergeSort(int *arr, const int size, int &compCount, int &moveCount){

    //delete
    int temp = 0;
    int mid;
    int first = 0;
    int last = size-1;
    int fSize;
    if (first < last){

        mid = size/2;
        fSize= mid - first;
        mergeSort(&arr[0], mid,  temp,temp);
        mergeSort(&arr[mid], size - mid,  temp,temp);

        merge(arr, 0, mid, last);
    }


}

void swap(int *a, int *b){
    int tempVal = *a;
    *a = *b;
    *b = tempVal;
}

void partition(int *arr, int first, int last, int& pivotIndex){
    int firstUnknownIndex = first+1;
    int S1LastIndex = first;

    while(firstUnknownIndex <= last){
        if (arr[firstUnknownIndex] > arr[pivotIndex]){
            firstUnknownIndex++;
        } else {
            swap(&arr[firstUnknownIndex], &arr[S1LastIndex+1]);
            S1LastIndex++;
            firstUnknownIndex++;
        }
    }

    //placing pivot in the middle
    while (pivotIndex < S1LastIndex){
        swap(&arr[pivotIndex], &arr[pivotIndex+1]);
        pivotIndex++;
    }
}

void quickSort(int *arr, const int size, int &compCount, int &moveCount){

    int pivotIndex = 0;
    int first = 0;
    int last = size - 1;

    if (first < last){
        partition(arr, first, last, pivotIndex);

        quickSort(&arr[0], pivotIndex, compCount, moveCount);
        quickSort(&arr[pivotIndex+1], size-pivotIndex-1, compCount, moveCount);
    }
}

void RadixSort(std::string *arr, const int size, int digit){

    if (digit >= 0){
        int count[ALPHABET_SIZE];
        int prefixSum[ALPHABET_SIZE];
        std::string output[size];
        int last = size-1;

        //init count and prefix
        for (int p = 0; p < ALPHABET_SIZE; p++) {
            count[p] = 0;
            prefixSum[p] = 0;
            if (p < size){
                output[p] = "-1";
            }
        }

        for(int i = 0; i <= last; i++){
            char ch[1];
            int u = i;
            std::strcpy(ch, arr[i].substr(digit,1).c_str());
            int digitValue = (int)ch[0];
            i = u;
            if (digitValue >= 48 && digitValue <= 57){
                count[digitValue-48]++;
            } else if (digitValue >= 65 && digitValue <= 90){
                count[digitValue-55]++;
            } else if (digitValue >= 97 && digitValue <= 122){
                count[digitValue-61]++;
            }
        }

        prefixSum[0] = count[0];
        for(int j = 1; j < ALPHABET_SIZE; j++){
            prefixSum[j] = count[j] + prefixSum[j-1];
        }

        for (int k = last; k >= 0; k--) {
            char ch[1];
            int u = k;
            std::strcpy(ch, arr[k].substr(digit,1).c_str());
            int digitValue = (int)*ch;
            k = u;
            if (digitValue >= 48 && digitValue <= 57){
                output[prefixSum[digitValue-48]-1] = arr[k];
            } else if (digitValue >= 65 && digitValue <= 90){
                output[prefixSum[digitValue-55]-1] = arr[k];
            } else if (digitValue >= 97 && digitValue <= 122){
                output[prefixSum[digitValue-61]-1] = arr[k];
            }
        }

        for(int l = 0; l < size; l++){
            arr[l] = output[l];
        }
        digit--;
        RadixSort(arr, size, digit);

    }
}