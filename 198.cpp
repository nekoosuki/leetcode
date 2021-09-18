#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    int s = nums.size();
    if (s == 1){
        return nums[0];
    }
    if (s == 2) {
        return max(nums[0], nums[1]);
    }
    nums[s - 3] += nums[s - 1];
    if (s == 3) {
        return max(nums[0], nums[1]);
    }
    int tmp = -1;
    for (int i = s - 4, tmp = nums[i + 3]; i >= 0; i--) {
        int t = nums[i + 2];
        nums[i] += max(t, tmp);
        tmp = t;
    }
    return max(nums[0], nums[1]);
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,1};
    cout << rob(v) << endl;
    return 0;
}
