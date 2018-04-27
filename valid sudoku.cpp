//
//  valid sudoku.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "valid sudoku.hpp"
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>

//Given 9 by 9 grid of numbers ranging from 0 to 8, 
//such that not all positions are filled, 
//determine whether the grid is a valid Sudoku Grid

using namespace std;

class Solution {
public:

bool validate_array(int n,int key,std::vector<std::vector<char>> a){
    std::unordered_map<char,int> M;
    char tmp;
    bool answer=true;
    for (int i=0;i<9;i++){
        if(key==0){
            tmp=a[n][i];}
        else{
            tmp=a[i][n];
        }
        if ((tmp!='.')&&(M.count(tmp)==0)){
            M.insert(std::pair<char,int>(tmp,i));
            continue;
        }
        else if (tmp=='.'){continue;}
        else
            
            answer=false;
        break;
        
    }
    return(answer);
}

bool validate_row_column(int n,int key,std::vector<std::vector<char>> a){
    bool answer=true;
    std::unordered_map<char,int> M;
    if (key==0){
        for(int i=0;i<9;i++){
            if ((a[n][i]!='.')&&(M.count(a[n][i])==0)){
                M.insert(std::pair<char,int>(a[n][i],n));
            }
            else if(a[n][i]=='.'){
                continue;
            }
            else{
                answer=false;
                return(false);
                break;}
        }
        
        if (answer==false){
            return(false);}
        else{
            return(true);}}
    else{
        for(int i=0;i<9;i++){
            if ((a[i][n]!='.')&&(M.count(a[i][n])==0)){
                M.insert(std::pair<char,int>(a[i][n],n));
            }
            else if(a[i][n]=='.'){
                continue;
            }
            else{
                answer=false;
                return(false);
                break;}
        }}
    return(answer);
    
}


bool validate_square(int n,std::vector<std::vector<char>> a){
    int m=n%3;//a
    int k=(n-m)/3;//b
    int tmp;
    bool answer=true;
    std::unordered_map<char,int> M;
    for(int i=3*k;i<3*(k+1);i++){
        for(int j=3*m;j<3*(m+1);j++){
            tmp=a[i][j];
            if((tmp!='.')&&(M.count(tmp)==0)){
                M.insert(std::pair<char,int>(tmp,n));
            }
            else if (tmp=='.'){continue;}
            else{
                answer=false;
                break;}
        }
    }
    return(answer);
}



bool isValidSudoku(vector<vector<char>>& board) {
    bool answer=true;
    bool answer_partial=true;
    
    for (int i=0;i<9;i++){
        answer_partial=validate_array(i,0,board)&validate_array(i,1,board);
        if (answer_partial==false){
            answer=false;
            break;  }
        
        else
            continue;
    }
    if(answer==false){
        return(false);
    }
    
    else
        for(int j=0;j<9;j++){
            if (validate_square(j,board)==false){
                answer=false;
                break;
                
            }
            else
                continue;
        }
    return answer;
}
};
