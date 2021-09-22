#include <iostream>
#include <vector>

using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) {
    int s = nums.size();
    if (s < 3) {
        return 0;
    }
    int diff[s - 1];
    for (int i = 0; i < s - 1; i++) {
        diff[i] = nums[i + 1] - nums[i];
    }
    int dp[s];
    dp[s - 1] = dp[s - 2] = 0;
    for (int i = s - 3; i >= 0; i--) {
        if (diff[i] == diff[i + 1]) {
            int d = diff[i];
            int stack = 0;
            for (int j = i + 1; j < s - 1; j++) {
                if (d == diff[j]) {
                    stack++;
                }else{
                    break;
                }
            }
            dp[i] = dp[i + 1] + stack;
        } else {
            dp[i] = dp[i + 1];
        }
    }
    return dp[0];
}

int main(int argc, char const* argv[]) {
    vector<int> v = {1, 2, 3, 4, 5, 0, 2, 4,5,6};
    cout << numberOfArithmeticSlices(v) << endl;
    return 0;
}
