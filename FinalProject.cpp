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

enum sort;

void checkSort(int size, int sort)
{
    int *array = new int[size];
    int *secondArray = new int[size];
    int *thirdArray = new int[size];
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    createReverseOrderList(array, size);
    createInOrderList(secondArray, size);
    createRandomList(thirdArray, size);
    
    cout << endl;
    if (sort == HEAPSORT)
    {
        cout << "Heapsort: " << endl;
        callHeapSort(array, size, counter1);
        callHeapSort(secondArray, size, counter2);
        callHeapSort(thirdArray, size, counter3);
    }
    else if (sort == TREESORT)
    {
        cout << "Treesort: " << endl;
        callTreeSort(array, size, counter1);
        callTreeSort(secondArray, size, counter2);
        callTreeSort(thirdArray, size, counter3);
    }
    else if (sort == MERGESORT)
    {
        cout << "Mergesort: " << endl;
        callMergeSort(array, size, counter1);
        callMergeSort(secondArray, size, counter2);
        callMergeSort(thirdArray, size, counter3);
    }
    else if (sort == BUBBLESORT)
    {
        cout << "Bubblesort: " << endl;
        callBubbleSort(array, size, counter1);
        callBubbleSort(secondArray, size, counter2);
        callBubbleSort(thirdArray, size, counter3);
    }
    else if (sort == INSERTIONSORT)
    {
        cout << "Insertion Sort: " << endl;
        callInsertionSort(array, size, counter1);
        callInsertionSort(secondArray, size, counter2);
        callInsertionSort(thirdArray, size, counter3);
    }
    else if (sort == SELECTIONSORT)
    {
        cout << "Selection Sort: " << endl;
        callSelectionSort(array, size, counter1);
        callSelectionSort(secondArray, size, counter2);
        callSelectionSort(thirdArray, size, counter3);
    }
    else if (sort == QUICKSORT)
    {
        cout << "Quicksort: " << endl;
        callQuickSort(array, size, counter1);
        callQuickSort(secondArray, size, counter2);
        callQuickSort(thirdArray, size, counter3);
    }

    //array is reverse order array
    if (!isSorted(array, size))
    {
        cout << "Reverse order list not sorted." << endl;
    }
    else
    {
        cout << "Reverse order list sorted." << endl;
        cout << "Count = " << counter1 << endl;
    }
    cout << "Sorted list: " << endl;
    if (size <= 10)
    {
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            cout << array[i] << " ";
        }
        cout << "... ";
        for (int i = 0; i < 5; i++)
        {
            cout << array[size - 5 + i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //secondArray is the reverse order array
    if (!isSorted(secondArray, size))
    {
        cout << "In order list not sorted." << endl;
    }
    else
    {
        cout << "In order list sorted." << endl;
        cout << "Count = " << counter2 << endl;
    }
    cout << "Sorted list: " << endl;
    if (size <= 10)
    {
        for (int i = 0; i < size; i++)
        {
            cout << secondArray[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            cout << secondArray[i] << " ";
        }
        cout << "... ";
        for (int i = 0; i < 5; i++)
        {
            cout << secondArray[size - 5 + i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //thirdArray is random order array
    if (!isSorted(thirdArray, size))
    {
        cout << "Random list not sorted." << endl;
    }
    else
    {
        cout << "Random list sorted." << endl;
        cout << "Counter = " << counter3 << endl;
    }
    cout << "Sorted list: " << endl;
    if (size <= 10)
    {
        for (int i = 0; i < size; i++)
        {
            cout << thirdArray[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            cout << thirdArray[i] << " ";
        }
        cout << "... ";
        for (int i = 0; i < 5; i++)
        {
            cout << thirdArray[size - 5 + i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //free memory
    delete [] array;
    delete [] secondArray;
    delete [] thirdArray;
}

int *callHeapSort(int *arr, int size, int &counter)
{
    Heap myHeap(arr, size);
    myHeap.heapSort();
    arr = myHeap.getArray();
    counter = myHeap.getCounter();
    
    return arr;
}

int *callTreeSort(int *arr, int size, int &counter)
{
    Tree myTree(arr, size);
    arr = myTree.treeSort(arr);
    counter = myTree.getCounter();
    
    return arr;
}

int *callMergeSort(int *arr, int size, int &counter)
{
    mergeSort(arr, 0, size - 1, counter);
    return arr;
}

int *callBubbleSort(int *arr, int size, int &counter)
{
    bubbleSort(arr, size, counter);
    return arr;
}

int *callInsertionSort(int *arr, int size, int &counter)
{
    insertionSort(arr, size, counter);
    return arr;
}

int *callSelectionSort(int *arr, int size, int &counter)
{
    selectionSort(arr, size, counter);
    return arr;
}

int *callQuickSort(int *arr, int size, int &counter)
{
    quickSort(arr, 0, size - 1, counter);
    return arr;
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
