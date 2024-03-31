#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int MAX = 20000;
int parent[MAX + 10];
int oppsex[MAX + 10]; // 记录和i反性别的虫子
int rankk[MAX + 10];
int GetRoot(int a);
bool Query(int a, int b);
void Merge(int a, int b);
int main() {
  int kase;
  scanf("%d", &kase);
  int k = 0;
  int n, m; // n个虫子，m个操作
  int x, y;
  while (kase--) {
    bool flag = 0; // 没找到
    ++k;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
      oppsex[i] = 0;
      rankk[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &x, &y);
      if (flag)
        continue;
      if (Query(x, y)) {
        flag = 1;
        continue;
      }
      if (oppsex[x] != 0) {
        Merge(oppsex[x], y);
      } else
        oppsex[x] = y;
      if (oppsex[y] != 0) {
        Merge(oppsex[y], x);
      } else
        oppsex[y] = x;
    }
    printf("Scenario #%d:\n", k);
    if (flag)
      printf("Suspicious bugs found!\n");
    else
      printf("No suspicious bugs found!\n");
    printf("\n");
  }
}
int GetRoot(int a) {

  if (a != parent[a]) {
    parent[a] = GetRoot(parent[a]);
  }
  return parent[a];
}
bool Query(int a, int b) { return GetRoot(a) == GetRoot(b); }
void Merge(int a, int b) {
  int pa = GetRoot(a);
  int pb = GetRoot(b);
  if (rankk[pa] < rankk[pb]) {
    parent[pa] = pb;
    rankk[pb] = max(rankk[pb], rankk[pa] + 1);
  } else {
    parent[pb] = pa;
    rankk[pa] = max(rankk[pa], rankk[pb] + 1);
  }
  return;
}