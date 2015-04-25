//
//  FinalProject.h
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  Copyright (c) 2015 William Barham. All rights reserved.
//

#ifndef FINAL_PROJECT_H
#define FINAL_PROJECT_H

enum sort {HEAPSORT = 1, TREESORT, MERGESORT, BUBBLESORT, INSERTIONSORT, SELECTIONSORT, QUICKSORT};

//Check sort
void checkSort(int size, int userInput);

int *callHeapSort(int *arr, int size, int &counter);
int *callTreeSort(int *arr, int size, int &counter);
int *callMergeSort(int *arr, int size, int &counter);
int *callBubbleSort(int *arr, int size, int &counter);
int *callInsertionSort(int *arr, int size, int &counter);
int *callSelectionSort(int *arr, int size, int &counter);
int *callQuickSort(int *arr, int size, int &counter);

//General Functions
void createReverseOrderList(int *arr, int size);
void createInOrderList(int *arr, int size);
void createRandomList(int *arr, int size);
bool isSorted(int *arr, int size);

#endif
