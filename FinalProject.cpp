//
//  FinalProject.cpp
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  Copyright (c) 2015 William Barham. All rights reserved.
//

#include <iostream>
#include "Sort.h"
#include "Heap.h"
#include "TreeSort.h"
#include "FinalProject.h"

using namespace std;

//Heapsort functions
void checkHeapSort(int size)
{
    cout << "Heapsort:" << endl;
    
    int *array = new int[size];
    
    //Sort reverse order list
    createReverseOrderList(array, size);
    array = callHeapSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Reverse order list not sorted." << endl;
    }
    else
    {
        cout << "Reverse order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort in order list
    createInOrderList(array, size);
    array = callHeapSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "In order list not sorted." << endl;
    }
    else
    {
        cout << "In order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort random list
    createRandomList(array, size);
    array = callHeapSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Random list not sorted." << endl;
    }
    else
    {
        cout << "Random list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    delete [] array;
}

int *callHeapSort(int *arr, int size)
{
    Heap myHeap(arr, size);
    myHeap.heapSort();
    arr = myHeap.getArray();
    
    return arr;
}

//Treesort functions
void checkTreeSort(int size)
{
    cout << "Treesort:" << endl;
    
    int *array = new int[size];
    
    //Sort reverse order list
    createReverseOrderList(array, size);
    array = callTreeSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Reverse order list not sorted." << endl;
    }
    else
    {
        cout << "Reverse order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort in order list
    createInOrderList(array, size);
    array = callTreeSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "In order list not sorted." << endl;
    }
    else
    {
        cout << "In order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort random list
    createRandomList(array, size);
    array = callTreeSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Random list not sorted." << endl;
    }
    else
    {
        cout << "Random list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    delete [] array;
}

int *callTreeSort(int *arr, int size)
{
    Tree myTree(arr, size);
    arr = myTree.treeSort(arr);
    return arr;
}

//Merge sort functions
int *callMergeSort(int *arr, int size)
{
    mergeSort(arr, 0, size - 1);
    return arr;
}

void checkMergeSort(int size)
{
    cout << "Merge sort:" << endl;
        
    int *array = new int[size];
    
    //Sort reverse order list
    createReverseOrderList(array, size);
    array = callMergeSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Reverse order list not sorted." << endl;
    }
    else
    {
        cout << "Reverse order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort in order list
    createInOrderList(array, size);
    array = callMergeSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "In order list not sorted." << endl;
    }
    else
    {
    cout << "In order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort random list
    createRandomList(array, size);
    array = callMergeSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Random list not sorted." << endl;
    }
    else
    {
        cout << "Random list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    delete [] array;
}

int *callBubbleSort(int *arr, int size)
{
    bubbleSort(arr, size);
    return arr;
}

void checkBubbleSort(int size)
{
    cout << "Bubble sort:" << endl;
    
    int *array = new int[size];
    
    //Sort reverse order list
    createReverseOrderList(array, size);
    array = callBubbleSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Reverse order list not sorted." << endl;
    }
    else
    {
        cout << "Reverse order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort in order list
    createInOrderList(array, size);
    array = callBubbleSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "In order list not sorted." << endl;
    }
    else
    {
        cout << "In order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort random list
    createRandomList(array, size);
    array = callBubbleSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Random list not sorted." << endl;
    }
    else
    {
        cout << "Random list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    delete [] array;
}

//Insertion sort functions
int *callInsertionSort(int *arr, int size)
{
    insertionSort(arr, size);
    return arr;
}
void checkInsertionSort(int size)
{
    cout << "Insertion sort:" << endl;
    
    int *array = new int[size];
    
    //Sort reverse order list
    createReverseOrderList(array, size);
    array = callInsertionSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Reverse order list not sorted." << endl;
    }
    else
    {
        cout << "Reverse order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort in order list
    createInOrderList(array, size);
    array = callInsertionSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "In order list not sorted." << endl;
    }
    else
    {
        cout << "In order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort random list
    createRandomList(array, size);
    array = callInsertionSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Random list not sorted." << endl;
    }
    else
    {
        cout << "Random list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    delete [] array;
}

//Selection Sort Functions
int *callSelectionSort(int *arr, int size)
{
    selectionSort(arr, size);
    return arr;
}

void checkSelectionSort(int size)
{
    cout << "Selection sort:" << endl;
    
    int *array = new int[size];
    
    //Sort reverse order list
    createReverseOrderList(array, size);
    array = callSelectionSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Reverse order list not sorted." << endl;
    }
    else
    {
        cout << "Reverse order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort in order list
    createInOrderList(array, size);
    array = callSelectionSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "In order list not sorted." << endl;
    }
    else
    {
        cout << "In order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort random list
    createRandomList(array, size);
    array = callSelectionSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Random list not sorted." << endl;
    }
    else
    {
        cout << "Random list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    delete [] array;
}

//Quick sort functions
int *callQuickSort(int *arr, int size)
{
    quickSort(arr, 0, size - 1);
    return arr;
}

void checkQuickSort(int size)
{
    cout << "Quick sort:" << endl;
    
    int *array = new int[size];
    
    //Sort reverse order list
    createReverseOrderList(array, size);
    array = callQuickSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Reverse order list not sorted." << endl;
    }
    else
    {
        cout << "Reverse order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort in order list
    createInOrderList(array, size);
    array = callQuickSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "In order list not sorted." << endl;
    }
    else
    {
        cout << "In order list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    //Sort random list
    createRandomList(array, size);
    array = callQuickSort(array, size);
    if (!isSorted(array, size))
    {
        cout << "Random list not sorted." << endl;
    }
    else
    {
        cout << "Random list sorted." << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    delete [] array;
}

void createInOrderList(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
}

void createReverseOrderList(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = size - i;
    }
}

void createRandomList(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        double randomNum = rand() % size; //creates numbers between 0 and the array size
        arr[i] = randomNum;
    }
}

bool isSorted(int *arr, int size)
{
    bool sorted = true;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i-1])
        {
            sorted = false;
        }
    }
    return sorted;
}
