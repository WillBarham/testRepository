//
//  driver.cpp
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  CSCI 2270- Data Structures and Algorithms
//  Instructor: Hoenigman
//  Final Project

#include <iostream>
#include "FinalProject.h"

using namespace std;

const int QUIT = 8;
enum sort;

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
        
        if (userInput == HEAPSORT)
        {
            cout << "Enter the size of the array you want sorted" << endl;
            cin >> size;
            checkSort(size, userInput);
        }
        else if (userInput == TREESORT)
        {
            cout << "Enter the size of the array you want sorted" << endl;
            cin >> size;
            checkSort(size, userInput);
        }
        else if (userInput == MERGESORT)
        {
            cout << "Enter the size of the array you want sorted" << endl;
            cin >> size;
            checkSort(size, userInput);
        }
        else if (userInput == BUBBLESORT)
        {
            cout << "Enter the size of the array you want sorted" << endl;
            cin >> size;
            checkSort(size, userInput);
        }
        else if (userInput == INSERTIONSORT)
        {
            cout << "Enter the size of the array you want sorted" << endl;
            cin >> size;
            checkSort(size, userInput);
        }
        else if (userInput == SELECTIONSORT)
        {
            cout << "Enter the size of the array you want sorted" << endl;
            cin >> size;
            checkSort(size, userInput);
        }
        else if (userInput == QUICKSORT)
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

