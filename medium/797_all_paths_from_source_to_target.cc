#include <gtest/gtest.h>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> paths;
  int n;
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<int> path;
    n = graph.size();
    path.push_back(0);
    dfs(0, graph, path);
    return paths;
  }
  void dfs(int u, const vector<vector<int>> &graph, vector<int> &path) {
    if (u == (n - 1)) {
      paths.push_back(path);
    }
    for (const auto &v : graph[u]) {
      path.push_back(v);
      dfs(v, graph, path);
      path.pop_back();
    }
  }
};

int main() {
  Solution s1;
  vector<vector<int>> g1 = {{1, 2}, {3}, {3}, {}};
  vector<vector<int>> a1 = {{0, 1, 3}, {0, 2, 3}};
  EXPECT_EQ(s1.allPathsSourceTarget(g1), a1);

  Solution s2;
  vector<vector<int>> g2 = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
  vector<vector<int>> a2 = {
      {0, 4}, {0, 3, 4}, {0, 1, 3, 4}, {0, 1, 2, 3, 4}, {0, 1, 4}};
  EXPECT_EQ(s2.allPathsSourceTarget(g2), a2);
}