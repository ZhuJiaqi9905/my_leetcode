#include <bits/stdc++.h>
using namespace std;
/// 用两个队列实现栈
class MyStack {
public:
  queue<int> q1_;
  queue<int> q2_;
  MyStack() {}

  void push(int x) {
    q2_.push(x);
    while (!q1_.empty()) {
      q2_.push(q1_.front());
      q1_.pop();
    }
    swap(q1_, q2_);
  }

  int pop() {
    int val = q1_.front();
    q1_.pop();
    return val;
  }

  int top() { return q1_.front(); }

  bool empty() { return q1_.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main() {}