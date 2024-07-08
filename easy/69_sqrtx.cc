#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int mySqrt(int x) {
    if (x == 0 || x == 1) {
      return x;
    }
    int64_t l = 0;
    int64_t r = x;
    int64_t mid;
    while (l < r) {
      mid = l + (r - l + 1) / 2;
      auto res = mid * mid;
      if (res > x) {
        r = mid - 1;
      } else if (res == x) {
        return mid;
      } else {
        l = mid;
      }
    }
    return l;
  }
};