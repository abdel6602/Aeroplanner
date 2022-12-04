#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

template <class elemType>
class Tree
{
private:
   
    template <class elemType>
    class Node {
    public:
        elemType data;
        Node<elemType>* left;
        Node<elemType>* right;

        Node()
            :left(0), right(0)
        {}
        //constructor to copy waypoint into the node
        Node(elemType waypoint)
            : left(0), right(0)
        {
            data = waypoint;
        }
        //destructor deletes the node and all children of a node: used for the tree destructor
        ~Node() {
            delete (left);
            delete (right);
        }
    }
    typedef Node* treeRootPtr2;    // line malosh ay lazma, mahtot bs 3lshn lw shelto el line el tahto haytal3 error for some reason
    typedef Node* treeRootPtr;
    typedef Node* nodePtr;
    typedef Node* leftptr;
    typedef Node* rightPtr;
    //for traversal during insert
    nodePtr getParentPos(elemType& item);
    nodePtr traverseDF(nodePtr node, elemType& item);
    //to swap 2 children
    void swap(nodePtr item, nodePtr parent);

public:


    Tree(elemType newRoot);  // instruct tree by the start node 
    ~Tree(); //destructor when I extract path
    void insert(elemType item, bool flag);// insert node if there is root if not add it as the root
    void eraseFromTree(const Node<elemType>*& x); // delete node desired, even if it is in the middle
    void eraseNode(const elemType& item);
    //search()
    int Traverse(Node<elemType>* root); // by depth to calculate the cost and return the cost
    //void extractBranch();// return the path
    //void deleteBranch();//it will be used in the extractBranch function to ensure that each node only have one child
    //createBranch();
    bool empty();
    vector<string> extractRoute();//display the route


private:
    treeRootPtr root;
    Node rootItem, leafItem;
};
