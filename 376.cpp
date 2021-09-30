#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// int wiggleMaxLength(vector<int>& nums) {
//     int s = nums.size();
//     int dp[s];
//     bool sign[s];
//     for (int i = 0; i < s; i++) {
//         dp[i] = 1;
//         sign[i] = true;
//     }
//     for (int i = 1; i < s; i++) {
//         for (int j = 0; j < i; j++) {
//             if (nums[i] > nums[j] && sign[j] == true) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//                 sign[i] = false;
//             }
//             if (nums[i] < nums[j] && sign[j] == false) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//                 sign[i] = true;
//             }
//         }
//     }
//     for (int i = 0; i < s; i++) {
//         // dp[i] = 1;
//         sign[i] = false;
//     }
//     for (int i = 1; i < s; i++) {
//         for (int j = 0; j < i; j++) {
//             if (nums[i] > nums[j] && sign[j] == true) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//                 sign[i] = false;
//             }
//             if (nums[i] < nums[j] && sign[j] == false) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//                 sign[i] = true;
//             }
//         }
//     }
//     return *max_element(dp,dp+s);
// }

int wiggleMaxLength(vector<int>& nums) {
    //似乎思维固化了
    int s = nums.size();
    int up = 1, down = 1;
    for (int i = 1; i < s; i++) {
        if (nums[i] > nums[i - 1]) {
            up = down + 1;
        } else if (nums[i] < nums[i - 1]) {
            down = up + 1;
        }
    }
    return max(up, down);
}
int main(int argc, char const* argv[]) {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << wiggleMaxLength(v);
    return 0;
}
