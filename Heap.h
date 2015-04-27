//
//  Heap.h
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  CSCI 2270- Data Structures and Algorithms
//  Instructor: Hoenigman
//  Final Project

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
        int getCounter();
    private:
        int *theArray;
        int heapSize;
        int arrayLength;
        int counter;
};

#endif
