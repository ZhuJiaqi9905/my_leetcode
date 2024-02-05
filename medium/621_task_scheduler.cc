#include <bits/stdc++.h>
using namespace std;
/// 贪心，思路就是尽量均匀的排任务，把空给尽量占满
class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    int len = tasks.size();
    vector<int> vec(26);
    for (char c : tasks) {
      ++vec[c - 'A'];
    }
    /// 从大到小排序
    sort(vec.begin(), vec.end(),
         [](const int &x, const int &y) { return x > y; });
    int cnt = 1;
    while (cnt < vec.size() && vec[cnt] == vec[0]) {
      cnt++;
    }
    return max(len, cnt + (n + 1) * (vec[0] - 1));
  }
};
int main() {}