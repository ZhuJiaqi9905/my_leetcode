#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    vector<int> stk;
    for (auto &token : tokens) {
      if (token == "+") {
        int b = stk.back();
        stk.pop_back();
        int a = stk.back();
        stk.pop_back();
        stk.push_back(a + b);
      } else if (token == "-") {
        int b = stk.back();
        stk.pop_back();
        int a = stk.back();
        stk.pop_back();
        stk.push_back(a - b);
      } else if (token == "*") {
        int b = stk.back();
        stk.pop_back();
        int a = stk.back();
        stk.pop_back();
        stk.push_back(a * b);
      } else if (token == "/") {
        int b = stk.back();
        stk.pop_back();
        int a = stk.back();
        stk.pop_back();
        stk.push_back(a / b);
      } else {
        stk.push_back(stoi(token));
      }
    }
    return stk.back();
  }
};