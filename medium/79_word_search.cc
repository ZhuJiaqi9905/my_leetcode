#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int go_[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int m_;
  int n_;
  int w_;
  bool exist(vector<vector<char>> &board, string word) {
    m_ = board.size();
    n_ = board[0].size();
    w_ = word.size();
    for (int i = 0; i < m_; ++i) {
      for (int j = 0; j < n_; ++j) {
        if (board[i][j] == word[0]) {
          auto res = dfs(board, word, i, j, 0);
          if (res == true) {
            return true;
          }
        }
      }
    }
    return false;
  }
  bool dfs(vector<vector<char>> &board, const string &word, int x, int y,
           int idx) {
    if (idx == w_ - 1) {
      return true;
    }
    char c = board[x][y];
    board[x][y] = '@';
    for (int i = 0; i < 4; ++i) {
      int xx = x + go_[i][0];
      int yy = y + go_[i][1];
      if (xx >= 0 && xx < m_ && yy >= 0 && yy < n_ &&
          board[xx][yy] == word[idx + 1]) {
        auto res = dfs(board, word, xx, yy, idx + 1);
        if (res == true) {
          board[x][y] = c;
          return res;
        }
      }
    }
    board[x][y] = c;

    return false;
  }
};

int main() {}