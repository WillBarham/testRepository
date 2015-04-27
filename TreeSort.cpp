//
//  TreeSort.cpp
//  FinalProjectCSCI2270
//
//  Created by William Barham on 4/22/15.
//  CSCI 2270- Data Structures and Algorithms
//  Instructor: Hoenigman
//  Final Project

#include <iostream>
#include "TreeSort.h"

using namespace std;

/*
 * In treesort, one merely builds an unbalanced binary search tree
 * from the array that needs to be sorted, and then does an inorder
 * tree traversal to sort the array contents.
 *
 * I designed these functions based on the psuedocode for binary 
 * search trees in the Cormen text. (ch. 12)
 */

/*
 1. Function prototype:
    Tree::Tree(int *arr, int size);
 
 2. Function description:
    The constructor takes in an array and its size and builds an unbalanced binary search 
    tree from the array contents.
 
 3. Example:
    Tree myTree(array, size); //The way you typically create an object with its constuctor
 
 4. Precondition:
        The array is unsorted.
 
    Postcondition:
        A Tree object is built from the unsorted array.
 */
Tree::Tree(int *arr, int size)
{
    counter = 0;
    root = NULL;
    buildTree(arr, size);
}

/*
 1. Function prototype:
    Tree::~Tree();
 
 2. Function description:
    This function is the destructor. It calls a helper method destroyTree.
    destroyTree then frees the allocated memory.
 
 3. Example:
    called when tree goes out of scope
 
 4. Precondition:
        We have a binary tree.
 
    Postcondition:
        The binary tree is deleted when this function is called.
 */
Tree::~Tree()
{
    destroyTree();
}

/*
 1. Function prototype:
    void Tree::destroyTree();
 
 2. Function description:
    This function calls an overloaded destroyTree(node*) method to
    free dynamically allocated memory.
 
 3. Example:
    destroyTree(); //This is called in destructor.
 
 4. Precondition:
        Before this function is called, the tree is intact.
 
    Postcondition:
        After this is called, the tree is deleted.
 */
void Tree::destroyTree()
{
    destroyTree(root);
}

/*
 1. Function prototype:
    void Tree::destroyTree(node *currentNode);
 
 2. Function description:
    This function is just a postorder tree traversal that deletes the tree
    as it traverses. This is an overloaded function called by destroyTree().
 
 3. Example:
    destroyTree(root); //initial call
    destroyTree(currentNode->left); //a recursive call
    destroyTree(currentNode->right); //another recursive call
 
 4. Precondition:
        Before this is called, currentNode, and its right and left subtrees are intact.
 
    Postcondition:
        After this is called, currentNode, and its right and left subtrees are deleted.
 */
void Tree::destroyTree(node *currentNode)
{
    if (currentNode != NULL)
    {
        destroyTree(currentNode->left);
        destroyTree(currentNode->right);
        delete currentNode;
    }
}


/*
 1. Function prototype:
    void Tree::buildTree(int *arr, int size);
 
 2. Function description:
    This function builds the tree from the array contents. It takes each array element,
    and passes it to the insertNode function.
 
 3. Example:
    buildTree(arr, size); //called in constructor
 
 4. Precondition:
        Initally, the tree is empty.
 
    Postcondition:
        After the function finishes, a binary search tree has been built from the contents
        of the array. Array is unchanged. The counter is incremented in each execution of
        the loop.
 */
void Tree::buildTree(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        counter++;
        insertNode(arr[i]);
    }
}

/*
 1. Function prototype:
    void Tree::insertNode(int value);
 
 2. Function description:
    The function creates a new node using the passed value as the node value. If the root is
    NULL, the new node becomes the root. Otherwise, the node is passed to the overloaded
    insertNode(node *newNode, node *theRoot) function.
 
 3. Example:
    insertNode(arr[i]); //the passed value will be the array contents
                        //see buildTree to see this function called
 4. Precondition:
        Before this is called, the binary tree will not contain a node corresponding to
        the array at i.
 
    Postcondition:
        After this is called, the tree has another node with the passed value. The counter is
        increased an amount that corresponds to how long it took to add the new node.
 
 */
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

/*
 1. Function prototype:
    void Tree:insertNode(node *newNode, node *theRoot);
 
 2. Function description:
    This function travels down the tree taking the left pointer if the input value 
    is smaller than the node we're comparing to, and the right if greater until we 
    reach NULL. The new node is then inserted at this unoccupied position in the tree.
    This function is overloaded. It is called inside insertNode(int value).
 
 3. Example:
    insertNode(newNode, root); //This is called inside insertNode(int value).
 
 4. Precondition:
        newNode is not yet in the tree.
 
    Postcondition:
        newNode is inserted into the tree in a way that maintains the search binary 
        tree property. counter is incremented each time the while loop is entered.
 */
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

/*
 1. Function prototype:
    int* Tree::treeSort(int *arr);
 
 2. Function description:
    This function increments the counter, and calls the overloaded treeSort(int*, node*, int)
    function. That function sorts the array. This function then returns the sorted array.
 
 3. Example:
    Tree myTree(arr, size); //size is the size of arr
    arr = myTree.treeSort(arr);
 
 4. Precondition:
        Before this is called, the array is unsorted.
 
    Postcondition:
        After this is called, the array is sorted. The counter is also incremented a 
        number of times corresponding to the time it took to sort the array.
 */
int* Tree::treeSort(int *arr)
{
    counter++;
    int index = 0;
    treeSort(arr, root, index);
    return arr;
}

/*
 1. Function prototype:
    void Tree::treeSort(int *arr, node *currentNode, int &index);
 
 2. Function description:
    This function does an inorder tree traversal to add elements to the
    array in ascending order. The index passed in is initally zero, but
    each time a value is added to the array, the index is incremented so
    that the next value added will be in the next position in the array.
    The counter is incremented each time this function is entered.
 
 3. Example:
    treeSort(arr, root, index); // index = 0, this function is called in this way
                                // in the overloaded treeSort(int *arr) function
                                // found above.
 4. Precondition:
        The array is unsorted.
 
    Postcondition:
        After completing the array will be sorted. The counter will have been
        incremented n times (n being the size of the array).
 */
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
