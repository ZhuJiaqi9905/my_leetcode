#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int MAX = 50000;
int parent[MAX + 10];
int relation[MAX + 10]; // relation[i] i和根节点的关系 0同类 1吃 2被吃
int N, K;
void Merge(int a, int b, int r);
int GetRoot(int a);
// int matrix[3][3][2] = {0,2,2, 1, 1, 0, 1, 0, 0, 2, 2, 1, 2, 1, 1, 0, 0, 2};
int main() {
  scanf("%d%d", &N, &K);
  int z, x, y;
  int total = 0;
  for (int i = 1; i <= N; ++i) {
    parent[i] = i;
    relation[i] = 0;
  }
  int l = 0;
  while (K--) {
    scanf("%d%d%d", &z, &x, &y);
    if ((x > N) || (y > N)) {
      ++total;
      continue;
    }
    if (z == 2 && x == y) {
      total++;
      continue;
    }
    int rx = GetRoot(x);
    int ry = GetRoot(y);
    if (rx != ry) {
      Merge(x, y, z - 1);
    } else if (rx == ry) {
      if ((relation[x] - relation[y] + 3) % 3 != (z - 1)) {
        total++;
      }
    }
  }
  printf("%d\n", total);
}
int GetRoot(int a) {
  if (a == parent[a])
    return a;
  int t = GetRoot(parent[a]);
  relation[a] = (relation[a] + relation[parent[a]]) % 3; // 更新关系
  parent[a] = t;
  return t;
}
void Merge(int a, int b, int r) {
  int pa = GetRoot(a);
  int pb = GetRoot(b);
  if (pa != pb) {
    parent[pb] = pa;
    if (r == 1)
      relation[pb] = (relation[a] - relation[b] + 2) % 3;
    else
      relation[pb] = (relation[a] - relation[b] + 3) % 3;
  }
  return;
}