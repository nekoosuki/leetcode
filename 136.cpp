#include <vector>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        for(int e:nums){
            a = a^e;
        }
        return a;
    }
};