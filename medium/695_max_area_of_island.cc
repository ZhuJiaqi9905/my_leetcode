#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int max_size{0};
  int m;
  int n;
  int go[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    m = grid.size();
    n = grid[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          int size = 0;
          grid[i][j] = 2;
          dfs(grid, i, j, size);

          max_size = max(max_size, size);
        }
      }
    }
    return max_size;
  }
  void dfs(vector<vector<int>> &grid, int x, int y, int &tmp_size) {
    tmp_size++;
    for (int i = 0; i < 4; ++i) {
      int xx = x + go[i][0];
      int yy = y + go[i][1];
      if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == 1) {
        grid[xx][yy] = 2;
        dfs(grid, xx, yy, tmp_size);
      }
    }
  }
};
int main() {}