#include <vector>
using namespace std;

class Solution {
public:
  int m_;
  int n_;
  vector<vector<int>> go_{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  void solve(vector<vector<char>> &board) {
    m_ = board.size();
    n_ = board[0].size();

    /// 从所有在边界上的O区域出发来标记
    for (int i = 0; i < m_; ++i) {
      dfs(board, i, 0);
      dfs(board, i, n_ - 1);
    }
    for (int i = 0; i < n_; ++i) {
      dfs(board, 0, i);
      dfs(board, m_ - 1, i);
    }

    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == 'K') {
          board[i][j] = 'O';
        }
      }
    }
  }

  void dfs(vector<vector<char>> &board, int x, int y) {
    if (x < 0 || x >= m_ || y < 0 || y >= n_ || board[x][y] != 'O') {
      return;
    }
    board[x][y] = 'K';
    for (int i = 0; i < 4; ++i) {
      int xx = go_[i][0] + x;
      int yy = go_[i][1] + y;
      dfs(board, xx, yy);
    }
  }
};