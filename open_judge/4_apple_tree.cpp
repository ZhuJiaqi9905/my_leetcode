#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
inline int lowbit(int b) { return b & (-b); }
const int MAX = 100000;
int a[2 * MAX + 10];
int C[2 * MAX + 10];
int sum[2 * MAX + 10];
vector<vector<int>> branch(MAX + 10); // 邻接表
int Start[MAX + 10];
int End[MAX + 10];
void BuildArray(int begin, int end);
void Update(int k, int end);
void dfs(int m);
int GetSum(int k); // 求从a[i]到a[k]的和
int Time;
int main() {
  int N;
  int M;
  scanf("%d", &N);
  int u, v;
  int x;
  char c, d;
  Time = 0; // 初始化时间
  for (int i = 1; i < N; ++i) {
    scanf("%d%d", &u, &v);
    branch[u].push_back(v);
  }

  dfs(1);
  scanf("%d", &M);
  for (int i = 1; i <= N; ++i) {
    a[Start[i]] = 1;
    a[End[i]] = 1;
  }
  BuildArray(1, 2 * N); // 总共有2N个
  scanf("%c", &c);
  while (M--) {
    scanf("%c%d%c", &c, &x, &d);
    if (c == 'C') {
      //	a[Start[x]] = !a[Start[x]]; a[End[x]] = !a[End[x]];//单点更新
      Update(Start[x], 2 * N);
      Update(End[x], 2 * N); // 更新单点和区间
    } else {
      printf("%d\n", (GetSum(End[x]) - GetSum(Start[x] - 1)) / 2);
    }
  }

  return 0;
}
void dfs(int m) {
  ++Time;
  Start[m] = Time;
  for (int i = 0; i < branch[m].size(); ++i) {
    dfs(branch[m][i]);
  }
  ++Time;
  End[m] = Time;
  return;
}
void BuildArray(int begin, int end) {
  sum[0] = 0;
  for (int i = begin; i <= end; ++i) {
    sum[i] = sum[i - 1] + a[i];
    C[i] = sum[i] - sum[i - lowbit(i)];
  }
  return;
}
int GetSum(int k) {
  int tol = 0;
  while (k > 0) {
    tol += C[k];
    k = k - lowbit(k);
  }
  return tol;
}
void Update(int k, int end) {
  int tep = !a[k] - a[k];
  a[k] = !a[k];
  while (k <= end) {
    C[k] = C[k] + tep;
    k = k + lowbit(k);
  }
}
