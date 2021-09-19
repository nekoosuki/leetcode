#include <iostream>
#include <vector>

using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
    int maxscore = -1,left = 0;
    for(int i = 0; i<values.size();i++){
        maxscore = max(maxscore, left+values[i]-i);
        left = max(left, values[i]+i);
    }
    return maxscore;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {8,1,5,2,6};
    cout << maxScoreSightseeingPair(v) << endl;
    return 0;
}
