#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> degree(numCourses, 0);
    for (auto &req : prerequisites) {
      auto u = req[0];
      auto v = req[1];
      graph[v].push_back(u);
      degree[u]++;
    }

    queue<int> que;
    for (int i = 0; i < numCourses; ++i) {
      if (0 == degree[i]) {
        que.push(i);
      }
    }
    vector<int> ans;
    while (!que.empty()) {
      auto u = que.front();
      que.pop();
      ans.push_back(u);
      for (auto &v : graph[u]) {
        degree[v]--;
        if (0 == degree[v]) {
          que.push(v);
        }
      }
    }
    if (ans.size() == numCourses) {
      return ans;
    } else {
      return vector<int>();
    }
  }
};
int main() {}