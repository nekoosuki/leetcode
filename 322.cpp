#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    if(amount == 0){
        return 0;
    }
    if(coins.size() == 0){
        return -1;
    }
    int dp[amount+1];
    for(int i=0;i<=amount;i++){
        dp[i]=INT32_MAX-1;
    }
    dp[0] = 0;
    for(int i =1;i<=amount;i++){
        for(int coin:coins){
            dp[i] = min(dp[i],dp[i-coin]+1);
        }
    }
    return dp[amount] == INT32_MAX-1?-1:dp[amount];
}
int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,5};
    cout << coinChange(v,11);
    return 0;
}