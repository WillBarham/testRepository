//
//  FinalProject.cpp
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  CSCI 2270- Data Structures and Algorithms
//  Instructor: Hoenigman
//  Final Project

#include <iostream>
#include "Sort.h"
#include "Heap.h"
#include "TreeSort.h"
#include "FinalProject.h"

using namespace std;

enum sort;

/*
 1. Function prototype:
    void checkSort(int size, int sort);

 2. Function description:
    This function is by far the largest, and is the only function called from the driver.
    It takes in a number for the array size the user wants sorted, and a number that
    corresponds to which sort is to be implemented. To make the program more legible, the
    input number corresponds with the function name as defined in "enum sort" in the
    header file.

    Three arrays and counters are created. The arrays are of the input size, and the counters
    correspond to each array. The first array is built to be a reverse order array using a
    helper function. The second is an in order array. The third is a random order array.

    The desired sorting function is then applied to each array. The three counters are passed
    into the functions to give a general measure of the efficiency of the sort.

    Then, for each array, the function prints whether the array was properly sorted
    (a helper function checks), the count from that sort is printed, and the sorted
    array is printed (if the size exceeds 10, ellipses are used and the first 5 and
    last 5 elements are printed).

 3. Example:
    checkSort(size, userInput); //size is array size, userInput is the desired sort

 4. Precondition:
        Size and userInput given by the user are passed into the function.

    Postcondition:
        Neither size nor userInput are changed. The function prints the gathered info, and
        deletes everything created inside the function.
 */
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
        bubbleSort(array, size, counter1);
        bubbleSort(secondArray, size, counter2);
        bubbleSort(thirdArray, size, counter3);
    }
    else if (sort == INSERTIONSORT)
    {
        cout << "Insertion Sort: " << endl;
        insertionSort(array, size, counter1);
        insertionSort(secondArray, size, counter2);
        insertionSort(thirdArray, size, counter3);
    }
    else if (sort == SELECTIONSORT)
    {
        cout << "Selection Sort: " << endl;
        selectionSort(array, size, counter1);
        selectionSort(secondArray, size, counter2);
        selectionSort(thirdArray, size, counter3);
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

/*
 1. Function prototype:
    void callHeapSort(int *arr, int size, int &counter);

 2. Function description:
    This function creates a heap, calls heapsort, and sets the counter equal to the
    counter in the class. The input array is sorted once this function finishes.

 3. Example:
    callHeapSort(array, size, counter); //This is only ever called in checkSort.

 4. Precondition:
        An unsorted array, its size, and a counter = 0 are entered.

    Postcondition:
        The array is sorted, its size is unchanged, and the counter has been added to
        so that it roughly measures how long the sort took.
 */
void callHeapSort(int *arr, int size, int &counter)
{
    Heap myHeap(arr, size);
    myHeap.heapSort();
    counter = myHeap.getCounter();
}

/*
 1. Function prototype:
    void callTreeSort(int *arr, int size, int &counter);

 2. Function description:
    This function creates a Tree from the input array, sorts the tree and sets the array
    to the sort tree function (which returns an array), and gets the counts from the sort.

 3. Example:
    callTreeSort(array, size, counter); //This is only ever called in checkSort.

 4. Precondition:
        An unsorted array, its size, and a counter = 0 are entered.

    Postcondition:
        The array is sorted, its size is unchanged, and the counter has been added to
        so that it roughly measures how long the sort took.
 */
void callTreeSort(int *arr, int size, int &counter)
{
    Tree myTree(arr, size);
    arr = myTree.treeSort(arr);
    counter = myTree.getCounter();
}

/*
 1. Function prototype:
    void callMergeSort(int *arr, int size, int &counter);

 2. Function description:
    This function calls merge sort from the info provided by the user.
    The array is sorted after this function is called.

 3. Example:
    callMergeSort(array, size, counter); //This is only ever called in checkSort

 4. Precondition:
        An unsorted array, its size, and a counter = 0 are entered.

    Postcondition:
        The array is sorted, its size is unchanged, and the counter has been added to
        so that it roughly measures how long the sort took.
 */
void callMergeSort(int *arr, int size, int &counter)
{
    mergeSort(arr, 0, size - 1, counter);
}

/*
 1. Function prototype:
    void callQuickSort(int *arr, int size, int &counter);

 2. Function description:
    This function calls quick sort from the info provided by the user.
    The array is sorted after this function is called.

 3. Example:
    callQuickSort(array, size, counter); //This is only ever called in CheckSort

 4. Precondition:
        An unsorted array, its size, and a counter = 0 are entered.

    Postcondition:
        The array is sorted, its size is unchanged, and the counter has been added to
        so that it roughly measures how long the sort took.
 */
void callQuickSort(int *arr, int size, int &counter)
{
    quickSort(arr, 0, size - 1, counter);
}

/*
 * The following three functions are all essentially the same. Their
 * functionallity is really simple. They take in an empty array and
 * the size of that array, and fill the array in a way specified by
 * their name.
 */
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
        int randomNum = rand() % size; //creates numbers between 0 and the array size
        arr[i] = randomNum;
    }
}

/*
 * This is another simple helper function. I didn't think it was big enough to merit
 * the whole specified comment block applied to significant functions. It checks if an
 * input array of input size is sorted. It starts by assuming the array is sorted, and
 * if any element is smaller than the element before it, the boolean is switched to false.
 * The test fails if all elements in the array are the same. That is why I also print the
 * sorted array in the checkSort function. This is only called in checkSort.
 */
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





