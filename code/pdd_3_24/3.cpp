#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, m;
int d_in[N];
int d_out[N];
int cnt[N];
vector<int> nxt[N], res;
queue<int> que;

void solve() {

  // 用一个点作为所有出度为0的点的终点
  for (int i = 1; i <= n; ++i) {
    if (d_out[i] == 0) {
      nxt[i].push_back(n + 1);
      d_in[n + 1]++;
      d_out[i]++;
    }
  }
  n++;
  // 用另一个点作为所有入度为0的点的起始点
  for (int i = 1; i <= n; ++i) {
    if (d_in[i] == 0) {
      nxt[0].push_back(i);
      d_in[i]++;
      d_out[0]++;
    }
    cnt[i] = d_in[i];
  }
  que.push(0);
  int sum = 0;
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    sum -= d_in[x];
    if (sum == 0 && x != 0) {
      res.push_back(x);
    }
    sum += d_out[x];
    for (auto i : nxt[x]) {
      if (!--cnt[i]) {
        que.push(i);
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    nxt[a].push_back(b);
    d_out[a]++;
    d_in[b]++;
  }
  solve();
  cout << res.size() - 1 << endl;
}

/*

7 7
1 2
2 3
3 4
4 7
2 5
5 4
6 4

*/