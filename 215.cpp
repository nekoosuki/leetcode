#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int,vector<int>,greater<int>> heap;
//         for(int num:nums){
//             heap.push(num);
//             if(heap.size()==k)heap.pop();
//         }
//         return heap.top();
//     }
// };

class Solution {
public:
    int quickselect(vector<int>& nums, int left, int right, int k){
        int idx= partition(nums, left, right);
        if(idx == k)return nums[k];
        return idx<k?quickselect(nums, idx+1, right,k):quickselect(nums, left, idx-1, k);
    }
    int partition(vector<int>& nums, int left, int right){
        int i=left,j=left;
        int p = nums[left];
        swap(nums[left],nums[right]);
        while(j!=right){
            if(p<=nums[j])j++;
            else swap(nums[i++],nums[j++]);
        }
        swap(nums[i],nums[right]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, 0, nums.size()-1, nums.size()-k);
    }
};
