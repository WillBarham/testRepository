//
//  FinalProject.h
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  CSCI 2270- Data Structures and Algorithms
//  Instructor: Hoenigman
//  Final Project

#ifndef FINAL_PROJECT_H
#define FINAL_PROJECT_H

enum sort {HEAPSORT = 1, TREESORT, MERGESORT, BUBBLESORT, INSERTIONSORT, SELECTIONSORT, QUICKSORT};

//Check sort
void checkSort(int size, int userInput);


void callHeapSort(int *arr, int size, int &counter);
void callTreeSort(int *arr, int size, int &counter);
void callMergeSort(int *arr, int size, int &counter);
void callQuickSort(int *arr, int size, int &counter);

//General Functions
void createReverseOrderList(int *arr, int size);
void createInOrderList(int *arr, int size);
void createRandomList(int *arr, int size);
bool isSorted(int *arr, int size);


#endif
