#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool row[9][9];
  bool col[9][9];
  bool block[3][3][9];
  bool valid{false};             // 成功填好
  vector<pair<int, int>> spaces; // 记录哪里可以填
  void solveSudoku(vector<vector<char>> &board) {
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(block, 0, sizeof(block));

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') {
          spaces.emplace_back(i, j);
        } else {
          int num = board[i][j] - '0' - 1;
          row[i][num] = true;
          col[j][num] = true;
          block[i / 3][j / 3][num] = true;
        }
      }
    }

    dfs(board, 0);
  }

  void dfs(vector<vector<char>> &board, int pos) {
    if (pos == spaces.size()) {
      valid = true;
      return;
    }
    auto [i, j] = spaces[pos];
    for (int num = 0; num < 9 && !valid; ++num) {
      if (!row[i][num] && !col[j][num] && !block[i / 3][j / 3][num]) {
        row[i][num] = col[j][num] = block[i / 3][j / 3][num] = true;
        board[i][j] = num + '0' + 1;
        dfs(board, pos + 1);
        row[i][num] = col[j][num] = block[i / 3][j / 3][num] = false;
      }
    }
  }
};