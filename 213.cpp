#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);

    vector<int> a(nums.begin(), prev(nums.end())),
        b(next(nums.begin()), nums.end());
    int s = a.size();
    if(s == 2){
        return max(max(a[0],a[1]),max(b[0],b[1]));
    }
    a[s-3] += a[s-1];
    b[s-3] += b[s-1];

    if(s == 3){
        return max(max(a[0],a[1]),max(b[0],b[1]));
    }
    int tmp = -1;
    for (int i = s - 4, tmp = a[i + 3]; i >= 0; i--) {
        int t = a[i + 2];
        a[i] += max(t, tmp);
        tmp = t;
    }
    int amax = max(a[0],a[1]);
    for (int i = s - 4, tmp = b[i + 3]; i >= 0; i--) {
        int t = b[i + 2];
        b[i] += max(t, tmp);
        tmp = t;
    }
    int bmax = max(b[0],b[1]);
    return max(amax,bmax);
}

int main(int argc, char const *argv[])
{
    vector<int> v = {2,3,2};
    cout << rob(v)<< endl;
    return 0;
}
