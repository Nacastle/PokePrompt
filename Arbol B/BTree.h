#pragma once
#include "BTreeNode.h"
#include <iostream>

class BTree
{
	BTreeNode *root;
	int t;
public:
	BTree(int _t){
        root = NULL;
        t = _t;
    }

	void traverse(){ 
        if (root != NULL) root->traverse(); 
    }

	BTreeNode* search(int k){
        return (root == NULL)? NULL : root->search(k); 
    }

	void insert(int k);
    
    void remove(int k);
    friend class BTreePrinter;
};