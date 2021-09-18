#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    vector<int> maxSum(nums);
    vector<int> minSum(nums);
    for (int i = maxSum.size() - 2; i >= 0; i--) {
        if (maxSum.at(i + 1) > 0) {
            maxSum.at(i) += maxSum.at(i + 1);
        }
        if (minSum.at(i + 1) < 0) {
            minSum.at(i) += minSum.at(i + 1);
        }
    }
    int sum = 0;
    bool hasP = false;
    for (int e : nums) {
        sum += e;
        if (e > 0) {
            hasP = true;
        }
    }
    if (hasP)
        return max(*max_element(maxSum.begin(), maxSum.end()),
                   sum - *min_element(minSum.begin(), minSum.end()));
    else
        return *max_element(nums.begin(), nums.end());
}