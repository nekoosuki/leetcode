#include <vector>

using namespace std;
//摩尔投票
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,n=0;
        for(int e:nums){
            if(count==0){
                n=e;
                count++;
            }else{
                e==n?count++:count--;
            }
        }
        return n;
    }
};