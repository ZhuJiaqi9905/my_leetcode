#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> degree(numCourses, 0);
    for (auto &prerequisy : prerequisites) {
      auto u = prerequisy[0];
      auto v = prerequisy[1];
      graph[u].push_back(v);
      degree[v] += 1;
    }
    queue<int> que;
    int cnt = 0;
    for (int i = 0; i < numCourses; ++i) {
      if (degree[i] == 0) {
        que.push(i);
        cnt++;
      }
    }
    while (!que.empty()) {
      auto u = que.front();
      que.pop();
      for (auto &v : graph[u]) {
        degree[v]--;
        if (degree[v] == 0) {
          que.push(v);
          cnt++;
        }
      }
    }
    return cnt == numCourses;
  }
};

int main() {}