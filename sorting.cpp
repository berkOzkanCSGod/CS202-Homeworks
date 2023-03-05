//
// Created by Berk Ozkan on 5.03.2023.
//



void swap(int& a, int& b, int& moveCount){
    int tempVal = a;
    a = b;
    b = tempVal;
    moveCount += 3;
}

void insertionSort(int *arr, const int size, int &compCount, int &moveCount){

    for (int i = 1; i < size; i++) {
        int j = i;
        compCount += 1; // comparison from while
        while (arr[j] < arr[j-1]){
            compCount += 1; // comparison from while
            swap(arr[j], arr[j-1], moveCount);
            j--;
        }
    }

}

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount){

    int unsortedPos = size;
    while (unsortedPos != 0){

        for (int i = 0; i < unsortedPos-1; i++) {

            compCount += 1; // comparison from while
            while (arr[i] > arr[i + 1] && i < unsortedPos) {

                compCount += 1; // comparison from while
                swap(arr[i], arr[i+1], moveCount);

            }

        }
        unsortedPos--;
    }
}

void merge (int* arr, int first, int mid, int last, int& compCount, int&moveCount){

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
            newArr[index] = arr[f1]; moveCount++;
            f1++;
        } else {
            newArr[index] = arr[f2]; moveCount++;
            f2++;
        } compCount++;

    }

    //empty both arrays
    for(; f1 <= l1; f1++, index++){
        newArr[index] = arr[f1]; moveCount++;
    }
    for(; f2 <= l2; f2++, index++){
        newArr[index] = arr[f2]; moveCount++;
    }

    //copy new array to int* arr
    for (index = first; index <= last; index++){
        arr[index] = newArr[index]; moveCount++;
    }
}

void mergeSort(int *arr, const int size, int &compCount, int &moveCount){

    int mid;
    int first = 0;
    int last = size-1;

    if (first < last){

        mid = size/2;
        mergeSort(&arr[0], mid,  compCount,moveCount);
        mergeSort(&arr[mid], size - mid,  compCount,moveCount);

        merge(arr, 0, mid, last, compCount, moveCount);
    }
}


void partition(int *arr, int first, int last, int& pivotIndex, int& compCount, int& moveCount){

    int firstUnknownIndex = first+1;
    int S1LastIndex = first;

    while(firstUnknownIndex <= last){
        if (arr[firstUnknownIndex] > arr[pivotIndex]){
            firstUnknownIndex++;
        } else {
            swap(arr[firstUnknownIndex], arr[S1LastIndex+1], moveCount);
            S1LastIndex++;
            firstUnknownIndex++;
        } compCount++;
    }

    //placing pivot in the middle
    while (pivotIndex < S1LastIndex){
        swap(arr[pivotIndex], arr[pivotIndex+1], moveCount);
        pivotIndex++;
    }
}

void quickSort(int *arr, const int size, int &compCount, int &moveCount){

    int pivotIndex = 0;
    int first = 0;
    int last = size - 1;

    if (first < last){
        partition(arr, first, last, pivotIndex, compCount, moveCount);

        quickSort(&arr[0], pivotIndex, compCount, moveCount);
        quickSort(&arr[pivotIndex+1], size-pivotIndex-1, compCount, moveCount);
    }
}

void hybridSort(int *arr, const int size, int &compCount, int &moveCount){
    int pivotIndex = 0;
    int first = 0;
    int last = size - 1;

    if (first < last && last-first > 20){
        partition(arr, first, last, pivotIndex, compCount, moveCount);

        hybridSort(&arr[0], pivotIndex, compCount, moveCount);
        hybridSort(&arr[pivotIndex+1], size-pivotIndex-1, compCount, moveCount);
    } else {
        bubbleSort(&arr[0], size, compCount, moveCount);
    }
}

void reverseArr(int* arr, const int size){

    int* temp = new int[size];
    for (int i = 0; i < size; ++i) {
        temp[i] = arr[i];
    }
    for (int j = 0; j < size; j++) {
        arr[j] = temp[size-1-j];
    }
    delete[] temp;
}