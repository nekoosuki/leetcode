#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums) {
    int s = nums.size();
    int maxp[s], minp[s];
    for(int i = 0; i<s;i++){
        maxp[i] = 0;
        minp[i] = 0;
    }
    maxp[0] = minp[0] = nums[0];
    for(int i = 1;i<s;i++){
        if(nums[i] > 0){
            maxp[i] = max(maxp[i-1] * nums[i], nums[i]);
            minp[i] = min(minp[i-1] * nums[i], nums[i]);
        }else if(nums[i] < 0){
            maxp[i] = max(minp[i-1] * nums[i], nums[i]);
            minp[i] = min(maxp[i-1] * nums[i], nums[i]);
        }else{
            maxp[i] = minp[i] = 0;
        }
    }
    return *max_element(maxp, maxp+s);
}

int main(int argc, char const *argv[])
{
    vector<int> v = {-2,0,-1,9,-1,0};
    cout << maxProduct(v) << endl;
    return 0;
}
