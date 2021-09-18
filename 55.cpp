#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (i <= r) {
            r = max(r, i + nums[i]);
            if (r >= n - 1) {
                return true;
            }
        }
    }
    return false;
}

// bool canJump(vector<int>& nums) {
//     int s = nums.size();
//     int lastcan = s;
//     bool can[s];
//     for (int i = 0; i < s - 1; i++) {
//         can[i] = false;
//     }
//     can[s - 1] = true;

//     for (int i = 0; i < s; i++) {
//         if (can[0]) {
//             return true;
//         }
//         for (int j = lastcan - 2; j >= 0; j--) {
//             for (int k = 0; k <= nums[j]; k++) {
//                 if (j + k >= s) {
//                     break;
//                 }
//                 if (can[j + k]) {
//                     can[j] = true;
//                     lastcan = j;
//                     break;
//                 }
//             }
//         }
//     }
//     return false;
// }

int main(int argc, char const* argv[]) {
    vector<int> v = {2, 3, 1, 1, 4};
    if (canJump(v)) {
        cout << "can" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
