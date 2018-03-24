//
//  majority element.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "majority element.hpp"
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int N=nums.size();
        int i=0;
        int m=std::numeric_limits<int>::max();
        for(int j=0;j<N;j++){
            if(i==0){
                m=nums[j];
                i++;
            }
            else if(m==nums[j]){
                i++;
            }
            else{
                i--;
            }
        }
        return m;
    }
};