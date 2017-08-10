//
//  BSTTree.hpp
//  BSTTree
//
//  Created by apple on 10.08.2017.
//  Copyright © 2017 apple. All rights reserved.
//

#ifndef BSTTree_hpp
#define BSTTree_hpp

class Node;

class BSTTree {
    Node* root;
    
    void insert(int value, Node* root);
    int getMinValue(Node* root);
    int getMaxValue(Node* root);
    Node* deleteValue(int value, Node* root);
    Node* getPredecessor(Node* root);



#pragma mark Public methods
public:
    void insert(int value);
    int getMinValue();
    int getMaxValue();
    void deleteValue(int value);
    BSTTree();
};
#endif /* BSTTree_hpp */
