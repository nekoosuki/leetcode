#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            int value = nums[mid];
            if(value==target)return mid;
            if(value<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return -1;
    }
};