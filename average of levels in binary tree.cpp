//
//  average of levels in binary tree.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "average of levels in binary tree.hpp"
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

double average_vector(std::vector<double> vec){
    int N=vec.size();
    double sum=0;
    for(int i=0;i<N;i++){
        sum=sum+vec[i];
    }
    return sum/N;
}



std::queue<TreeNode*> next_level(std::queue<TreeNode*> current_level){
    std::queue<TreeNode*> output;
    TreeNode *top,*left_child,*right_child;
    while(!current_level.empty()){
        top=current_level.front();
        left_child=top->left;
        right_child=top->right;
        if(left_child!=NULL){
            output.push(left_child);
        }
        if(right_child!=NULL){
            output.push(right_child);
        }
        current_level.pop();
    }
    return output;
}




vector<double> averageOfLevels(TreeNode *root) {
    std::queue<TreeNode*> current_level,next_lvl;
    current_level.push(root);
    std::vector<double> output,single_level;
    TreeNode *top;
    double average;
    while(!current_level.empty()){
        next_lvl=next_level(current_level);
        while(!current_level.empty()){
            top=current_level.front();
            single_level.push_back(top->val);
            current_level.pop();
        }
        average=average_vector(single_level);
        single_level.clear();
        output.push_back(average);
        current_level=next_lvl;
    }
    return output;
    
}
