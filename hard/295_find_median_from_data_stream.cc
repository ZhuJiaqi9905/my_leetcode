#include <bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
  priority_queue<int, vector<int>, less<int>> low_;
  priority_queue<int, vector<int>, greater<int>> high_;
  MedianFinder() {}

  void addNum(int num) {
    if (low_.empty() || num <= low_.top()) {
      low_.emplace(num);
      if (low_.size() > high_.size() + 1) {
        high_.emplace(low_.top());
        low_.pop();
      }
    } else {
      high_.emplace(num);
      if (high_.size() > low_.size()) {
        low_.emplace(high_.top());
        high_.pop();
      }
    }
  }

  double findMedian() {
    if (low_.size() == high_.size()) {
      return (static_cast<double>(low_.top()) +
              static_cast<double>(high_.top())) /
             2;
    } else {
      return static_cast<double>(low_.top());
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */