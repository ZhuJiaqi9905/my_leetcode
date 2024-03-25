#include <bits/stdc++.h>
using namespace std;
struct Node {
  int x;
  int y;
  int val;
};

bool operator<(const Node &n1, const Node &n2) { return n1.val < n2.val; }
// 排序 + dp
class Solution {
public:
  int go[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<Node> nds;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        nds.emplace_back(Node{i, j, matrix[i][j]});
      }
    }
    sort(nds.begin(), nds.end());
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int ans = 1;
    for (auto &nd : nds) {
      dp[nd.x][nd.y] = 1;
      for (int i = 0; i < 4; ++i) {
        int x = nd.x + go[i][0];
        int y = nd.y + go[i][1];
        if (x < 0 || x >= m || y < 0 || y >= n) {
          continue;
        }
        if (matrix[x][y] >= matrix[nd.x][nd.y]) {
          continue;
        }
        dp[nd.x][nd.y] = max(dp[nd.x][nd.y], dp[x][y] + 1);
        ans = max(ans, dp[nd.x][nd.y]);
      }
    }
    return ans;
  }
};