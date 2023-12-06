#include <vector>
using namespace std;
/// 维护一个普通栈和一个元素单调递减的栈
class MinStack {
public:
  vector<int> stk_;
  vector<int> min_stk_;
  MinStack() {}

  void push(int val) {
    stk_.emplace_back(val);
    if (min_stk_.empty() || min_stk_.back() >= val) {
      min_stk_.emplace_back(val);
    }
  }

  void pop() {
    int val = stk_.back();
    stk_.pop_back();
    if (val == min_stk_.back()) {
      min_stk_.pop_back();
    }
  }

  int top() { return stk_.back(); }

  int getMin() { return min_stk_.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */