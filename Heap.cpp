//
//  Heap.cpp
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  CSCI 2270- Data Structures and Algorithms
//  Instructor: Hoenigman
//  Final Project

#include <iostream>
#include "Heap.h"

using namespace std;

/*
 * For a better description of the heap structure and heapsort,
 * I recommend reading pages 151-162 int the Cormen text. I will
 * do my best to explain heaps and heapsort, but the Cormen text
 * certainly would explain it better than I can.
 *
 * I based the following functions on the pseudocode found in the
 * heap section of the Cormen text.
 *
 * Also note that although the heap is a tree data structure,
 * I have implemented this tree as an array rather than nodes
 * with references. Again, the Cormen text explains how this
 * works really well.
 */

/*
 1. Function prototype:
        Heap::Heap(int *arr, int size);
 
 2. Function description:
        An array and its size are passed in as parameters. A pointer to the
        array is set, and the array and its size are passed into the buildMaxHeap
        method.
 
 3. Example:
        Heap myHeap(arr, size); // Just the way you typically call a
                                // constructor with input values
 4. Precondition:
        An unsorted array and its size are passed in
 
    Postcondition:
        This size remains unchanged, but the Heap object has been created, and 
        the input array, which is pointed to by the private variable theArray,
        has been maxHeapified.
 */
Heap::Heap(int *arr, int size)
{
    counter = 0;
    theArray = arr;
    buildMaxHeap(arr, size);
}

/*
 * The heap destructor: since nothing is created on the stack in this class,
 * nothing needs to be in the destructor. Note that theArray is a pointer to
 * the array that is passed into the constructor. Thus, it does not need to be
 * deleted since this array is later deleted in the checkSort function.
 */
Heap::~Heap()
{

}

/*
 1. Function prototype:
        void Heap::buildMaxHeap(int *arr, int size);
 
 2. Function description:
        The buildMaxHeap function takes in a pointer to an array, and the array's size
        and then starting at the bottom of the heap (that is, the nodes just above the
        leaf nodes) calls maxHeapify to give the array the max heap property. The max heap property
        is that all nodes below a given node are at most equal to the node itself. We don't call the 
        maxHeapify function on the leaf nodes (all nodes with indices > arrayLength/2) since, having
        no children, they already satisfy the max heap property. We start at the bottom and work our
        way to the top so that, for every node we encounter, its left and right subtrees are already 
        max heaps (which the maxHeapify function requires).
 
        The reason why all nodes with indices > arrayLength/2 are leaf nodes is because right(index)
        is defined to be 2*index + 1, and left(index) is 2*index. Thus, for indices > arrayLength/2,
        the right and left children are not indices in the array.
 
 3. Example:
        buildMaxHeap(arr, size); //this function is only called in the Heap constructor
 
 4. Precondition:
        The input array is unsorted, and unheapified.
 
    Postcondition:
        The array at the end is still unsorted, but it has been heapified (it satisfies the max
        heap property).
        The size is unchanged.
        The heapSize is set to be equal to the array size.
 */
void Heap::buildMaxHeap(int *arr, int size)
{
    arrayLength = size;
    heapSize = arrayLength;
    for (int i = arrayLength/2; i >= 0; i--)
    {
        counter++;
        maxHeapify(arr, i);
    }
}

/*
 1. Function prototype:
        void Heap::maxHeapify(int *arr, int index);
 
 2. Function description:
        This function takes an index of the heap that has not yet been given the
        max heap property, and gives the index the heap property. Once the index,
        if the heap was changed in the process, the value at the index will have
        been exchanged with either its left or right child's value. If this happens,
        The maxHeapify is recursively called on that child so that the entire subtree
        might have its max heap property restored.
 
 3. Example:
        maxHeapify(arr, i); //i is the index being max heapified
 
 4. Precondition:
        The array at the input index and the index's subtrees have not had the
        max heap property imposed on them.
 
    Postcondition:
        After the function completes, the input index and its entire subtree has
        had the max heap property. That is, every index in the subtree of the input
        index has a value that is not exceeded by any of its children.
 */
void Heap::maxHeapify(int *arr, int index)
{
    counter++;
    int largest;
    int left = returnLeft(index);
    int right = returnRight(index);
    if (left < heapSize && theArray[left] > theArray[index])
    {
        largest = left;
    }
    else
    {
        largest = index;
    }
    if (right < heapSize && theArray[right] > theArray[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        int temp = theArray[index];
        theArray[index] = theArray[largest];
        theArray[largest] = temp;
        maxHeapify(arr, largest);
    }
}

/*
 * The next four functions are insignificant. The first three return indices in the
 * array that correspond to the left, right and parent of the value at the the input
 * index. The other method is a getter.
 */

int Heap::returnLeft(int index)
{
    return (2*index);
}

int Heap::returnRight(int index)
{
    return ((2*index)+1);
}

int Heap::returnParent(int index)
{
    return (index/2);
}

int Heap::getCounter()
{
    return counter;
}

/*
 1. Function prototype:
        void Heap::heapSort();
 
 2. Function description:
        A heap has been created out of the array. This heap has been maxHeapified (that function is
        described above). The greatest value is at the first index, so in order to sort the array,
        one merely takes the first index, places it at the end of the heap, decrements the heap by one,
        and restores the maxHeap property (so that the next greatest value will be at the front).
 
 3. Example:
        Heap myHeap(arr, size); //create heap
        myHeap.heapSort();
 
 4. Precondition: 
        the Heap has been created from the array, and it has been maxHeapified (see maxHeapify for more)
        the counter has been incremented several times already at this point
        the heapSize is equal to the size of the array to be sorted
    Postcondition:
        the array is sorted
        the counter has been incremented as much as was necessary to sort the array
        the heapSize is now 1
 */
void Heap::heapSort()
{
    for (int i = heapSize - 1; i >= 1; i--)
    {
        counter++;
        int temp = theArray[0];
        theArray[0] = theArray[i];
        theArray[i] = temp;
        heapSize = heapSize - 1;
        maxHeapify(theArray, 0);
    }
}
