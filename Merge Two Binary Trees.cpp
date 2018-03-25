//
//  Merge Two Binary Trees.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/25/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "Merge Two Binary Trees.hpp"
 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
class Solution {
public:
    
    TreeNode* mergeTrees_with_parent (TreeNode* parent1,TreeNode* t1,TreeNode* parent2, TreeNode* t2,bool left_child){
        int tmp;
        if((t1==NULL)&&(t2==NULL)){
            return NULL;
        }
        else if(t2==NULL){
            return t1;
        }
        else if(t1==NULL){
            if(left_child==true){
                parent1->left=t2;
                return t2;
            }
            else{
                parent1->right=t2;
                return t2;
            }
            
        }
        else{
            tmp=t1->val;
            t1->val=tmp+(t2->val);
            mergeTrees_with_parent(t1,t1->left,t2,t2->left,true);
            mergeTrees_with_parent(t1,t1->right,t2,t2->right,false);
            return t1;
        }
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        int tmp;
        if((t1==NULL)&&(t2==NULL)){
            return NULL;
        }
        else if(t2==NULL){
            return t1;
        }
        else if(t1==NULL){
            return t2;
        }
        else{
            tmp=t1->val;
            t1->val=tmp+(t2->val);
            mergeTrees_with_parent(t1,t1->left,t2,t2->left,true);
            mergeTrees_with_parent(t1,t1->right,t2,t2->right,false);
            return t1;
        }
    }};