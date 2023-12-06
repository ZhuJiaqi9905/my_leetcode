#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  bool isValid(string s) {
    int n = s.size();
    if (n % 2 == 1) {
      return false;
    }

    unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};

    vector<char> stk;
    for (const auto &ch : s) {
      if (pairs.count(ch)) {
        if (stk.empty() || stk.back() != pairs[ch]) {
          return false;
        }
        stk.pop_back();
      } else {
        stk.push_back(ch);
      }
    }
    return stk.empty();
  }
};