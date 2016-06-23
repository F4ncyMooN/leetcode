//
//  main.cpp
//  leetcode
//
//  Created by lvhao on 16/2/4.
//  Copyright © 2016年 lvhao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include "solution.hpp"
using namespace std;

int main(void)
{
    vector<vector<int>> tree;
    tree.resize(5);

    solution s;
    vector<int> array = {94,40,49,65,21,21,106,80,92,81,679,4,61,6,237,12,72,74,29,95,265,35,47,1,61,397,52,72,37,51,1,81,45,435,7,36,57,86,81,72};
    //cout<<s.getPermutation(9, 24)<<endl;
    cout<<s.hIndex(array)<<endl;
    
    vector<int> v = {1,2,2,3,2,1,1,3};
    vector<int> ttt = s.majorityElement2(v);
    for(int i=0;i<ttt.size();i++){
        cout<<ttt[i]<<endl;
    }
}