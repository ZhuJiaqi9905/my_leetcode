// 社会集群
#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 1e3 + 10;

int p[MAXN];
int cnt[MAXN];
void init() {
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
    cnt[i] = 1;
  }
}

vector<int> h[MAXN]; // h[i]表示喜欢爱好i的人们。相当于邻接表

int getRoot(int x) {
  if (x == p[x]) {
    return x;
  }
  p[x] = getRoot(p[x]);
  return p[x];
}

void merge(int x, int y) {
  int rx = getRoot(x);
  int ry = getRoot(y);
  if (rx == ry) {
    return;
  }
  p[ry] = rx;
  cnt[rx] += cnt[ry];
}

int main() {
  cin >> n;
  init();
  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int x;
      cin >> x;
      h[x].push_back(i);
    }
  }
  for (int i = 1; i <= 1000; ++i) {
    if (h[i].size() > 0) {
      cout << "h[" << i << "]"
           << ": ";
      for (int x : h[i]) {
        cout << x << " ";
      }
      cout << endl;
    }
  }

  for (int i = 1; i <= 1000; ++i) { // 对于每个爱好
    if (h[i].size() <= 1) {
      continue;
    }
    int s = h[i].size();
    for (int j = 1; j < s; ++j) {
      merge(h[i][0], h[i][j]);
    }
  }
  vector<int> res;
  for (int i = 1; i <= n; ++i) {
    if (i == getRoot(i)) {
      res.push_back(cnt[i]);
    }
  }
  sort(res.begin(), res.end(), greater<int>());
  // 注意输出格式
  cout << res.size() << endl;
  for (auto x : res) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}