//
//  Sort.cpp
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  Copyright (c) 2015 William Barham. All rights reserved.
//

#include "Sort.h"
#include <climits>
#include <iostream>

using namespace std;

//Merge sort functions
void merge(int *arr, int lowerIndex, int middleIndex, int upperIndex, int &counter)
{
    int first = middleIndex - lowerIndex + 1;
    int second = upperIndex - middleIndex;
    int left[first + 1];
    int right[second + 1];
    int i, j;
    for (i = 0; i < first; i++)
    {
        left[i] = arr[lowerIndex + i];
        counter++;
    }
    for (j = 0; j < second; j++)
    {
        right[j] = arr[middleIndex + j + 1];
        counter++;
    }
    left[first] = INT_MAX;
    right[second] = INT_MAX;
    i = 0;
    j = 0;
    for (int k = lowerIndex; k <= upperIndex; k++)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        counter++;
    }
}

void mergeSort(int *arr, int lowerIndex, int upperIndex, int &counter)
{
    if (lowerIndex < upperIndex)
    {
        int middleIndex = ((lowerIndex + upperIndex)/2);
        mergeSort(arr, lowerIndex, middleIndex, counter);
        mergeSort(arr, middleIndex + 1, upperIndex, counter);
        merge(arr, lowerIndex, middleIndex, upperIndex, counter);
        counter++;
    }
}

//Quicksort function
void quickSort(int *arr, int left, int right, int &counter)
{
    int i = left;
    int j = right;
    int temp;
    int pivot = arr[(left + right) / 2];
    while(i <= j)
    {
        counter++;
        while(arr[i] < pivot)
        {
            counter++;
            i++;
        }
        while(arr[j] > pivot)
        {
            counter++;
            j--;
        }
        if(i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j)
    {
        counter++;
        quickSort(arr, left, j, counter);
    }
    if (i < right)
    {
        counter++;
        quickSort(arr, i, right, counter);
    }
}

//Insertion sort function
void insertionSort(int *array, int size, int &counter)
{
    int index, j;
    for(int i = 1; i < size; i++)
    {
        counter++;
        index = array[i];
        j = i;
        while((j > 0) && (array[j - 1] > index))
        {
            counter++;
            array[j] = array[j - 1];
            j = j - 1;
        }
        array[j] = index;
    }
}

//Selection sort function
void selectionSort(int *array, int size, int &counter)
{
    int minIndex;
    int temp;
    for(int i = 0; i < size - 1; i++)
    {
        counter++;
        minIndex = i;
        for(int j = i + 1; j < size; j++)
        {
            counter++;
            if(array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

//Bubble sort function
void bubbleSort(int *array, int size, int &counter)
{
    int temp;
    for(int i = 0; i < size - 1; i++)
    {
        counter++;
        for(int j = 0; j < size - i - 1; j++)
        {
            counter++;
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

