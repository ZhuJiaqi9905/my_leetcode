#include <gtest/gtest.h>
#include <limits>
#include <stack>
#include <unistd.h>
#include <vector>
using namespace std;
// 找数组中某元素之前，连续小于等于它的元素个数
class StockSpanner {
public:
  StockSpanner() {
    idx_ = -1;
    stk_.emplace(idx_, numeric_limits<int>().max());
  }

  int next(int price) {
    idx_++;
    while (price >= stk_.top().second) {
      stk_.pop();
    }
    int ret = idx_ - stk_.top().first;
    stk_.emplace(idx_, price);
    return ret;
  }

  int idx_;
  stack<pair<int, int>> stk_;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main() {}