#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        multiset<pair<int, int>> st;
        for (auto b : buildings) {
            //用正负表示左右端点
            //按x坐标排序
            st.insert(make_pair(b[0], -b[2]));
            st.insert(make_pair(b[1], b[2]));
        }
        vector<vector<int>> ret;
        multiset<int> height{0};//打底
        int m = 0;
        for (auto s : st) {
            if (s.second < 0) height.insert(-s.second); // 矩形左侧
            else height.erase(height.find(s.second)); // 矩形右侧 把线删掉 它的高度也无效了
            if (m != *height.rbegin())
                //加了这条线后最大高度变了
                ret.push_back({s.first, *height.rbegin()});
            m = *height.rbegin();
        }
        return ret;
    }
};