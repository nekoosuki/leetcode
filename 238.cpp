#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int s = nums.size();
        vector<int> res(s,1);
        int left=1,right=1;
        for(int i=0;i<s;i++){
            res[i]*=left;
            left*=nums[i];
        }
        for(int i=s-1;i>=0;i--){
            res[i]*=right;
            right*=nums[i];
        }
        return res;
    }
};