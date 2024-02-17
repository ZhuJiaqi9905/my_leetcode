#include <bits/stdc++.h>
using namespace std;
#include <gtest/gtest.h>
class Solution {
public:
  vector<int> prisonAfterNDays(vector<int> &cells, int n) {
    int s = 8;
    unsigned int bin = 0;
    for (int i = 0; i < s; ++i) {
      bin *= 2;
      bin += cells[i];
    }
    vector<int> table(256, 0); // 记录每次变换的状态
    // 先变换1次，能够有效减小枚举的次数，因为头尾的值一定是0。如果初始状态中头尾有1，那么很难到达初始状态
    bin = (~((bin << 1) ^ (bin >> 1))) & 0x7E; 
    table[0] = bin;
    unsigned int start = bin;
    for (int i = 1; i < n; ++i) {
      bin = (~((bin << 1) ^ (bin >> 1))) & 0x7E;
      if (bin == start) {
        bin = table[(n - 1) % i]; // 先变换了1次，还剩n-1次
        break;
      } else {
        table[i] = bin;
      }
    }
    for (int i = s - 1; i >= 0; --i) {
      cells[i] = (bin & 1);
      bin = bin >> 1;
    }
    return cells;
  }
};
int main() {
  Solution s1;
  vector<int> c1 = {0, 1, 0, 1, 1, 0, 0, 1};
  vector<int> a1 = {0, 0, 1, 1, 0, 0, 0, 0};
  EXPECT_EQ(s1.prisonAfterNDays(c1, 7), a1);

  Solution s2;
  vector<int> c2 = {1,0,0,1,0,0,1,0};
  vector<int> a2 = {0,0,1,1,1,1,1,0};
  EXPECT_EQ(s2.prisonAfterNDays(c2, 1000000000), a2);
}