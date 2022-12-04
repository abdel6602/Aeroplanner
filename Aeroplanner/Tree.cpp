#include <stdio.h>
#include <iostream>
#include "Tree.h"
#include <vector>

using namespace std;

//Tree Constructor
template <class elemType>
Tree<elemType> ::Tree(elemType newRoot) {
    Node* newNode = new Node(newRoot);
    root = newNode;
}
//Destructor
template <class elemType>
Tree<elemType>::~Tree() { 
    Node* ptr = root;
    delete (root);
    // Node * ptr = root;
    // leftPtr lptr = root;
    // // el right one dayman wahda bas
    // rightPtr rptr= root->right;
    // delete (rptr);

    // // nezelt lehad ma l2et 5er parent node
    // rptr=ptr->right;
    // while ( lptr->left != nullptr){
    //     lptr=lptr->left;
    //     delete (rptr);
    //     delete (ptr);
    //     ptr=lptr;
    //     rptr=ptr->right;
    // }
    // //waslt le 25er node malhash right heya left bas malhash right fa ashelha bel pointer lptr ely nezel 3ndaha
    // delete (lptr);
   
}

//eraseFromTree Function 
template <class elemType>
void Tree<elemType> ::eraseFromTree(const Node<elemType>*& x) {
    Tree::nodePtr current;   // pointer to traverse tree
    Tree::nodePtr parent;    // pointer to parent of node
    Tree::nodePtr temp;      // pointer to delete node

    if (x == NULL)
        cout << "Error. The node desired to be erased doesn't exist" << endl;
    // node that has no children
    else if (x->left == NULL && x->right == NULL) {
        x == NULL;
        delete x;
    }
    // node that has one child
    else if (x->left == NULL) {
        x = x->right;
        delete x;
    }
    else if (x->right == NULL) {
        x = x->left;
        delete x;
    }
    // node that has 2 children
    // loop in left sub tree to find right most node (predecessor)
    else {
        current = x->left;
        parent = NULL;

        while (current->right != NULL) {
            parent = current;
            current = current->right;
        }

        x->name = current->name;

        if (parent == NULL)
            x->left = current->left;
        else
            parent->right = current->right;

        delete current;
    }
}

// eraseNode function
// search tree to find node to be deleted
template <class elemType>
void Tree<elemType> ::eraseNode(const elemType& item) {
    Tree::nodePtr current;        // pointer to traverse tree
    Tree::nodePtr parent;         // pointer to parent of node
    bool found == false;

    if (root == NULL)
        cout << "Error, tree is empty" << endl;
    else {
        current = root;
        parent = root;

        while (current != NULL && !found) {
            if (current->data == item)
                found = true;
            else {
                parent = current;
                if (current->data.name > item.name)
                    current = current->left;
                else
                    current = current->right;
            }
        }

        if (current == NULL)
            cout << "Error, Item desired to be deleted doesn't exist" << endl;
        else if (found) {
            if (current == root)
                eraseFromTree(root);
            else if (parent->data.name > item)
                eraseFromTree(parent->left);
            else
                eraseFromTree(parent->right);
        }
        else
            cout << "Error, Item to be deleted isn't in the tree" << endl;

    }

}


//traverse function
template <class elemType>
int Tree<elemType> ::Traverse(Node<elemType>* root) {
    if (root != NULL) {
        cout << root->data.name << endl;
        Traverse(root->left);
        Traverse(root->right);
        for (ElementCost cost = 0; cost <= root->cost; cost++) {
            cost += cost;
            return cost;
        }
    }

}

//assume that the last node inserted is the B-endpoint- of the route that will be displayed as last node
template <class elemType>
void Tree<elemType>::insert(elemType item, bool flag)
{
    Node* newPtr = new Node(item);
    leftPtr lPtr = root->left; // ->left;
    rightPtr rPtr = root->right;// ->right ;
    treeRootPtr rootPtr = root;
    Node* ptr;
    Node* preptr;

    if (empty()) { //law m3ndesh 5er A bas
        /*
        if (newPtr->cost > rootPtr->cost)
            cerr << "invalid waypoint";
        rootPtr->left = newPtr;
        lPtr = rootPtr->left;
        lPtr->right = rootPtr;
        rootPtr = lPtr;
        */
        lptr = newPtr;
        return;
    }
    if (!empty()) {
        if (flag)
            leafItem = Node(item);
        //finding parent: returns a pointer to the node with node == item
        nodePtr parent = this->getParentPos(item);
        //case of two children (in this program it is invalid because it would disrupt an existing route
        // possibility)
        if (parent->right != 0 && parent->left != 0) {
            cerr << "INSERT ERROR CODE : 01";
        }
        //case of no children
        if (parent->right == 0 && parent->left == 0) {
            parent->left = newPtr;
            return;
        }
        //case of 1 child on the left
        if (parent->left != 0 && parent->right == 0) {
            if (item->data < parent->left) {
                this->swap(new Node(item), parent);
                return;
            }
            else {
                parent->right = new Node(item);
                return;
            }
        }
/*
        if (newPtr->cost > rootPtr->cost)
            cerr << "invalid waypoint";
        if (newPtr->cost < rootPtr->cost)
        {
            //if (130)
            //      \
            //      (150)A
            if (rootPtr->left == nullptr)
                rootPtr->left = newPtr;

            //    (130)
       //        /     \
       //      (120)   (150)A
                   // after this goes normal sceanrio of inserting the nodes and adjusting the tree to fit the preorder traverse
            ptr = lPtr;
            while (lPtr->left != nullptr)
            {
                ptr = lPtr;
                lPtr = lPtr->left;
            }
            lPtr->left = newPtr;
            if (ptr->right == nullptr) {
                preptr = ptr;
                ptr = lPtr;
                lPtr = lPtr->left;
                preptr->left = lPtr;
                lPtr->right = ptr;
            }
        }


        */  
    }
}

template <class elemType>
bool Tree<elemType>::empty()
{
    return (root == nullptr);
}

template <class elemType>
vector<string> Tree<elemType>::extractRoute() {
    treeRootPtr ptr = root;
    leftptr lptr = root->left;
    rightPtr rptr = lptr->left->right;
    vector<string> route;
    
    if (empty()) {
        cerr << "INSERT ERROR CODE: 03" << root->name;
    }
    while (ptr->data.name != leafItem->data.name) {
        //diversions to avoid in-air conflicts
        if (ptr->data.isBusy()) {
            ptr = ptr->right;
            route.push_back(ptr->data.name);
        }
        //follow the leftmost path for the best route
        else {
            ptr = ptr->left;
            route.push_back(ptr->data.name);
        }
        //guard condition for insertion errors
        if (ptr == 0)
            cerr << "INSERT ERROR CODE:02";
    }
    return route;
    /*if (rootAptr->right == nullptr)
    {
        q1.push(rootAptr->data.name);
        delete (rootAptr);
    }
    q1.push(lptr->data.name);
    q1.push(rptr->data.name);
    if (lptr->left != nullptr)
    {
        lptr = lptr->left;
        rptr = lptr->right;
        extractRoute();

    }*/
}

template<class elemType>
Tree<elemType>::nodePtr Tree<elemType>::getParentPos(elemType& item)
{
    nodePtr ptr = root;
    return traverseDF(ptr, item); 
}

template<class elemType>
Tree<elemType> :: nodePtr Tree<elemType>::traverseDF(nodePtr node, elemType& item)
{
    if (node->data == item->data)
        return node;
    if (node == NULL)
        return 0;
    traverseDF(node->left, item);
    traverseDF(node->right, item);
}

template<class elemType>
void Tree<elemType>::swap(nodePtr item, nodePtr parent)
{
    parent->right = parent->left;
    parent->left = item;
}