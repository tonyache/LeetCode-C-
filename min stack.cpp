//
//  min stack.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "min stack.hpp"
#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

class MinStack {
private:
    std::stack<int> backup;
public:
    /** initialize your data structure here. */
    std::stack<int> content;
    int running_minimum;
    
    
    MinStack() {
        //content;
        //backup;
        running_minimum=INFINITY;
    }
    
    void push(int x) {
        int top;
        if(content.empty()){
            running_minimum=x;
            content.push(x);
            backup.push(x);
        }
        else{
            top=backup.top();
            if (x<running_minimum){
                running_minimum=x;
                content.push(x);
                backup.push(x);
            }
            else{
                content.push(x);
                backup.push(top);
            }
        }
        
    }
    
    void pop() {
        int top;
        //top=content.top();
        if(content.empty()){
            return;
        }
        else{
            top=content.top();
            if(top==running_minimum){
                backup.pop();
                content.pop();
                if(backup.empty()){
                    running_minimum=INFINITY;
                }
                else{
                    running_minimum=backup.top();
                }
            }
            else{
                backup.pop();
                content.pop();
            }
        }
    }
    
    int top() {
        if(content.empty()){
            return INFINITY;
        }
        else{
            return content.top();
        }
    }
    
    int getMin() {
        return running_minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */