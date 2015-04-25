//
//  TreeSort.cpp
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  Copyright (c) 2015 William Barham. All rights reserved.
//

#include <iostream>
#include "TreeSort.h"

using namespace std;

Tree::Tree(int *arr, int size)
{
    counter = 0;
    root = NULL;
    buildTree(arr, size);
}

Tree::~Tree()
{
    destroyTree();
}

void Tree::destroyTree()
{
    destroyTree(root);
}

void Tree::destroyTree(node *currentNode)
{
    if (currentNode != NULL)
    {
        destroyTree(currentNode->left);
        destroyTree(currentNode->right);
        delete currentNode;
    }
}

void Tree::buildTree(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        counter++;
        insertNode(arr[i]);
    }
}

void Tree::insertNode(int value)
{
    counter++;
    //Create the new node to add
    node *newNode = new node;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = value;
    
    if (root != NULL)
    {
        //Pass the newly created node to the private insertNode function
        insertNode(newNode, root);
    }
    else
    {
        //If the tree is empty, then the new node is the root.
        root = newNode;
    }
}

void Tree::insertNode(node *newNode, node *theRoot)
{
    node *newPosition = theRoot;
    node *parentNode = NULL;
    while (newPosition != NULL)
    {
        counter++;
        parentNode = newPosition;
        if (newNode->value < newPosition->value)
        {
            newPosition = newPosition->left;
        }
        else
        {
            newPosition = newPosition->right;
        }
    }
    if (newNode->value < parentNode->value)
    {
        parentNode->left = newNode;
    }
    else
    {
        parentNode->right = newNode;
    }
}

int* Tree::treeSort(int *arr)
{
    counter++;
    int index = 0;
    treeSort(arr, root, index);
    return arr;
}

void Tree::treeSort(int *arr, node *currentNode, int &index)
{
    counter++;
    if (currentNode != NULL)
    {
        treeSort(arr, currentNode->left, index);
        arr[index] = currentNode->value;
        index++;
        treeSort(arr, currentNode->right, index);
    }
}

int Tree::getCounter()
{
    return counter;
}
