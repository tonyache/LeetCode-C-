//
//  Hamming Distance.cpp
//  Leetcode
//
//  Created by Antonio Ache on 3/24/18.
//  Copyright © 2018 Antonio Ache. All rights reserved.
//

#include "Hamming Distance.hpp"

int hammingDistance(int x, int y) {
    int z=x^y;
    int count=0;
    while(z!=0){
        if (z%2==1){
            z=z>>1;
            count++;
        }
        else
            z=z>>1;
    }
    return count;
}