#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    inline static int abs(int a) { return a < 0 ? -a : a; }
    vector<int> sortedSquares(vector<int>& nums) {
        if (nums[0] >= 0) {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] *= nums[i];
            }
            return nums;
        } else if (nums[nums.size() - 1] <= 0) {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] *= nums[i];
            }
            reverse(nums.begin(),nums.end());
            return nums;
        }
        vector<int> res;
        int i = 0, j = 1;
        while (!(nums[i] < 0 && nums[j] >= 0)) {
            i++;
            j++;
        }
        while (i >= 0 && j <= nums.size() - 1) {
            if (abs(nums[i]) > abs(nums[j])) {
                res.push_back(nums[j] * nums[j]);
                j++;
            } else {
                res.push_back(nums[i] * nums[i]);
                i--;
            }
        }
        if (i < 0) {
            while (j <= nums.size() - 1) {
                res.push_back(nums[j] * nums[j]);
                j++;
            }
        } else {
            while (i >= 0) {
                res.push_back(nums[i] * nums[i]);
                i--;
            }
        }
        return res;
    }
};