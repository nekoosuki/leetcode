#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashTable;
    for(int i=0;i<nums.size();i++){
        auto index = hashTable.find(target - nums[i]);
        if(index != hashTable.end()){
            return {i, index->second};
        }
        hashTable[nums[i]] = i;
    }
    return {};
}