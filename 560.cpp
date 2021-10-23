#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int e : nums) {
            sum += e;
            res += m[sum - k];
            m[sum]++;
        }
        return res;
    }
};