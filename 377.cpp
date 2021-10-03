#include <iostream> 
#include <vector>

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    unsigned int dp[target+1];
    dp[0] = 1;
    for(int i=1;i<=target;i++){
        dp[i] =0;
    }
    for(int i=0;i<=target;i++){
        for (int num:nums){
            if(i>=num){
                dp[i] += dp[i-num];
            }
        }
    }
    return dp[target];
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
