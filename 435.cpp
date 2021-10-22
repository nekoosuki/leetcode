#include <vector>
#include <algorithm>
using namespace std;
//和56比较像
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int count = 1;
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] >= end){
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size()-count;
    }
};