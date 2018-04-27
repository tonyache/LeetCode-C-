//
//  Ransome Note.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//


//Given an arbitrary ransom note string and another string containing letters from all the magazines, 
//write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
//Each letter in the magazine string can only be used once in your ransom note.



#include "Ransome Note.hpp"
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;


bool canConstruct(string ransomNote, string magazine) {
    bool answer=true;
    std::unordered_map<char,int> table;
    char c;
    int freq;
    for(std::string::iterator it=magazine.begin();it!=magazine.end();it++){
        c=*it;
        if(table.count(c)==0){
            table.insert(std::pair<char,int>(c,1));
        }
        else{
            freq=table.find(c)->second;
            table.find(c)->second=freq+1;
        }
    }
    for(std::string::iterator it=ransomNote.begin();it!=ransomNote.end();it++){
        char c=*it;
        if(table.count(c)>0){
            freq=table.find(c)->second;
            if(freq>1){
                table.find(c)->second=freq-1;
            }
            else{
                table.erase(table.find(c));
            }
        }
        else{
            answer=false;
            break;
        }
        
    }
    return answer;
}
