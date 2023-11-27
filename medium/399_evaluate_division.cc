// 建图，用bfs
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

/// 每个变量是图的每个点，除法是一条边，边的权重是相除的值。要做双向的图，可以算出a/b和b/a。
/// 计算答案就是从起始点bfs到终止点。
/// 注意处理该点不存在等特殊情况。
class Solution {
private:
  vector<vector<pair<int, double>>> graph_;
  unordered_map<string, int>
      map_; // 一个翻译表，把每个变量映射到一个整数，便于表示图的节点
  int cnt_ = 0;

public:
  class Node {
  public:
    int s;
    double v; // val
  };
  double bfs(int begin, int end) {
    set<int> visit; // 去重
    queue<Node> que;
    Node nd;
    nd.s = begin;
    nd.v = 1;
    visit.insert(begin);
    que.push(nd);
    while (!que.empty()) {
      Node front = que.front();
      que.pop();
      if (front.s == end) {
        return front.v;
      }
      for (auto iter = graph_[front.s].begin(); iter != graph_[front.s].end();
           ++iter) {
        if (visit.find(iter->first) != visit.end()) {
          continue;
        }
        Node nnd;
        nnd.s = iter->first;
        nnd.v = front.v * iter->second;
        visit.insert(nnd.s);
        que.push(std::move(nnd));
      }
    }
    return -1;
  }
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    int n = equations.size();
    graph_ = vector<vector<pair<int, double>>>(30);
    for (auto &s : equations) {
      for (auto &ch : s) {
        if (!map_.count(ch))
          map_[ch] = cnt_++;
      }
    }

    for (int i = 0; i < n; ++i) {
      int u = map_[equations[i][0]];
      int v = map_[equations[i][1]];
      graph_[u].push_back(make_pair(v, values[i]));
      graph_[v].push_back(make_pair(u, 1 / values[i]));
    }

    vector<double> ans;
    for (auto &ele : queries) {
      if (map_.find(ele[0]) == map_.end() || map_.find(ele[1]) == map_.end()) {
        ans.push_back(-1);
        continue;
      }
      double tmp = bfs(map_[ele[0]], map_[ele[1]]);
      ans.push_back(tmp);
    }
    return ans;
  }
};
int main() {
  //   Solution s;
  //   vector<vector<string>> equations;
  //   equations.push_back(vector<string>{"a", "b"});
  //   equations.push_back(vector<string>{"b", "c"});
  //   vector<double> values{2.0, 3.0};
  //   vector<vector<string>> queries{
  //       vector<string>{"a", "c"}, vector<string>{"b", "a"},
  //       vector<string>{"a", "e"}, vector<string>{"a", "a"},
  //       vector<string>{"x", "x"}

  //   };
  //   vector<double> ans = s.calcEquation(equations, values, queries);
  //   for (auto a : ans) {
  //     cout << a << " ";
  //   }
  //   cout << endl;

  Solution s2;
  vector<vector<string>> e2{{"b", "a"}, {"c", "b"}, {"d", "c"}, {"e", "d"},
                            {"f", "e"}, {"g", "f"}, {"h", "g"}, {"i", "h"},
                            {"j", "i"}, {"k", "j"}, {"k", "l"}, {"l", "m"},
                            {"m", "n"}, {"n", "o"}, {"o", "p"}, {"p", "q"},
                            {"q", "r"}, {"r", "s"}, {"s", "t"}, {"t", "u"}};

  vector<double> v2{1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05,
                    1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05,
                    1e-05, 1e-05, 1e-05, 1e-05, 1e-05, 1e-05};
  vector<vector<string>> q2{"a", "u"};

  s2.calcEquation(e2, v2, q2);
}