//
//  Sort.h
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  CSCI 2270- Data Structures and Algorithms
//  Instructor: Hoenigman
//  Final Project

#ifndef SORT_H
#define SORT_H

//Merge Sort
void merge(int *arr, int lowerIndex, int middleIndex, int upperIndex, int &counter);
void mergeSort(int *arr, int lowerIndex, int upperIndex, int &counter);

//Bubble sort
void bubbleSort(int *array, int size, int &counter);

//Insertion Sort
void insertionSort(int *array, int size, int &counter);

//Selection Sort
void selectionSort(int *array, int size, int &counter);

//Quick Sort
void quickSort(int *arr, int left, int right, int &counter);

#endif
