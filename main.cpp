#include <iostream>
#include "sorting.h"
#include <ctime>
#include <math.h>

int main() {

    int dataSet[4] = {1000,5000,10000,20000};
    int dataSetSize = 4;

    int InsertionCompCount = 0; int InsertionMoveCount = 0;
    int BubbleCompCount = 0; int BubbleMoveCount = 0;
    int MergeCompCount = 0; int MergeMoveCount = 0;
    int QuickCompCount = 0; int QuickMoveCount = 0;
    int HybridCompCount = 0; int HybridMoveCount = 0;

    clock_t InsertionTime;
    clock_t BubbleTime;
    clock_t MergeTime;
    clock_t QuickTime;
    clock_t HybridTime;


    int groupSize;
    int c = 0, m = 0; //temp place holders

    printf("%70s" , "Part 2-b-1: Performance analysis of random integers array\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(" %35s %20s %20s\n", "Elapsed time(ms)", "Comp. count", "Move count");

    //rand array
    for(int i = 0; i < dataSetSize; i++){

        int size = dataSet[i];

//        int* InsertionRand =  new int[size];
//         InsertionCompCount = 0;  InsertionMoveCount = 0;
//        int* BubbleRand =  new int[size];
//         BubbleCompCount = 0;  BubbleMoveCount = 0;
//        int* MergeRand =  new int[size];
//         MergeCompCount = 0;  MergeMoveCount = 0;
//        int* QuickRand =  new int[size];
//         QuickCompCount = 0;  QuickMoveCount = 0;
//        int* HybridRand =  new int[size];
//         HybridCompCount = 0;  HybridMoveCount = 0;

        int InsertionRand[size];
         InsertionCompCount = 0;  InsertionMoveCount = 0;
        int BubbleRand[size];
         BubbleCompCount = 0;  BubbleMoveCount = 0;
        int MergeRand[size];
         MergeCompCount = 0;  MergeMoveCount = 0;
        int QuickRand[size];
         QuickCompCount = 0;  QuickMoveCount = 0;
        int HybridRand[size];
         HybridCompCount = 0;  HybridMoveCount = 0;

         for(int j = 0; j < size; j++){
             int randNumber = rand() % 20000 + 1;
             InsertionRand[j] = randNumber;
             BubbleRand[j] = randNumber;
             MergeRand[j] = randNumber;
             QuickRand[j] = randNumber;
             HybridRand[j] = randNumber;
         }

        InsertionTime = clock();
        insertionSort(InsertionRand, size, InsertionCompCount, InsertionMoveCount);
        InsertionTime = clock() - InsertionTime;
        BubbleTime = clock();
        bubbleSort(BubbleRand, size, BubbleCompCount, BubbleMoveCount);
        BubbleTime = clock() - BubbleTime;
        MergeTime = clock();
        mergeSort(MergeRand, size, MergeCompCount, MergeMoveCount);
        MergeTime = clock() - MergeTime;
        QuickTime = clock();
        quickSort(QuickRand, size, QuickCompCount, QuickMoveCount);
        QuickTime = clock() - QuickTime;
        HybridTime = clock();
        hybridSort(HybridRand, size, HybridCompCount, HybridMoveCount);
        HybridTime = clock() - HybridTime;

        //printing table
        printf("Array Size: %4i\n", size);
        printf("%-20s %15f %20i %20i\n", "Insertion Sort", ((float)InsertionTime/CLOCKS_PER_SEC)*1000, InsertionCompCount, InsertionMoveCount);
        printf("%-20s %15f %20i %20i\n", "Bubble Sort", ((float)BubbleTime/CLOCKS_PER_SEC)*1000, BubbleCompCount, BubbleMoveCount);
        printf("%-20s %15f %20i %20i\n", "Merge Sort", ((float)MergeTime/CLOCKS_PER_SEC)*1000, MergeCompCount, MergeMoveCount);
        printf("%-20s %15f %20i %20i\n", "Quick Sort", ((float)QuickTime/CLOCKS_PER_SEC)*1000, QuickCompCount, QuickMoveCount);
        printf("%-20s %15f %20i %20i\n", "Hybrid Sort", ((float)HybridTime/CLOCKS_PER_SEC)*1000, HybridCompCount, HybridMoveCount);
        printf("\n");

//        delete[] InsertionRand;
//        delete[] BubbleRand;
//        delete[] MergeRand;
//        delete[] QuickRand;
//        delete[] HybridRand;


    }

    printf("%70s" , "Part 2-b-2: Performance analysis of random integers array\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(" %35s %20s %20s\n", "Elapsed time(ms)", "Comp. count", "Move count");

    for(int i = 0; i < dataSetSize; i++){

        int size = dataSet[i];
        groupSize = log2(dataSet[i]);

        int InsertionAs[size];
        InsertionCompCount = 0;  InsertionMoveCount = 0;
        int BubbleAs[size];
        BubbleCompCount = 0;  BubbleMoveCount = 0;
        int MergeAs[size];
        MergeCompCount = 0;  MergeMoveCount = 0;
        int QuickAs[size];
        QuickCompCount = 0;  QuickMoveCount = 0;
        int HybridAs[size];
        HybridCompCount = 0;  HybridMoveCount = 0;

        for(int j = 0; j < size; j++){
            int randNumber = rand() % 20000 + 1;
            InsertionAs[j] = randNumber;
            BubbleAs[j] = randNumber;
            MergeAs[j] = randNumber;
            QuickAs[j] = randNumber;
            HybridAs[j] = randNumber;
        }
        hybridSort(InsertionAs, size,c,m);
        hybridSort(BubbleAs, size,c,m);
        hybridSort(MergeAs, size,c,m);
        hybridSort(QuickAs, size,c,m);
        hybridSort(HybridAs, size,c,m);

        //scramble array
        for(int l = 0; l < size; l += groupSize){
            for (int k = l; k < l + groupSize/2+1; k++) {
                int rn = rand() % groupSize;
                if (k + rn < size){
                    swap(InsertionAs[k], InsertionAs[k + rn],m);
                }
            }
        }


        InsertionTime = clock();
        insertionSort(InsertionAs, size, InsertionCompCount, InsertionMoveCount);
        InsertionTime = clock() - InsertionTime;
        BubbleTime = clock();
        bubbleSort(BubbleAs, size, BubbleCompCount, BubbleMoveCount);
        BubbleTime = clock() - BubbleTime;
        MergeTime = clock();
        mergeSort(MergeAs, size, MergeCompCount, MergeMoveCount);
        MergeTime = clock() - MergeTime;
        QuickTime = clock();
        quickSort(QuickAs, size, QuickCompCount, QuickMoveCount);
        QuickTime = clock() - QuickTime;
        HybridTime = clock();
        hybridSort(HybridAs, size, HybridCompCount, HybridMoveCount);
        HybridTime = clock() - HybridTime;

        //printing table
        printf("Array Size: %4i\n", dataSet[i]);
        printf("%-20s %15f %20i %20i\n", "Insertion Sort", ((float)InsertionTime/CLOCKS_PER_SEC)*1000, InsertionCompCount, InsertionMoveCount);
        printf("%-20s %15f %20i %20i\n", "Bubble Sort", ((float)BubbleTime/CLOCKS_PER_SEC)*1000, BubbleCompCount, BubbleMoveCount);
        printf("%-20s %15f %20i %20i\n", "Merge Sort", ((float)MergeTime/CLOCKS_PER_SEC)*1000, MergeCompCount, MergeMoveCount);
        printf("%-20s %15f %20i %20i\n", "Quick Sort", ((float)QuickTime/CLOCKS_PER_SEC)*1000, QuickCompCount, QuickMoveCount);
        printf("%-20s %15f %20i %20i\n", "Hybrid Sort", ((float)HybridTime/CLOCKS_PER_SEC)*1000, HybridCompCount, HybridMoveCount);
        printf("\n");

//        delete[] InsertionAs;
//        delete[] BubbleAs;
//        delete[] MergeAs;
//        delete[] QuickAs;
//        delete[] HybridAs;


    }

    printf("%70s" , "Part 2-b-3: Performance analysis of random integers array\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(" %35s %20s %20s\n", "Elapsed time(ms)", "Comp. count", "Move count");

    for(int i = 0; i < dataSetSize; i++){

        int size = dataSet[i];
        groupSize = log2(dataSet[i]);

        int InsertionDs[size];
        InsertionCompCount = 0;  InsertionMoveCount = 0;
        int BubbleDs[size];
        BubbleCompCount = 0;  BubbleMoveCount = 0;
        int MergeDs[size];
        MergeCompCount = 0;  MergeMoveCount = 0;
        int QuickDs[size];
        QuickCompCount = 0;  QuickMoveCount = 0;
        int HybridDs[size];
        HybridCompCount = 0;  HybridMoveCount = 0;

        for(int j = 0; j < size; j++){
            int randNumber = rand() % 20000 + 1;
            InsertionDs[j] = randNumber;
            BubbleDs[j] = randNumber;
            MergeDs[j] = randNumber;
            QuickDs[j] = randNumber;
            HybridDs[j] = randNumber;
        }
        hybridSort(InsertionDs, size,c,m);
        hybridSort(BubbleDs, size,c,m);
        hybridSort(MergeDs, size,c,m);
        hybridSort(QuickDs, size,c,m);
        hybridSort(HybridDs, size,c,m);

        //reverse arr
        reverseArr(InsertionDs, size);
        reverseArr(BubbleDs, size);
        reverseArr(MergeDs, size);
        reverseArr(QuickDs, size);
        reverseArr(HybridDs, size);

        //scramble array
        for(int l = 0; l < size; l += groupSize){
            for (int k = l; k < l + groupSize/2+1; k++) {
                int rn = rand() % groupSize;
                if (k + rn < size){
                    swap(InsertionDs[k], InsertionDs[k + rn],m);
                    swap(BubbleDs[k], InsertionDs[k + rn],m);
                    swap(MergeDs[k], InsertionDs[k + rn],m);
                    swap(QuickDs[k], InsertionDs[k + rn],m);
                    swap(HybridDs[k], InsertionDs[k + rn],m);
                }
            }
        }

        InsertionTime = clock();
        insertionSort(InsertionDs, size, InsertionCompCount, InsertionMoveCount);
        InsertionTime = clock() - InsertionTime;
        BubbleTime = clock();
        bubbleSort(BubbleDs, size, BubbleCompCount, BubbleMoveCount);
        BubbleTime = clock() - BubbleTime;
        MergeTime = clock();
        mergeSort(MergeDs, size, MergeCompCount, MergeMoveCount);
        MergeTime = clock() - MergeTime;
        QuickTime = clock();
        quickSort(QuickDs, size, QuickCompCount, QuickMoveCount);
        QuickTime = clock() - QuickTime;
        HybridTime = clock();
        hybridSort(HybridDs, size, HybridCompCount, HybridMoveCount);
        HybridTime = clock() - HybridTime;

        //printing table
        printf("Array Size: %4i\n", size);
        printf("%-20s %15f %20i %20i\n", "Insertion Sort", ((float)InsertionTime/CLOCKS_PER_SEC)*1000, InsertionCompCount, InsertionMoveCount);
        printf("%-20s %15f %20i %20i\n", "Bubble Sort", ((float)BubbleTime/CLOCKS_PER_SEC)*1000, BubbleCompCount, BubbleMoveCount);
        printf("%-20s %15f %20i %20i\n", "Merge Sort", ((float)MergeTime/CLOCKS_PER_SEC)*1000, MergeCompCount, MergeMoveCount);
        printf("%-20s %15f %20i %20i\n", "Quick Sort", ((float)QuickTime/CLOCKS_PER_SEC)*1000, QuickCompCount, QuickMoveCount);
        printf("%-20s %15f %20i %20i\n", "Hybrid Sort", ((float)HybridTime/CLOCKS_PER_SEC)*1000, HybridCompCount, HybridMoveCount);
        printf("\n");

//        delete[] InsertionDs;
//        delete[] BubbleDs;
//        delete[] MergeDs;
//        delete[] QuickDs;
//        delete[] HybridDs;

    }




//    insertionSort(arr, size, compCount, moveCount);
//    bubbleSort(arr, size, compCount, moveCount);
//    mergeSort(arr, size, compCount, moveCount);
//    quickSort(arr, size, compCount, moveCount);
//    hybridSort(arr, size, compCount, moveCount);

    return 0;
}
