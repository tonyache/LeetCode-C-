//
//  Reverse Linked List II.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "Reverse Linked List II.hpp"

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>

using namespace std;



struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

ListNode* reverseBetween(ListNode* head, int m, int n) {
    int index=1;
    ListNode *original,*node;
    original=head;
    node=head;
    //find mth node;
    while(index<m){
        node=node->next;
        index++;
    }
    std::queue<ListNode*> Q;
    std::stack<int> stk;
    Q.push(node);
    int node_val=node->val;
    stk.push(node_val);
    for(int i=m+1;i<=n;i++){
        node=node->next;
        Q.push(node);
        node_val=node->val;
        stk.push(node_val);
    }
    ListNode *front;
    int top;
    while(!stk.empty()){
        front=Q.front();
        top=stk.top();
        front->val=top;
        stk.pop();
        Q.pop();
    }
    return original;
}