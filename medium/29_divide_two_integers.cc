#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int divide(int dividend, int divisor) {
    // 被除数是最小值
    if (dividend == INT_MIN) {
      if (divisor == 1) {
        return INT_MIN;
      }
      if (divisor == -1) {
        return INT_MAX;
      }
    }
    // 除数是最小值
    if (divisor == INT_MIN) {
      return dividend == INT_MIN ? 1 : 0;
    }
    // 被除数是0
    if (dividend == 0) {
      return 0;
    }

    // 将所有正数取相反数, 全转化为负数做，因为-INT_MIN无法表示
    bool rev = false;
    if (dividend > 0) {
      dividend = -dividend;
      rev = !rev;
    }
    if (divisor > 0) {
      divisor = -divisor;
      rev = !rev;
    }

    vector<int> candidates = {divisor};

    while (candidates.back() >= dividend - candidates.back()) {
      candidates.push_back(candidates.back() + candidates.back());
    }
    int ans = 0;
    for (int i = candidates.size() - 1; i >= 0; --i) {
      if (candidates[i] >= dividend) {
        ans += (1 << i);
        dividend -= candidates[i];
      }
    }
    return rev ? -ans : ans;
  }
};