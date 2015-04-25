//
//  FinalProject.h
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  Copyright (c) 2015 William Barham. All rights reserved.
//

#ifndef FINAL_PROJECT_H
#define FINAL_PROJECT_H

//Heapsort functions
int *callHeapSort(int *arr, int size);
void checkHeapSort(int size);

//Treesort functions
int *callTreeSort(int *arr, int size);
void checkTreeSort(int size);

//Merge sort functions
int *callMergeSort(int *arr, int size);
void checkMergeSort(int size);

//Bubble sort functions
int *callBubbleSort(int *arr, int size);
void checkBubbleSort(int size);

//Insertion sort functions
int *callInsertionSort(int *arr, int size);
void checkInsertionSort(int size);

//Selection sort functions
int *callSelectionSort(int *arr, int size);
void checkSelectionSort(int size);

//Quick sort functions
int *callQuickSort(int *arr, int size);
void checkQuickSort(int size);

//General Functions
void createReverseOrderList(int *arr, int size);
void createInOrderList(int *arr, int size);
void createRandomList(int *arr, int size);
bool isSorted(int *arr, int size);

#endif
