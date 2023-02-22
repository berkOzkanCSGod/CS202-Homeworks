//
// Created by Berk Ozkan on 8.02.2023.
//

#ifndef SORTINGT_SORTING_H
#define SORTINGT_SORTING_H

#include <iostream>
#include <string>

//std::srand(time(NULL));
struct Array {

    int size;
    int* array;
    int compCount, moveCount;

    Array(int otherSize)
        : size(otherSize), moveCount(0), compCount(0)
    {
        array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = rand() % 100 + 1;
        }
    }

    Array(const Array& other)
        : size(other.size), compCount(other.compCount), moveCount(other.moveCount)
    {
        array = new int[other.size];
        for (int i = 0; i < other.size; i++) {
            array[i] = other.array[i];
        }
    }

    ~Array(){
        delete[] array;
    }

    Array operator= (const Array& other){

        // Guard self assignment
        if (this == &other)
            return *this;

        delete[] array;              // release resource in *this
        array = new int[other.size];
        size = other.size;
        compCount = 0;
        moveCount = 0;

        for (int i = 0; i < other.size; i++)
            array[i] = other.array[i];

        return *this;
    }



};
struct Timer {

    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;

    Timer(){
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer(){
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout << " ^ Time it took: " << ms << "ms\n";

    }
};

void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
void merge (int *arr, int first, int mid, int last);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void swap(int *a, int *b);
void partition(int *arr, int first, int last, int& pivotIndex);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void RadixSort(std::string *arr, const int size, int digit);

std::ostream& operator<< (std::ostream& stream, const Array& array);



#endif //SORTINGT_SORTING_H
