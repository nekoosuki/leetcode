#include <unordered_map>
#include <vector>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    unordered_map<int,int> inter;
    for(int i : nums1){
        inter[i]++;
    }
    for(int i : nums2){
        if(inter[i] > 0){
            res.push_back(i);
            inter[i]--;
        }
    }
    return res;
}
