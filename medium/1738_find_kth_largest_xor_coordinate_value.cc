#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int kthLargestValue(vector<vector<int>> &matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> v(m, vector<int>(n, 0));
    v[0][0] = matrix[0][0];
    vector<int> res(m * n, 0);
    res[0] = v[0][0];
    for (int i = 1; i < n; ++i) {
      v[0][i] = v[0][i - 1] ^ matrix[0][i];
      res[i] = v[0][i];
    }
    for (int i = 1; i < m; ++i) {
      v[i][0] = v[i - 1][0] ^ matrix[i][0];
      res[i * n] = v[i][0];
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        v[i][j] = v[i - 1][j - 1] ^ v[i][j - 1] ^ v[i - 1][j] ^ matrix[i][j];
        res[i * n + j] = v[i][j];
      }
    }
    // sort(res.begin(), res.end(), greater<int>());
    nth_element(res.begin(), res.begin() + k - 1, res.end(), greater<int>());
    return res[k - 1];
  }
};