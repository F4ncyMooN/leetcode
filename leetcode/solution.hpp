//
//  solution.hpp
//  leetcode
//
//  Created by lvhao on 16/2/4.
//  Copyright © 2016年 lvhao. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

class solution{
public:
    //leetcode 4
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //size_t median = (nums1.size()+nums2.size())/2;
        size_t tNum1,tNum2;
        tNum1 = (nums1.size()+nums2.size())/2;
        tNum2 = (nums1.size()+nums2.size()+1)/2;
        double ret = findKthNumInSortedArrays(nums1,0,nums1.size(),
                                              nums2,0,nums2.size(),
                                              tNum1)+
        findKthNumInSortedArrays(nums1,0,nums1.size(),
                                 nums2,0,nums2.size(),
                                 tNum2);
        return ret/2;
    }
    double findKthNumInSortedArrays(vector<int>& nums1,int s1,int t1,
                                    vector<int>& nums2,int s2,int t2,
                                    size_t k){
        int median1 = nums1[(s1+t1)/2];
        int median2 = nums2[(s2+t2)/2];
        
        
        return 0;
    }
    //leetcode 209
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int length = (int)nums.size();
        int l=0,r=0;
        bool flag = false;
        while(r!=nums.size()){
            sum+=nums[r++];
            if(sum>=s){
                while(sum>=s){
                    sum-=nums[l++];
                }
                flag = true;
                length = min(length,r-l+1);
            }
        }
        length = flag?length:0;
        return length;
    }
    //leetcode225

    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }
    
    // Get the top element.
    int top() {
        return q.front();
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
    queue<int> q;
    
    
    //leetcode169
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(count == 0){
                majority = nums[i];
                count++;
            }else{
                majority == nums[i]?count++:count--;
            }
        }
        return majority;
    }
    
    //leetcode229
    vector<int> majorityElement2(vector<int>& nums) {
        vector<int> list;
        if(nums.size() == 0){
            return list;
        }else if (nums.size() == 1){
            list.push_back(nums[0]);
            return list;
        }else if (nums.size() == 2){
            list.push_back(nums[0]);
            if(nums[0] != nums[1]){
                list.push_back(nums[1]);
            }
            return list;
        }
        int count1=0,count2=0;
        int major1=nums[0],major2=nums[1];
        for(int i=0;i<nums.size();i++){
            if(major1 == nums[i]){
                count1++;
            }
            else if (major2 == nums[i]){
                count2++;
            }
            else if(count1 == 0){
                major1 = nums[i];count1++;
            }else if (count2 == 0){
                major2 = nums[i];count2++;
            }else{
                count1--;
                count2--;
            }
        }
        int size1=0,size2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == major1){
                size1++;
            }else if (nums[i] == major2){
                size2++;
            }
        }
        if(size1>nums.size()/3){
            list.push_back(major1);
        }
        if(size2>nums.size()/3){
            list.push_back(major2);
        }
        return list;
    }
    

    
};

#endif /* solution_hpp */