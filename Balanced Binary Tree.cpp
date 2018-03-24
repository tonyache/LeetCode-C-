//
//  Balanced Binary Tree.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "Balanced Binary Tree.hpp"
#include<iostream>
#include<math.h>

using namespace std;

struct TreeNode {
         int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
      };



    int depth(TreeNode* root){
        int depth_right;
        int depth_left;
        if (root==NULL){
            return 0;
        }
        else{
            depth_right=depth(root->right);
            depth_left=depth(root->left);
            return std::max(depth_right,depth_left)+1;
            
        }
    }
    
    bool isBalanced(TreeNode* root) {
        int depth_left;
        int depth_right;
        bool partial_answer;
        if(root==NULL){
            return true;
        }
        else{
            partial_answer=isBalanced(root->left)&isBalanced(root->right);
            if(partial_answer==false){
                return false;
            }
            else{
                depth_right=depth(root->right);
                depth_left=depth(root->left);
                if(abs(depth_left-depth_right)>1){
                    return false;
                }
                else{
                    return true;
                }
            }
        }
    }