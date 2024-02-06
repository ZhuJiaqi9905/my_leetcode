#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
/// 素数筛
class Solution {
public:
  int countPrimes(int n) {
    vector<int> p(n + 1, 1);
    int ans = 0;
    for (uint64_t i = 2; i < n; ++i) {
      if (p[i]) {
        ans += 1;
        for (uint64_t j = i * i; j < n; j += i) {
          p[j] = 0;
        }
      }
    }
    return ans;
  }
};