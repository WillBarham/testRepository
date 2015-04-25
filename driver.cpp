//
//  driver.cpp
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  Copyright (c) 2015 William Barham. All rights reserved.
//

#include <iostream>
#include "Heap.h"
#include "FinalProject.h"
#include "Sort.h"
#include "TreeSort.h"

using namespace std;

int main()
{
    int size;
    
    cout << "Enter the size of the array you want sorted" << endl;
    cin >> size;
    
    checkHeapSort(size);
    cout << endl;
    checkTreeSort(size);
    cout << endl;
    checkMergeSort(size);
    cout << endl;
    checkBubbleSort(size);
    cout << endl;
    checkInsertionSort(size);
    cout << endl;
    checkSelectionSort(size);
    cout << endl;
    checkQuickSort(size);
}
