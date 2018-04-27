//
//  LRU Cache.cpp
//  Leetcode
//
//  Created by Antonio Ache on 4/27/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "LRU Cache.hpp"
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<unordered_map>
#include<list>

using namespace std;


// Goal: Create a Data Structure for the Last Recently Used Cache (LRU Cache).
// This Data Structure supports two operations: get(key), and put(key,value).
// and has a fixed capacity that we will denote by ''cap''.
// The function get(key) retrieves a key and returns its value if the key is
// already present and returns -1 if the key is not present. The function
// put(key,value) inserts a key with value "value" if the key is not present.
// If the capicity of the structure has been reached, the least recently used key
// will be evicted.

class LRUCache {
private:
std::unordered_map<int,std::list<std::pair<int,int>>::iterator> content;
std::list<std::pair<int,int>> least_used;
int cap;

// We will keep track of how recently each key has been used by means of a doubly linked list (least_used)
// so that the least recently used key occupies the "back" of the list and the most recently used key
// will occupy the "front" of the list.
// The structure "content" will consist of a map from keys to nodes in the linked list. This is to determine
// whether a given key is the least recently used key or not.
    
public:
LRUCache(int capacity) {
    cap=capacity;
    
}

int get(int key) {
    int result;
    std::pair<int,int> block,tmp;
    std::list<std::pair<int,int>>::iterator it;
    
    if(content.count(key)==0){
        return -1;
    }
    else{
        it=content.find(key)->second;
        tmp=*it;
        result=tmp.second;
        block.first=key;
        block.second=result;
        content.erase(content.find(key));
        least_used.erase(it);
        least_used.push_front(block);
        content.insert(std::pair<int,std::list<std::pair<int,int>>::iterator>(key,least_used.begin()));
        return result;
    }
}

void put(int key, int value) {
    int N=least_used.size();
    std::list<std::pair<int,int>>::iterator it,it_least;
    std::pair<int,int> least_pair,new_block;
    int key_least;
    if(content.count(key)>0){
        it=content.find(key)->second;
        new_block.first=key;
        new_block.second=value;
        content.erase(content.find(key));
        least_used.erase(it);
        least_used.push_front(new_block);
        content.insert(std::pair<int,std::list<std::pair<int,int>>::iterator>(key,least_used.begin()));
    }
    else{
        if(N==cap){
            least_pair=least_used.back();
            key_least=least_pair.first;
            content.erase(content.find(key_least));
            least_used.pop_back();
            new_block.first=key;
            new_block.second=value;
            least_used.push_front(new_block);
            content.insert(std::pair<int,std::list<std::pair<int,int>>::iterator>(key,least_used.begin()));
        }
        else{
            new_block.first=key;
            new_block.second=value;
            least_used.push_front(new_block);
            content.insert(std::pair<int,std::list<std::pair<int,int>>::iterator>(key,least_used.begin()));
        }
    }
}
};
