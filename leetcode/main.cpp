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
    string str("hello");
    cout<<str<<endl;
    vector<int> numbers = {1};
    solution s;
    
    cout<<s.f1(31)<<endl;
    
    s.generate(5);
    
    s.removeElement(numbers, 1);
    
    s.isPowerOfFour(16);
    
    s.reverseVowels(str);
    
    s.compareVersion("1.0.1", "1");
    
    ListNode* a = new ListNode(3);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(1);
    ListNode* d = new ListNode(0);
    
    a->next = b;b->next = c;c->next = d;
    s.reverseKGroup(a, 3);
    
    s.insertionSortList(a);
    
    vector<int> nums1 = {1,2},nums2 = {1,1};
    cout<<s.getExistNumber(nums1, 3)<<endl;
    s.intersect(nums1, nums2);
    
    
    numbers  = {0,1,2,4,5,7};
    s.summaryRanges(numbers);
    
    cout << s.minWindow("ab", "b")<<endl;

    cout<<s.mySqrt(2147395600)<<endl;

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