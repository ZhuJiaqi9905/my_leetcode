#include <deque>
#include <gtest/gtest.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

/// 建图，对图进行bfs
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    int m = beginWord.size();
    int n = wordList.size();
    vector<vector<int>> graph(n);
    // 建图
    int end_idx = -1;
    for (int i = 0; i < n; ++i) {
      if (wordList[i] == endWord) {
        end_idx = i;
      }
      for (int j = i + 1; j < n; ++j) {
        int diff = 0;
        for (int k = 0; k < m; ++k) {
          if (wordList[i][k] != wordList[j][k]) {
            diff++;
            if (diff > 1) {
              break;
            }
          }
        }
        if (diff == 1) {
          graph[i].push_back(j);
          graph[j].push_back(i);
        }
      }
    }
    // 处理第一次的输入
    int step = 2;
    queue<int> que;
    deque<bool> visit(n);
    for (int i = 0; i < n; ++i) {
      int diff = 0;
      for (int k = 0; k < m; ++k) {
        if (beginWord[k] != wordList[i][k]) {
          diff++;
          if (diff > 1) {
            break;
          }
        }
      }
      if (diff == 1) {
        que.push(i);
        visit[i] = true;
      }
    }
    // bfs
    while (!que.empty()) {
      int s = que.size();
      while (s--) {
        int curr = que.front();
        que.pop();
        if (curr == end_idx) {
          return step;
        }
        for (auto &next : graph[curr]) {
          if (!visit[next]) {
            visit[next] = true;
            que.push(next);
          }
        }
      }
      step++;
    }
    return 0;
  }
};

int main() {
  Solution s;
  string b1 = "hit";
  string e1 = "cog";
  vector<string> w1{"hot", "dot", "dog", "lot", "log", "cog"};
  EXPECT_EQ(s.ladderLength(b1, e1, w1), 5);
}