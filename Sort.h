//
//  Sort.h
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  Copyright (c) 2015 William Barham. All rights reserved.
//

#ifndef SORT_H
#define SORT_H

//Merge Sort, Quick Sort, Bubble Sort, Insertion Sort, Selection Sort in this file

//Merge Sort
void merge(int *arr, int lowerIndex, int middleIndex, int upperIndex);
void mergeSort(int *arr, int lowerIndex, int upperIndex);

//Bubble sort
void bubbleSort(int *array, int size);

//Insertion Sort
void insertionSort(int *array, int size);

//Selection Sort
void selectionSort(int *array, int size);

//Quick Sort
void quickSort(int *arr, int left, int right);

#endif
