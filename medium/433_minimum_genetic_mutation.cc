#include <queue>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int minMutation(string startGene, string endGene, vector<string> &bank) {
    int n = bank.size();
    int m = startGene.size();
    vector<vector<int>> graph(n);
    int end_idx = -1;
    // 建图
    for (int i = 0; i < n; ++i) {
      if (bank[i] == endGene) {
        end_idx = i;
      }
      for (int j = i + 1; j < n; ++j) {
        int mutation = 0;
        for (int k = 0; k < m; ++k) {
          if (bank[i][k] != bank[j][k]) {
            mutation++;
            if (mutation > 1) {
              break;
            }
          }
        }
        if (mutation == 1) {
          graph[i].push_back(j);
          graph[j].push_back(i);
        }
      }
    }
    if (end_idx == -1) {
      return -1;
    }

    // 处理输入的可能情况
    deque<bool> visit(n, false);
    queue<int> que;
    int step = 1;
    for (int i = 0; i < n; ++i) {
      int mutation = 0;
      for (int k = 0; k < m; ++k) {
        if (startGene[k] != bank[i][k]) {
          mutation++;
          if (mutation > 1) {
            break;
          }
        }
      }
      if (mutation == 1) {
        visit[i] = true;
        que.push(i);
      }
    }

    // bfs
    while (!que.empty()) {
      int s = que.size();
      while (s--) {
        int u = que.front();
        que.pop();
        if (u == end_idx) {
          return step;
        }
        for (auto &v : graph[u]) {
          if (!visit[v]) {
            visit[v] = true;
            que.push(v);
          }
        }
      }
      step++;
    }
    return -1;
  }
};

int main() {}