//
//  Heap.cpp
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  Copyright (c) 2015 William Barham. All rights reserved.
//

#include <iostream>
#include "Heap.h"

using namespace std;

Heap::Heap(int *arr, int size)
{
    counter = 0;
    theArray = arr;
    buildMaxHeap(arr, size);
}

Heap::~Heap()
{
    
}

void Heap::buildMaxHeap(int *arr, int size)
{
    arrayLength = size; // -1 makes it so we get the right indices.
    heapSize = arrayLength;
    for (int i = arrayLength/2; i >= 0; i--)
    {
        counter++;
        maxHeapify(arr, i);
    }
}

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

int *Heap::getArray()
{
    return theArray;
}

int Heap::getCounter()
{
    return counter;
}

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
