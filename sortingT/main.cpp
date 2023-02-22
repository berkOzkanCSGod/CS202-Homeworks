#include "sorting.h"
#include <chrono>

int main() {

    std::string stuff[3] = {"1", "2", "3"};
    int last = 3;

    for(int i = 0; i <= last; i++){
        char ch[1];
        int u = i;
        std::strcpy(ch, stuff[i].substr(0,1).c_str());
        i = u;
        int digitValue = (int)ch[0];

    }

//    int arrSize = 16;
//    Array array(arrSize);
//    Array arrayOrigin = array;

//    std::cout << array << std::endl;
//    std::cout << "Insertion sort: " << std::endl;
//    insertionSort(array.array, array.size, array.compCount, array.moveCount);
//    std::cout << "Insertion sort: " << std::endl;
//    std::cout << array << std::endl;

//    array = arrayOrigin;
//    std::cout << std::endl;

//    std::cout << array << std::endl;
//    std::cout << "Bubble sort: " << std::endl;
//    bubbleSort(array.array, array.size, array.compCount, array.moveCount);
//    std::cout << "Bubble sort: " << std::endl;
//    std::cout << array << std::endl;

//    array = arrayOrigin;
//    std::cout << std::endl;

//    std::cout << array << std::endl;
//    std::cout << "Merge sort: " << std::endl;
//    mergeSort(array.array, array.size, array.compCount, array.moveCount);
//    std::cout << array << std::endl;
//    std::cout << array << std::endl;
//    std::cout << "Quick sort: " << std::endl;
//    quickSort(array.array, array.size, array.compCount, array.moveCount);
//    std::cout << array << std::endl;

    return 0;
}
