//
//  Maximum Depth of a Binary Search Tree.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "Maximum Depth of a Binary Search Tree.hpp"
#include<iostream>

using namespace std;


struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };


    int maxDepth(TreeNode* root) {
        int d_right,d_left,max;
        if(root==NULL){
            return 0;
        }
        else{
            d_left=maxDepth(root->left);
            d_right=maxDepth(root->right);
            max=std::max(d_left,d_right);
            return(max+1);
        }
    }