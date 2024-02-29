#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int ans{0};
  int n{0};
  int maxLength(vector<string> &arr) {
    n = arr.size();
    vector<uint32_t> masks(n, 0); // 记录每个字符串拥有的字母

    for (int i = 0; i < n; ++i) {
      auto &mask = masks[i];
      for (auto ch : arr[i]) {
        ch -= 'a';
        if ((mask >> ch) & 1) {
          // 本身已经有重复字母
          mask = 0;
          break;
        }
        mask |= (1 << ch);
      }
    }
    dfs(arr, masks, 0, 0, "");
    return ans;
  }
  void dfs(const vector<string> &arr, const vector<uint32_t> &masks, int idx,
           uint32_t curr_mask, string tmp_ans) {
    if (n == idx) {
      ans = max(ans, (int)tmp_ans.size());
      return;
    }
    if (masks[idx] != 0 && (curr_mask & masks[idx]) == 0) {
      dfs(arr, masks, idx + 1, curr_mask | masks[idx], tmp_ans + arr[idx]);
    }
    dfs(arr, masks, idx + 1, curr_mask, tmp_ans);
  }
};
int main() {}