#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   private:
    vector<vector<int>> res;

   public:
    void fullarr(vector<int>& nums, int start, int end) {
        if (start == end) {
            res.push_back(nums);
        } else {
            for (int i = start; i < end; i++) {
                swap(nums[start], nums[i]);
                fullarr(nums, start + 1, end);
                swap(nums[start], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        fullarr(nums, 0, nums.size());
        return res;
    }
};