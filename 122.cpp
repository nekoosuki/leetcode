#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int buy = prices[0], profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        buy = min(buy, prices[i]);
        if (i == prices.size() - 1) {
            profit += prices[i] - buy;
        } else if (prices[i + 1] < prices[i]) {
            profit += prices[i] - buy;
            buy = 10001;
        }
    }
    return profit;
}

int main(int argc, char const* argv[]) {
    vector<int> v = {1,2};
    cout << maxProfit(v) << endl;
    return 0;
}
