#include <cstddef>
#include <gtest/gtest.h>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
/// 这不需要dp
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    size_t n = prices.size();
    int minPrice = numeric_limits<int>().max();
    int profit = 0;
    for (size_t i = 0; i < n; ++i) {
      minPrice = min(minPrice, prices[i]);
      if (prices[i] > minPrice) {
        profit = max(profit, prices[i] - minPrice);
      }
    }
    return profit;
  }
};

int main() {
  Solution s1;
  vector<int> prices1 = {7, 1, 5, 3, 6, 4};
  EXPECT_EQ(s1.maxProfit(prices1), 5);
}