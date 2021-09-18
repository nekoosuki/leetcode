#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    vector<int> maxSum(nums);
    for(int i = maxSum.size()-2; i >= 0; i--){
        if(maxSum.at(i+1) > 0){
            maxSum.at(i) += maxSum.at(i+1);
        }
    }
    return *max_element(maxSum.begin(), maxSum.end());
}

int main(int argc, char const *argv[])
{
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    return 0;
}
