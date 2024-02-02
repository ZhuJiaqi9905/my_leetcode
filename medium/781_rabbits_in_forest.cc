#include <bits/stdc++.h>
using namespace std;
// 如果有y只兔子都回答x个和它同色，则至少有 ceil(y / (x+1))个颜色，每个颜色有(x+1)个兔子,
// 所以就至少有ceil(y/(x+1)) * (x+1)个兔子。
// ceil(a/b) = (a+b-1) / b

class Solution {
public:
  int numRabbits(vector<int> &answers) {
    unordered_map<int, int> cnt;
    for (auto x : answers) {
      cnt[x]++;
    }
    int ans = 0;
    for (auto &[x, y] : cnt) {
      ans += (y + (x + 1) - 1) / (x + 1) * (x + 1);
      // ans += ceil(1.0 * y / (x + 1)) * (x + 1);
    }
    return ans;
  }
};