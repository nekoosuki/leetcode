#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int buy = prices[0], profit = 0;
    for (int i = 1; i < prices.size() - 1; i++) {
        buy = min(buy, prices[i]);
        if (prices[i] > buy + fee) {
            profit += prices[i] - buy - fee;
            //这步比较重要 让当天的买入不会有卖出的手续费
            //这样可以避免重复买入卖出在计算时造成多余手续费
            //当buy再次通过min表达式刷新的时候 代表A买入-B卖出-C买入-D卖出的收益大于A买入-D卖出 因为C买入带来的价差比手续费还高
            buy = prices[i] - fee;
        }
    }
    return max(profit, profit + prices[prices.size() - 1] - buy - fee);
}

int main(int argc, char const* argv[]) {
    vector<int> v = {4,5,5,2,4,3,5,5,2,3};
    cout << maxProfit(v, 3) << endl;
    return 0;
}
