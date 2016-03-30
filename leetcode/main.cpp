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
    vector<int> v = {1,2,2,3,2,1,1,3};
    vector<int> ttt = s.majorityElement2(v);
    for(int i=0;i<ttt.size();i++){
        cout<<ttt[i]<<endl;
    }
}