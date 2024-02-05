#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int go[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  vector<bool> visit;
  int n;
  int findCircleNum(vector<vector<int>> &isConnected) {
    n = isConnected.size();
    visit = vector<bool>(n, false);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (!visit[i]) {
        for (int j = 0; j < n; ++j) {
          if (isConnected[i][j] == 1 && !visit[j]) {
            visit[i] = true;
            dfs(isConnected, j);
            ans++;
          }
        }
      }
    }
    return ans;
  }
  void dfs(vector<vector<int>> &isConnected, int x) {
    visit[x] = true;
    for (int i = 0; i < n; ++i) {
      if (isConnected[x][i] == 1 && !visit[i]) {
        dfs(isConnected, i);
      }
    }
  }
};