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

            size = 100000000;
            while(size>10000)
            {
                cout << "Enter the size of the array you want sorted (10000 or under)" << endl;
                cin >> size;
            }
            if (size < 10000)
            {
                    checkSort(size, userInput);
            }

        }
        else if (userInput == TREESORT)
        {
             size = 100000000;
            while(size>10000)
            {
                cout << "Enter the size of the array you want sorted (10000 or under)" << endl;
                cin >> size;
            }
            if (size < 10000)
            {
                    checkSort(size, userInput);
            }
        }
        else if (userInput == MERGESORT)
        {
             size = 100000000;
            while(size>10000)
            {
                cout << "Enter the size of the array you want sorted (10000 or under)" << endl;
                cin >> size;
            }
            if (size < 10000)
            {
                    checkSort(size, userInput);
            }
        }
        else if (userInput == BUBBLESORT)
        {
             size = 100000000;
            while(size>10000)
            {
                cout << "Enter the size of the array you want sorted (10000 or under)" << endl;
                cin >> size;
            }
            if (size < 10000)
            {
                    checkSort(size, userInput);
            }
        }
        else if (userInput == INSERTIONSORT)
        {
             size = 100000000;
            while(size>10000)
            {
                cout << "Enter the size of the array you want sorted (10000 or under)" << endl;
                cin >> size;
            }
            if (size < 10000)
            {
                    checkSort(size, userInput);
            }
        }
        else if (userInput == SELECTIONSORT)
        {
             size = 100000000;
            while(size>10000)
            {
                cout << "Enter the size of the array you want sorted (10000 or under)" << endl;
                cin >> size;
            }
            if (size < 10000)
            {
                    checkSort(size, userInput);
            }
        }
        else if (userInput == QUICKSORT)
        {
             size = 100000000;
            while(size>10000)
            {
                cout << "Enter the size of the array you want sorted (10000 or under)" << endl;
                cin >> size;
            }
            if (size < 10000)
            {
                    checkSort(size, userInput);
            }
        }
        else if (userInput == QUIT)
        {
             size = 100000000;
            while(size>10000)
            {
                cout << "Enter the size of the array you want sorted (10000 or under)" << endl;
                cin >> size;
            }
            if (size < 10000)
            {
                    checkSort(size, userInput);
            }
        }
    }
}

