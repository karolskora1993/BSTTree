//
//  Node.hpp
//  BSTTree
//
//  Created by apple on 10.08.2017.
//  Copyright © 2017 apple. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

struct Node {
    int value;
    Node* leftChild;
    Node* rightChild;
    
    Node(int value);
};

#endif /* Node_hpp */
