#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int s = prices.size();
    int state[s][3];
    state[0][0] = -prices[0];
    state[0][1] = 0;
    state[0][2] = 0;
    for(int i=1;i<s;i++){
        state[i][0] = max(state[i-1][0], state[i-1][2]-prices[i]);
        state[i][1] = state[i-1][0] + prices[i];
        state[i][2] = max(state[i-1][1], state[i-1][2]);
    }
    return max(state[s-1][1],state[s-1][2]);
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,0,2};
    cout << maxProfit(v) << endl;
    return 0;
}
