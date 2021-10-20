#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    static bool cmpleft(vector<int> a, vector<int> b) { return a[0] < b[0]; }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int s = intervals.size();
        if (s==0||s==1) return intervals;
        sort(intervals.begin(), intervals.end(), cmpleft);
        vector<vector<int>> res;
        int left = 0;
        int right = 1;
        while (right < s) {
            if (intervals[left][1] >= intervals[right][0]) {
                intervals[left] = {intervals[left][0], max(intervals[right][1],intervals[left][1])};
                if (right == s - 1) res.push_back(intervals[left]);
            } else {
                res.push_back(intervals[left]);
                left = right;
                if (right == s - 1) res.push_back(intervals[right]);
            }
            right++;
        }
        return res;
    }
};