// 优秀题解
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int k;
int n;

struct Node {
  int a;
  int b;
};
Node nd[MAXN];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> nd[i].a;
  }
  for (int i = 0; i < n; ++i) {
    cin >> nd[i].b;
  }
  sort(nd, nd + n, [](const Node &x, const Node &y) { return x.b > y.b; });
  priority_queue<int, vector<int>, greater<int>> pq;
  int64_t sum = 0;
  int64_t res = 0;
  for (int i = 0; i < n; ++i) {
    int sz = pq.size();
    if (sz < k) {
      pq.push(nd[i].a);
      sum += nd[i].a;
    } else if (pq.top() < nd[i].a) {
      sum -= pq.top();
      pq.pop();
      pq.push(nd[i].a);
      sum += nd[i].a;
    }
    if (i >= k - 1) {
      res = max(res, sum * nd[i].b);
    }
  }
  cout << res << endl;
  return 0;
}