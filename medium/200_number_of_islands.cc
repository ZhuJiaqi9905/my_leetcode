#include <vector>
using namespace std;
class Solution {
public:
  int ans_ = 0;
  int m_;
  int n_;
  int numIslands(vector<vector<char>> &grid) {
    m_ = grid.size();
    n_ = grid[0].size();

    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          ans_++;
        }
      }
    }
    return ans_;
  }

  void dfs(vector<vector<char>> &grid, int x, int y) {
    grid[x][y] = '2';
    if (x > 0 && grid[x - 1][y] == '1') {
      dfs(grid, x - 1, y);
    }
    if (x < m_ - 1 && grid[x + 1][y] == '1') {
      dfs(grid, x + 1, y);
    }
    if (y > 0 && grid[x][y - 1] == '1') {
      dfs(grid, x, y - 1);
    }
    if (y < n_ - 1 && grid[x][y + 1] == '1') {
      dfs(grid, x, y + 1);
    }
  }
};

int main() {}