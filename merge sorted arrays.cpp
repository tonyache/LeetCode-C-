//
//  merge sorted arrays.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "merge sorted arrays.hpp"
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    std::vector<int> L,R;
    for(int i=0;i<m;i++){
        L.push_back(nums1[i]);
    }
    int inf=std::numeric_limits<int>::max();
    L.push_back(inf);
    for(int j=0;j<n;j++){
        R.push_back(nums2[j]);
    }
    R.push_back(inf);
    int a=0;
    int b=0;
    for(int k=0;k<n+m;k++){
        if(L[a]<=R[b]){
            nums1[k]=L[a];
            a++;
        }
        else{
            nums1[k]=R[b];
            b++;
        }
    }
}
};