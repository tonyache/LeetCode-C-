//
//  two sum.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "two sum.hpp"
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> M;
        int N=nums.size();
        vector<int> output;
        for(int i=0;i<N;i++){
            if(M.count(nums[i])==0){
                M.insert(std::pair<int,int>(nums[i],i));}
            if (M.count(target-nums[i])>0){
                int j=M.find(target-nums[i])->second;
                if(j==i){continue;}
                else
                    output.push_back(j);
                output.push_back(i);
                break;
            }
            else continue;
        }
        if (output.empty()){
            output.push_back(-1);
            output.push_back(-1);
        }
        return(output);
    }
    
};

