#include <iostream>
#include <vector>

using namespace std;
/*
只要发现后一天价格比当天低就立刻卖出
然后买入后一天的
同时不断刷新买入价格 寻找最小的买入点
*/
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
