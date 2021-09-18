#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
    int s = nums.size();
    int step[s];
    for (int i = 0; i < s; i++) {
        step[i] = 10000;
    }
    step[0] = 0;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j <= nums[i]; j++) {
            if (i + j >= s) {
                break;
            }
            step[i + j] = min(step[i] + 1, step[i + j]);
        }
    }
    return step[s - 1];
}

int main(int argc, char const* argv[]) {
    vector<int> v = {2, 1};
    cout << jump(v) << endl;
    return 0;
}
