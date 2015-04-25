//
//  Heap.h
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  Copyright (c) 2015 William Barham. All rights reserved.
//

#ifndef HEAP_H
#define HEAP_H

class Heap
{
    public:
        Heap(int *arr, int size); //takes in an array and creates a heap out of it
        ~Heap();
        void maxHeapify(int *arr, int index);
        void buildMaxHeap(int *arr, int size);
        int returnParent(int index);
        int returnLeft(int index);
        int returnRight(int index);
        void heapSort();
        int *getArray();
        int getCounter();
    private:
        int *theArray;
        int heapSize;
        int arrayLength;
        int counter;
};

#endif
