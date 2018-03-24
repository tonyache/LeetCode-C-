//
//  Palindrome Linked List.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "Palindrome Linked List.hpp"

 struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };


    bool palindrome_in_range(ListNode* &node,int N){
        ListNode *tmp,*prev,*next_ptr;
        bool partial_answer;
        int val1,val2;
        if(N==1){
            node=node->next;
            return true;
        }
        else if(N==2){
            val1=node->val;
            node=node->next;
            if(node->val==val1){
                node=node->next;
                return true;
            }
            else{
                return false;
            }
        }
        else{
            val1=node->val;
            node=node->next;
            partial_answer=palindrome_in_range(node,N-2);
            if(partial_answer==false){
                return false;
            }
            else{
                if(node->val==val1){
                    node=node->next;
                    return true;}
                else{
                    return false;
                }
            }
        }
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return true;
        }
        else{
            int N=0;
            ListNode* original=head;
            while(head!=NULL){
                N++;
                head=head->next;
            }
            return palindrome_in_range(original,N);}
    }