#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string multiply(string num1, string num2) {
    int m = num1.size();
    int n = num2.size();
    vector<int> ans(m + n, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[i + j] += (num1[m - i - 1] - '0') * (num2[n - j - 1] - '0');
      }
    }
    for (int i = 0; i < m + n - 1; ++i) {

      int carry = ans[i] / 10;
      ans[i] = ans[i] % 10;
      ans[i + 1] += carry;
    }
    string res;
    bool flag = false;
    for (int i = (m + n - 1); i >= 0; --i) {
      if (!flag && ans[i] != 0) {
        flag = true;
      }
      if (flag) {
        res += ('0' + ans[i]);
      }
    }
    if (!flag) {
      return "0";
    }
    return res;
  }
};
int main() {}