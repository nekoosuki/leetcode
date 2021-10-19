#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int s = nums.size();
        if (s < 3) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < s; i++) {
            if (nums.at(i) > 0) break;
            if (i > 0) {
                if (nums.at(i) == nums.at(i-1)) {
                    continue;
                }
            }
            int target = -nums.at(i);
            int p = i + 1, q = s - 1;
            while (p < q) {
                if (nums.at(p) + nums.at(q) > target) {
                    q--;
                } else if (nums.at(p) + nums.at(q) < target) {
                    p++;
                } else {
                    res.push_back({nums.at(p), nums.at(q), -target});
                    p++;
                    q--;
                    while (p < q && nums.at(p) == nums.at(p-1)) p++;
                    while (p < q && nums.at(q) == nums.at(q+1)) q--;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    auto res = s.threeSum(v);
    for(auto a :res){
        for(int e:a)
            cout << e << ',';
    }
    return 0;
}
