//
//  Degree of an Array.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/25/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "Degree of an Array.hpp"
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int findShortestSubArray(vector<int>& nums){
    std::unordered_map<int,int> table;
    std::unordered_set<int> most_freq;
    std::pair<int,int> last_pair;
    int max_freq=1;
    int output;
    int N=nums.size();
    int freq;
    if(N==1){
        return 1;
    }
    else{
        for(int i=0;i<N;i++){
            if(table.count(nums[i])==0){
                table.insert(std::pair<int,int>(nums[i],1));
            }
            else{
                freq=table.find(nums[i])->second;
                table.find(nums[i])->second=freq+1;
                max_freq=std::max(max_freq,freq+1);
            }
        }
        
        for(std::unordered_map<int,int>::iterator it=table.begin();it!=table.end();it++){
            if(it->second==max_freq){
                most_freq.insert(it->first);
            }
        }
        if(max_freq==1){
            return 1;
        }
        else{
            int start=0;
            int end=N-1;
            while(!most_freq.empty()&&(start<end)){
                last_pair.first=start;
                last_pair.second=end;
                if(most_freq.count(nums[start])==0){
                    start++;
                }
                else if(most_freq.count(nums[end])==0){
                    end--;
                }
                else{
                    if(nums[start+1]==nums[start]||(most_freq.count(nums[start+1]))==0){
                        most_freq.erase(most_freq.find(nums[start]));
                        start++;
                    }
                    else if(nums[end-1]==nums[end]||(most_freq.count(nums[end-1])==0)){
                        most_freq.erase(most_freq.find(nums[end]));
                        end--;
                    }
                    else{
                        if(nums[start]==nums[end]){
                            most_freq.erase(most_freq.find(nums[start]));
                            start++;
                            end--;
                        }
                        else{
                            most_freq.erase(most_freq.find(nums[end]));
                            most_freq.erase(most_freq.find(nums[start]));
                            start++;
                            end--;}
                    }
                }}
            start=last_pair.first;
            end=last_pair.second;
            return end-start+1;
        }
        
        
    }
}