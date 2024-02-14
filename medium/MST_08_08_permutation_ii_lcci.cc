#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<string> ans;
  vector<int> visit;
  int n;
  vector<string> permutation(string S) {
    n = S.size();
    sort(S.begin(), S.end());
    visit = vector<int>(n, 0);
    string tmp_ans;
    dfs(S, tmp_ans, 0);
    return ans;
  }

  void dfs(const string &S, string &tmp_ans, int k) {
    cout << k << " " << tmp_ans << endl;
    if (k == n) {
      ans.emplace_back(tmp_ans);
      return;
    }
    for (int i = 0; i < n; ++i) {

      if (visit[i] || (i > 0 && S[i - 1] == S[i] && !visit[i - 1])) {
        continue;
      }

      visit[i] = 1;
      tmp_ans += S[i];
      dfs(S, tmp_ans, k + 1);
      tmp_ans.pop_back();
      visit[i] = 0;
    }
  }
};
int main() {}