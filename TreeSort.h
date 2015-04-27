//
//  TreeSort.h
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  CSCI 2270- Data Structures and Algorithms
//  Instructor: Hoenigman
//  Final Project

#ifndef TREESORT_H
#define TREESORT_H

struct node
{
    node *right;
    node *left;
    int value;
};

class Tree
{
    public:
        Tree(int *arr, int size);
        ~Tree();
        void destroyTree();
        void destroyTree(node *currentNode);
        void buildTree(int *arr, int size);
        void insertNode(int value);
        void insertNode(node *newNode, node *theRoot);
        int* treeSort(int *arr);
        void treeSort(int *arr, node *currentNode, int &index);
        int getCounter();
    private:
        node* root;
        int counter;
};

#endif
