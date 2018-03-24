//
//  Add Binary.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "Add Binary.hpp"
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;


std::vector<int> string_to_vec(std::string str){
    std::vector<int> output;
    char c,top;
    for(std::string::iterator it=str.begin();it!=str.end();it++){
        c=*it;
        if(c=='1'){
            output.push_back(1);
        }
        else {
            output.push_back(0);}
    }
    return output;
}

int carry(int a,int b){
    if ((a+b)>=2){
        return 1;
    }
    else return 0;
}

string addBinary(string a, string b) {
    std::vector<int> vec1,vec2,vec_max,vec_min;
    std::string output;
    int n_max,n_min;
    vec1=string_to_vec(a);
    vec2=string_to_vec(b);
    if(vec1.size()==vec2.size()){
        vec_max=vec1;
        vec_min=vec2;
        n_max=vec1.size();
        n_min=vec2.size();
    }
    else{
        vec_max=(vec1.size()>vec2.size())? vec1:vec2;
        vec_min=(vec1.size()<vec2.size())? vec1:vec2;
        n_max=vec_max.size();
        n_min=vec_min.size();
    }
    int carr=0;
    int tmp;
    for(int i=0;i<n_min;i++){
        tmp=(vec_max[n_max-1-i]+vec_min[n_min-1-i]+carr)%2;
        carr=carry(vec_max[n_max-1-i]+carr,vec_min[n_min-1-i]);
        vec_max[n_max-1-i]=tmp;
    }
    
    if(n_max>n_min){
        for(int i=n_max-n_min-1;i>=0;i--){
            tmp=(vec_max[i]+carr)%2;
            carr=carry(vec_max[i],carr);
            vec_max[i]=tmp;
        }
    }
    if (carr==1){
        output.push_back('1');
    }
    for(int i=0;i<n_max;i++){
        if(vec_max[i]==1){
            output.push_back('1');
        }
        else
            output.push_back('0');
    }
    return output;
}
