//
//  main.cpp
//  leetcode
//
//  Created by lvhao on 16/2/4.
//  Copyright © 2016年 lvhao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "solution.hpp"
using namespace std;

int main(void)
{
    solution s;
    cout << s.minWindow("ab", "b")<<endl;

    cout<<s.mySqrt(2147395600)<<endl;
    vector<int> numbers;
    for(int i=0;i<10;i++){
        numbers.push_back(i);
    }
    numbers.erase(numbers.begin(),numbers.begin()+numbers.size()-1);

    vector<vector<int>> tree;
    tree.resize(5);

    vector<int> array = {94,40,49,65,21,21,106,80,92,81,679,4,61,6,237,12,72,74,29,95,265,35,47,1,61,397,52,72,37,51,1,81,45,435,7,36,57,86,81,72};
    //vector<int> array = {0,1,3,5,6};
    //cout<<s.getPermutation(9, 24)<<endl;
    cout<<s.hIndex(array)<<endl;
    
    vector<int> v = {1,2,2,3,2,1,1,3};
    vector<int> ttt = s.majorityElement2(v);
    for(int i=0;i<ttt.size();i++){
        cout<<ttt[i]<<endl;
    }
}