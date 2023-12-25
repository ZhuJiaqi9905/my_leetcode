#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int rows[9][9];
    int cols[9][9];
    int subboxes[3][3][9];

    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));
    memset(subboxes, 0, sizeof(subboxes));
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') {
          continue;
        }
        int idx = board[i][j] - '0' - 1;
        rows[i][idx]++;
        cols[j][idx]++;
        subboxes[i / 3][j / 3][idx]++;
        if (rows[i][idx] > 1 || cols[j][idx] > 1 ||
            subboxes[i / 3][j / 3][idx] > 1) {
          return false;
        }
      }
    }
    return true;
  }
};
int main() {}