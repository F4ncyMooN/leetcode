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
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

class solution{
public:
    //leet 350
    int getExistNumber(const vector<int>& base, int num){
        auto lower = lower_bound(base.begin(),base.end(),num);
        auto upper = upper_bound(base.begin(),base.end(),num);
        return upper - lower;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>& base = nums2, &search = nums1;
        vector<int> common;
        int target = 0, number = 0, repeatition = 0;
        if(nums1.size()>nums2.size()){
            swap(base,search);
        }
        if(search.size() == 0)
            return common;
        target = *search.begin();
        for(auto iter = search.begin();iter!=search.end();iter++){
            if(target == *iter){
                number++;
            }else{
                repeatition = min(number,getExistNumber(base,target));
                for(int i = 0;i<repeatition;i++){
                    common.push_back(target);
                }
                number = 1;
                target = *iter;
            }
        }
        repeatition = min(number,getExistNumber(base,target));
        for(int i = 0;i<repeatition;i++){
            common.push_back(target);
        }
        return common;
    }
    //leet 349
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection;
        auto end1 = unique(nums1.begin(), nums1.end());
        auto end2 = unique(nums2.begin(), nums2.end());
        sort(nums2.begin(), end2);
        for(auto iter = nums1.begin();iter != end1;iter++){
            auto position = find(nums2.begin(),end2,*iter);
            if(position != end2){
                intersection.push_back(*position);
            }
        }
        
        return intersection;
    }
    //leet 283
    void moveZeroes(vector<int>& nums) {
        auto first_zero = nums.end();
        auto iter = nums.begin();
        int zero_num = 0;
        while(iter != nums.end()){
            if(*iter == 0){
                first_zero = iter;
                iter++;
                zero_num = 1;
                break;
            }
            iter++;
        }
        
        for(;iter!=nums.end();iter++){
            if(*iter != 0){
                *first_zero = *iter;
                *iter = 0;
                if(zero_num == 1){
                    first_zero = iter;
                }else{
                    first_zero++;
                }
            }else{
                zero_num++;
            }
        }
        
    }
    //leet 8
    bool checkOverflow(int num, int digit){
        if(num > 0){
            if(num < INT_MAX/10)
                return false;
            else if(num == INT_MAX/10){
                if(digit > INT_MAX - num*10)
                    return true;
            }else{
                return true;
            }
        }else{
            if(num > INT_MIN/10)
                return false;
            else if(num == INT_MIN/10){
                if(digit > num*10 - INT_MIN)
                    return true;
            }else{
                return true;
            }
        }
        return false;
    }
    int myAtoi(string str) {
        int sign = 1;
        int num = 0;
        //escape blanks
        auto iter = str.begin();
        while(*iter == ' '){iter++;}
        
        //check sign
        if(*iter == '+'){
            iter++;
        }else if(*iter == '-'){
            iter++;
            sign = -1;
        }
        for(;iter != str.end();iter++){
            if(*iter > '9' || *iter<'0')
                return num;
            if(checkOverflow(num,*iter-'0')){
                if(num>0)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            
            
            num = num>=0 ? num*10 + (*iter-'0'):num*10 - (*iter-'0');
            
            if(sign == -1 && num!=0){
                num*=-1;
                sign = 1;
            }
        }
        return num;
    }
    
    //leet 228
    vector<string> summaryRanges(vector<int>& nums) {
        stringstream ss;
        vector<string> ranges;
        int start = INT_MIN,end = 0;
        int now;
        if(nums.empty())
            return ranges;
        for(auto iter = nums.begin();iter!=nums.end();iter++){
            now = *iter;
            if(iter == nums.begin()){
                start = *iter;
                end = *iter;
            }else{
                if(now == end+1){
                    end = *iter;
                }else{
                //find sub range.
                    ss.str("");
                    ss<<start;
                    if(start != end){
                        ss<<"->"<<end;
                    }
                    ranges.push_back(ss.str());
                    start = now;
                    end = now;
                }
            }
        }
        ss.str("");
        ss<<start;
        if(start != end){
            ss<<"->"<<end;
        }
        ranges.push_back(ss.str());
        
        return ranges;
    }
    //leet69
    int mySqrt(int x) {
        if(x == 1 || x == 0)
            return x;
        int upper = 46340;
        int lower = 0;
        int now = 0;
        int mult = 0;
        while(upper>lower){
            if(upper == lower+1)
                return upper*upper<=x?upper:lower;
            now = (lower+upper)/2;
            mult = now*now;
            if(mult > x){
                upper = now;
            }else if(mult == x){
                return now;
            }
            else{
                lower = now;
            }
        }
        return now;
    }
    
    //leet 76
    bool inline canShrink(const char c,const map<char,int>& target){
        if(target.find(c) == target.end()){
            return true;
        }else{
            if(target.at(c) < 0){
                return true;
            }else{
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int minSize = INT_MAX;
        string minString = "";
        int start = 0,end = 0;
        int validNum = 0;
        map<char,int> target;
        for(auto iter = t.begin();iter!=t.end();iter++){
            target[*iter]++;
            validNum++;
        }
        //find first valid min Sequence.
        for(int i = 0;validNum != 0 && i < s.size();i++){
            if(target.find(s[i]) != target.end()){
                if(target.at(s[i]) > 0)
                    validNum--;
                target[s[i]]--;
            }
            end++;
        }
        if(validNum > 0)
            return "";
        for(int i=0;true;i++){
            if(!canShrink(s[i], target)){
                break;
            }else{
                target.find(s[i]) == target.end()?i:target.at(s[i])++;
                start++;
            }
        }
        
        minSize = end-start;
        minString = s.substr(start,minSize);
        
        
        int size = 0;
        //keep valid and record all possible Sequence.
        //be careful when end reach the string's end.
        while(canShrink(s[start], target) || end != s.end()-s.begin()){
            if(canShrink(s[start],target)){
                if(target.find(s[start]) != target.end()){
                    target.at(s[start])++;
                }
                start++;
            }else{
                if(target.find(s[end]) != target.end()){
                    target[s[end]]--;
                }
                end++;
            }
            size = end-start;
            if(size < minSize){
                minSize = size;
                minString = s.substr(start,minSize);
            }
        }
        
        return minString;
    }
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
    
    //leet60
    struct node{
        int number;
        struct node * next;
    };
    string getPermutation(int n, int k){
        string ret;
        int array[10]={0};
        array[0]=1;
        
        for(int i=1;i<n;i++){
            array[i]=array[i-1]*(i+1);
        }
        node *head = (node *)(malloc(sizeof(node)));
        node *p;
        for(int i=n;i>=1;i--){
            node * now = head->next;
            p = (node *)(malloc(sizeof(node)));
            p->number = i;
            p->next = now;
            head->next = p;
        }
        for(int i=n-2;i>=0;i--){
            int mod = (k-1)/array[i];
            node *prev;
            prev = head;
            for(int j = 0;j<mod;j++){
                prev = prev->next;
            }
            p = prev->next;
            ret += p->number+'0';
            //free p
            prev->next = p->next;
            free(p);
            
            k -= mod * array[i];
        }
        ret += head->next->number+'0';
        free(head->next);
        free(head);
        
        return ret;
    }
    //leet242
    bool isAnagram(string s, string t){
        int count1[256]={0};
        int count2[256]={0};
        for_each(s.begin(),s.end(),[&](char c){count1[c]++;});
        for_each(s.begin(),s.end(),[&](char c){count2[c]++;});
        for(int i=0;i<256;i++){
            if(count1[i]!=count2[i])return false;
        }
        return true;
    }
    
    
    //leet274,275
    template<class ForwardIt, class T, class Compare>
    ForwardIt my_upper_bound(ForwardIt first, ForwardIt last, const T& value,Compare comp)
    {
        ForwardIt it;
        typename std::iterator_traits<ForwardIt>::difference_type count, step;
        count = std::distance(first,last);
        
        while (count > 0) {
            it = first;
            step = count / 2;
            std::advance(it, step);
            if (!comp(value , it)) {
                first = ++it;
                count -= step + 1;
            } else count = step;
        }
        return first;
    }
    
    int hIndex(vector<int>& citations) {
        //O(n)，降序时取i+1 <= citations[i]的最大值 h=i+1
//        sort(citations.begin(),citations.end(),[](int a,int b){return a>b;});
//        int h=0;
//        for(int i=0;i<citations.size();i++){
//            if(i+1 <= citations[i]){
//                h = i+1;
//            }else{
//                break;
//            }
//        }
//        return h;
        //O(logn)，升序时取N-i>=citations[i]的最大值 h=N-i
        sort(citations.begin(),citations.end(),[](int a,int b){return a<b;});
        int h=(int)citations.size();
        vector<int>::iterator iter = my_upper_bound(citations.begin(), citations.end(), h, [&h,&citations](int value,vector<int>::iterator it){
            int h = (it-citations.begin());
            return *it >= citations.size()-(it-citations.begin());
        });
        return (int)(citations.size()-(iter-citations.begin()));
    }
    
    
    
};

#endif /* solution_hpp */
