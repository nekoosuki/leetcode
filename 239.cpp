#include <vector>
#include <iostream>
#include <deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> q;
        vector<int> res;
        for(int i=0;i<k;i++){
            if(q.empty()||nums[i]>q.back().second){
                q.push_front(make_pair(i,nums[i]));
            }
        }
        res.push_back(q.front().second);
        for(int i=k;i<nums.size();i++){
            while(q.back().first < i-k){
                q.pop_back();
            }
            q.push_front(make_pair(i,nums[i]));
            res.push_back(q.front().second);
        }
        return res;
    }
};