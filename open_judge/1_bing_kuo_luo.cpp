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
void Merge(int a, int b);
int GetRoot(int a);
bool Query(int a, int b);
int main() {
  int m, n; // n个可乐，m次操作
  while (scanf("%d%d", &n, &m) != EOF) {
    int x, y;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &x, &y);
      if (Query(x, y)) {
        printf("Yes\n");
      } else {
        Merge(x, y);
        printf("No\n");
        ++sum;
      }
    }
    printf("%d\n", n - sum);
    for (int i = 1; i <= n; ++i) {
      if (i == GetRoot(i))
        printf("%d ", i);
    }
    printf("\n");
  }
}
int GetRoot(int a) {
  if (parent[a] != a)
    parent[a] = GetRoot(parent[a]);
  return parent[a];
}
void Merge(int a, int b) {
  parent[GetRoot(b)] = GetRoot(a);
  return;
}
bool Query(int a, int b) { return GetRoot(a) == GetRoot(b); }