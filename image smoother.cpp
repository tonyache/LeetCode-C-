//
//  image smoother.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "image smoother.hpp"
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
    int row=M.size();
    int col=M[0].size();
    std::vector<std::vector<int>> output;
    std::vector<int> row_vector;
    for(int i=0;i<col;i++){
        row_vector.push_back(0);
    }
    for(int j=0;j<row;j++){
        output.push_back(row_vector);
    }
    int n;
    int sum;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            n=0;
            sum=0;
            for(int k=-1;k<=1;k++){
                for(int l=-1;l<=1;l++){
                    if((i+k>=0)&&(i+k<row)&&(j+l>=0)&&(j+l<col)){
                        n++;
                        sum=sum+M[i+k][j+l];
                    }
                }
            }
            output[i][j]=floor(sum/n);
        }
    }
    return output;
}