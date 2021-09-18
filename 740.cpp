#include <iostream>
#include <vector>

using namespace std;

int deleteAndEarn(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    if (nums.size() == 2) {
        int d = nums[0] - nums[1];
        if (d == 1 || d == 0 || d == -1) {
            return max(nums[0], nums[1]);
        }
        return nums[0] + nums[1];
    }
    int a[10001];
    for (int i = 0; i < 10001; i++) {
        a[i] = 0;
    }
    for (int i = 0; i < nums.size(); i++) {
        a[nums[i]] += nums[i];
    }
    for (int i = 10001 - 3, tmp = a[i + 2]; i >= 0; i--) {
        int t = a[i + 2];
        a[i] += max(t, tmp);
        tmp = t;
    }
    return max(a[0], a[1]);
}

int main(int argc, char const* argv[]) {
    vector<int> v = {3,5};
    cout << deleteAndEarn(v) << endl;
    return 0;
}
