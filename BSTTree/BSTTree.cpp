//
//  BSTTree.cpp
//  BSTTree
//
//  Created by apple on 10.08.2017.
//  Copyright © 2017 apple. All rights reserved.
//

#include "BSTTree.hpp"
#include "Node.hpp"

void BSTTree::insert(int value) {
    if(this->root==nullptr) {
        this->root = new Node(value);
    }else {
        this->insert(value, this->root);
    }
}

void BSTTree::insert(int value, Node *root) {
    if(value < root->value) {
        if(root->leftChild == nullptr) {
            root->leftChild = new Node(value);
        }else {
            this->insert(value, root->leftChild);
        }
    }else {
        if(root->rightChild == nullptr) {
            root->rightChild = new Node(value);
        }else {
            this->insert(value, root->rightChild);
        }
    }
}

int BSTTree::getMinValue() {
    if(this->root == nullptr) throw "empty tree";
    
    return this->getMinValue(this->root);
}

int BSTTree::getMinValue(Node *root) {
    if(root->leftChild == nullptr) return this->root->value;
    
    return this->getMinValue(root->leftChild);
}

int BSTTree::getMaxValue() {
    if(this->root ==nullptr) throw "empty tree";
    
    return this->getMaxValue(this->root);
}

int BSTTree::getMaxValue(Node *root) {
    if(root->rightChild == nullptr) return root->value;
    
    return this->getMaxValue(root->rightChild);
}

void BSTTree::deleteValue(int value) {
    if(this->root == nullptr) throw "not found";
    
    this->root = this->deleteValue(value, this->root);
}

Node* BSTTree::deleteValue(int value, Node* root) {
    if(root == nullptr) return nullptr;
    
    if(value < root->value) {
        root->leftChild = this->deleteValue(value, root->leftChild);
    }else if(value > root->value) {
        root->rightChild = this->deleteValue(value, root->rightChild);
    }else {
        if(root->leftChild == nullptr && root->rightChild == nullptr) {
            delete root;
            return nullptr;
        } else if(root->leftChild == nullptr) {
            Node* temp = root->rightChild;
            delete root;
            return temp;
        }else if(root->rightChild == nullptr) {
            Node* temp = root->leftChild;
            delete root;
            return temp;
        }else {
            Node* temp = this->getPredecessor(root);
            root->value = temp->value;
            root->leftChild = this->deleteValue(value, root->leftChild);
        }
    }
    return root;
}

Node* BSTTree::getPredecessor(Node *root) {
    if(root->rightChild == nullptr) return root;
    
    return this->getPredecessor(root->rightChild);
}

