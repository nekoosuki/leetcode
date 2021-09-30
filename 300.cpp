#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int s = nums.size();
    int dp[s];
    for (int i = 0; i < s; i++) {
        dp[i] = 1;
    }
    for (int i = 1; i < s; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp,dp+s);
}

int main(int argc, char const* argv[]) {
    vector<int> v = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(v);
    return 0;
}
