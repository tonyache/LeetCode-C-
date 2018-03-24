//
//  Best Time to Buy and Sell Stock II.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "Best Time to Buy and Sell Stock II.hpp"
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;
int maxProfit(vector<int>& prices) {
    int N=prices.size();
    int profits=0;
    for(int i=1;i<N;i++){
        if(prices[i]>prices[i-1]){
            profits=profits+(prices[i]-prices[i-1]);
        }
    }
    return profits;
}
