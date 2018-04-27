//
//  Valid_Binary_Tree.cpp
//  Leetcode
//
//  Created by Antonio Ache on 4/27/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "Valid_Binary_Tree.hpp"
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

// Definition of a Binary Tree

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

// Determine if a given binary tree is a binary-search tree
//This solution is based on a min-max approach

class Solution {
public:
    int max_subtree(TreeNode* root){
        
        int max1,max2;
        if(root==NULL){
            return -INFINITY;
        }
        else{
            max1=std::max(max_subtree(root->left),max_subtree(root->right));
            max2=std::max(max1,root->val);
            return max2;
        }
    }
    
    int min_subtree(TreeNode* root){
        
        int min1,min2;
        if(root==NULL){
            return INFINITY;
        }
        else{
            min1=std::min(min_subtree(root->left),min_subtree(root->right));
            min2=std::min(min1,root->val);
            return min2;
        }
    }
    
    
    bool isValidBST(TreeNode* root) {
        bool partial_answer;
        if(root==NULL){
            return true;
        }
        else if((root->right==NULL)&&(root->left==NULL)){
            return true;
        }
        else{
            partial_answer=isValidBST(root->right)&isValidBST(root->left);
            if(partial_answer==true){
                if(((root->val>max_subtree(root->left)||(root->left==NULL)))&&((root->val<min_subtree(root->right))||(root->right==NULL))){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
};