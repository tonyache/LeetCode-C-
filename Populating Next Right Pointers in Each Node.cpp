//
//  116.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "116.hpp"
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>

// Consider a data structure given by a binary tree and such that all nodes in a given level form a singly linked list.
// Write an algorithm that returns for every tree node the next element in the level corresponding to that tree node
// (again one sees the level containing the node as a linked list).

using namespace std;

 //Definition for binary tree with next pointer.
 struct TreeLinkNode {
     int val;
      TreeLinkNode *left, *right, *next;
      TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
     };

class Solution {
public:
    
    TreeLinkNode* populate_from_node(TreeLinkNode *parent,TreeLinkNode *root,bool left_child){
        TreeLinkNode* tmp;
        if(root==NULL){
            return NULL;
        }
        else{
            if(left_child==true){
                root->next=parent->right;
                populate_from_node(root,root->left,true);
                populate_from_node(root,root->right,false);
            }
            else{
                if(parent->next==NULL){
                    root->next=NULL;
                    populate_from_node(root,root->left,true);
                    populate_from_node(root,root->right,false);
                }
                else{
                    tmp=parent->next;
                    root->next=tmp->left;
                    populate_from_node(root,root->left,true);
                    populate_from_node(root,root->right,false);
                }
            }
            
        }
        return root;
    }
    
    void connect(TreeLinkNode *root) {
        if (root==NULL){
            return;
        }
        else{
            populate_from_node(root,root->left,true);
            populate_from_node(root,root->right,false);}   
    }
};
