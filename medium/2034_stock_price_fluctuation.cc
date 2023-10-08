#include <gtest/gtest.h>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
/// multiset<T>中使用erase(value)方法删除元素，会删除所有的val相同的元素。如果想只删除一个元素，需要用erase(iterator)的方式删除。
class StockPrice {
public:
  StockPrice() { maxTimestamp_ = 0; }

  void update(int timestamp, int price) {
    auto it = stockMap_.find(timestamp);
    if (it == stockMap_.end()) {
      prices_.insert(price);
      stockMap_.emplace(timestamp, price);
      maxTimestamp_ = std::max(maxTimestamp_, timestamp);
    } else {
      auto pIt = prices_.find(it->second);
      if (pIt != prices_.end()) {
        prices_.erase(pIt);
      }
      prices_.insert(price);
      it->second = price;
    }
  }

  int current() { return stockMap_[maxTimestamp_]; }

  int maximum() { return *prices_.rbegin(); }

  int minimum() { return *prices_.begin(); }

  int maxTimestamp_;
  multiset<int> prices_;
  unordered_map<int, int> stockMap_;
};

int main() {}