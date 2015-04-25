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

const int QUIT = 8;

int main()
{
    int userInput = 0;
    int size;
    
    while (userInput != QUIT)
    {
        cout << "===Main Menu===" << endl
             << "Choose a sorting algorithm." << endl
             << "1. Heap sort" << endl
             << "2. Tree sort" << endl
             << "3. Merge sort" << endl
             << "4. Bubble sort" << endl
             << "5. Insertion sort" << endl
             << "6. Selection sort" << endl
             << "7. Quick sort" << endl
             << "8. Quit" << endl;
        cin >> userInput;
        
        if (userInput == sort::HEAPSORT)
        {
            cout << "Enter the size of the array you want sorted" << endl;
            cin >> size;
            checkSort(size, userInput);
        }
        else if (userInput == sort::TREESORT)
        {
            cout << "Enter the size of the array you want sorted" << endl;
            cin >> size;
            checkSort(size, userInput);
        }
        else if (userInput == sort::MERGESORT)
        {
            cout << "Enter the size of the array you want sorted" << endl;
            cin >> size;
            checkSort(size, userInput);
        }
        else if (userInput == sort::BUBBLESORT)
        {
            cout << "Enter the size of the array you want sorted" << endl;
            cin >> size;
            checkSort(size, userInput);
        }
        else if (userInput == sort::INSERTIONSORT)
        {
            cout << "Enter the size of the array you want sorted" << endl;
            cin >> size;
            checkSort(size, userInput);
        }
        else if (userInput == sort::SELECTIONSORT)
        {
            cout << "Enter the size of the array you want sorted" << endl;
            cin >> size;
            checkSort(size, userInput);
        }
        else if (userInput == sort::QUICKSORT)
        {
            cout << "Enter the size of the array you want sorted" << endl;
            cin >> size;
            checkSort(size, userInput);
        }
        else if (userInput == QUIT)
        {
            cout << "Goodbye!" << endl;
        }
    }
}

