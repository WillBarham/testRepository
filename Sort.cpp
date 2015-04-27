//
//  Sort.cpp
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  CSCI 2270- Data Structures and Algorithms
//  Instructor: Hoenigman
//  Final Project

#include "Sort.h"
#include <climits>
#include <iostream>

using namespace std;

/*
 * The following functions are all derived from the lecture notes
 * or psuedocode in the Cormen text.
 */

//Merge sort functions
/*
 1. Function prototype:
        void merge(int *array, int lowerIndex, int middleIndex, int upperIndex, int &counter);
 
 2. Function description:
        This takes in a range of indices in an array from lowerIndex to upperIndex 
        that are divided by middleIndex into two sorted subarrays. The function then
        selects the smaller of the first items in the two sorted subarrays to place 
        at the first index in the range. The method continues until all items in the
        subarrays are merged together into a single sorted array. This does not sort
        the entire array, but a subset of the array from lowerIndex to upperIndex.
 
 3. Example:
        merge(arr, lowerIndex, middleIndex, upperIndex, counter);
        // int *arr, int lowerIndex, int middleIndex, int upperIndex, and int counter
        // have all been previously defined.
 
 4. Precondition: 
        Counter is some value (based on how many loops have been encountered
        thus far in the sorting).
        arr is partitioned into two sorted subarrays in the range from lowerIndex
        to upperIndex. MiddleIndex is halfway between lowerIndex and uppwerIndex
        and divides the two subarrays.
    Postcondition: 
        Counter is incremented in each loop.
        arr is sorted in the range from lowerIndex to upperIndex.
 */
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
    left[first] = INT_MAX;   // These are sentinels. Nothing will ever exceed their values.
    right[second] = INT_MAX; // They mark the end of the arrays.
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

/*
 1. Function prototype:
    mergeSort(int *arr, int lowerIndex, int upperIndex, int &counter);
 
 2. Function description:
    An array is given, and its lower index and upper index are also given. This is 
    a recursive function, so in the first call, the lower index is zero, and the upper
    is size - 1. As the function recurses, it is run on smaller and smaller subarrays.
    It bottoms out when the arrays are of size 1. The merge function then recombines 
    the arrays and, in the process, sorts the array.
 
 3. Example:
    mergeSort(arr, 0, size - 1, counter); //For first call
    mergeSort(arr, lowerIndex, middleIndex, counter); //One of its recursive calls
 
 4. Precondition:
        The array is unsorted. The counter = 0.
    
    Postcondition:
        The array is sorted, and the counter gives a rough measure of the time it took
        to sort the array.
 
 */
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
/*
 1. Function prototype:
    void quickSort(int *arr, int left, int right, int &counter);
 
 2. Function description:
    This function is an implementation of quickSort. In fact, it is almost
    identical to the quick sort from the lecture notes. It is a little 
    complicated to describe, so I refer you to the lecture notes for a 
    complete description. 
 
    Rough description: The pivot is selected to be in the middle, and
    the indices i and j move from the right and left until they find values
    on the wrong side of the pivot. The values are exchanged. Once i and j
    pass each other, the function recursively calls itself. This continues
    until i and j pass the left and right indices.
 
 3. Example:
    quickSort(array, 0, size - 1, counter); //This is the original call
    quickSort(arr, left, j, counter); // A recursive call from inside quickSort
 
 4. Precondition:
        Before calling quickSort, the array is unsorted and counter = 0.
 
    Postcondition:
        After calling quickSort, the array is sorted, and the counter gives
        a rough measure of the time it took to sort the array.
 */
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
/*
 1. Function prototype:
    void insertionSort(int *array, int size, int &counter);
 
 2. Function description:
    Starting at the second index in the array and continuing this procedure for all
    following indices in the array, we move backward through the array, and if any 
    preceeding elements are greater than the starting value, we exchange the values.
 
    The lecture notes give a more complete explanation of this algorithm.
 
 3. Example:
    insertionSort(array, size, counter);
 
 4. Precondition:
        Initially the array is unsorted, and counter = 0;
 
    Postcondition:
        After insertionSort is called, the array is sorted, and counter gives
        a rough measure of the time it took to sort the array.
 
 */
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
/*
 1. Function prototype:
    void selectionSort(int *array, int size, int &counter);
 
 2. Function description:
    Again, the lecture notes probably are your best bet to really understand
    this sorting algorithm, but I'll do my best to explain.
    
    Selection starts at the beginning of the array, and compares the value of each
    element of the array with all its successors. The smallest element encountered
    is selected, and if this element is not the one we started with, we swap the values
    of the starting index, and the index of the smallest value. This involves a nested
    for loop, so the operation is O(n^2).
 
 3. Example:
    selectionSort(array, size, counter);
 
 4. Precondition:
        The array is unsorted, and counter = 0.
 
    Postcondition:
        The array is sorted, and counter gives a rough estimate of the time it
        took to sort the array.
 */
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
/*
 1. Function prototype:
    void bubbleSort(int *array, int size, int &counter);
 
 2. Function description:
    Starting at the beginning of the array, we check the value of each item in the
    array against its successor. If the successor is smaller, then we switch values.
    Once we get to index (size - starting index - 1), we repeat, but this time starting from the
    second index. This continues until the second to last index.
 
    The lecture notes give a more complete description of this algorithm.
 
 3. Example:
    bubbleSort(array, size, counter);
 
 4. Precondition:
    Initially the array is unsorted, and counter = 0;
 
 Postcondition:
    After insertionSort is called, the array is sorted, and counter gives
    a rough measure of the time it took to sort the array.
 */
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

