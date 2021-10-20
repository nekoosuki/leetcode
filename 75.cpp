#include <vector>
using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        vector<int> bucket(3);
        for (int e : nums) {
            bucket[e]++;
        }
        int z = bucket[0];
        int o = bucket[1];
        int t = bucket[2];
        int i = 0;
        while (i < z) {
            nums[i++] = 0;
        }
        while (i < z + o) {
            nums[i++] = 1;
        }
        while (i < z + o + t) {
            nums[i++] = 2;
        }
    }
};