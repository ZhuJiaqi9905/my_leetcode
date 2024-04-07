#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  char nums[9]; // nums[i] = i - 1
  int s[10];    // s[i]是i个元素的全排列个数
  int visit[9];
  int k;
  int n;
  string ans;
  string tmp_ans;
  int iter{0}; // 统计当前情况是第几个全排列
  string getPermutation(int n, int k) {
    // 特殊处理
    if (n == 1) {
      return "1";
    }
    this->n = n;
    this->k = k;
    s[1] = 1;
    for (int i = 2; i <= 9; ++i) {
      s[i] = s[i - 1] * i;
    }
    for (int i = 0; i < 9; ++i) {
      nums[i] = '1' + i;
      visit[i] = 0;
    }

    dfs(0);
    return ans;
  }
  void dfs(int idx) {
    if (idx == n) {
      ans = tmp_ans;
      return;
    }
    int t = s[n - idx - 1]; // 剩下的元素能构成的排列个数
    for (int i = 0; i < n; ++i) {
      if (!visit[i]) {
        if (iter + t < k) {
          iter += t;
          continue;
        }
        if (t == 1) { // 这里是因为它是要填的最后一个数了，需要占一个编号
          iter++;
        }
        if (iter > k) { // 剪枝
          break;
        }
        // 想用第i个元素
        visit[i] = true;
        tmp_ans += nums[i];
        dfs(idx + 1);
        tmp_ans.pop_back();
        visit[i] = false;
      }
    }
  }
};