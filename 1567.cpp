#include <iostream>
#include <vector>

using namespace std;

int getMaxLen(vector<int>& nums) {
    int prev_changesign = 0;
    int prev_zero = 0;
    int maxlen = 0;
    int lastest_changesign = 10001;
    int change_time = 0;
    bool current_sign = true;
    nums.push_back(0);
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            if (current_sign) {
                maxlen = max(i - prev_zero, maxlen);
            } else {
                maxlen = max(prev_changesign - prev_zero, maxlen);
                maxlen = max(i - prev_changesign - 1, maxlen);
                maxlen = max(i - lastest_changesign, maxlen);
            }
            current_sign = true;
            change_time = 0;
            lastest_changesign = 10001;
            prev_changesign = i;
            prev_zero = i + 1;
        } else if (nums[i] < 0) {
            change_time++;
            if (change_time == 1) {
                lastest_changesign = i+1;
            }
            prev_changesign = i;
            current_sign = !current_sign;
        }
    }
    return maxlen;
}

int main(int argc, char const* argv[]) {
    vector<int> v = {5,-20,-20,-39,-5,0,0,0,36,-32,0,-7,-10,-7,21,20,-12,-34,26,2};
    cout << getMaxLen(v) << endl;
    return 0;
}
