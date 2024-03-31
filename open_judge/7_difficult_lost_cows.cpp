#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int MAX = 100000;
int N;
int indexx[MAX + 10];
int ans[MAX + 10];
struct Node {
  int L;
  int R;
  int num; //[L,R]区间中还剩多少牛没有判断过
};
Node tree[4 * MAX + 10];
void BuildTree(int root, int l, int r) {
  tree[root].L = l;
  tree[root].R = r;
  if (l == r) {
    tree[root].num = 1;
    return;
  }
  int mid = (l + r) / 2;
  int lc = 2 * root;
  int rc = 2 * root + 1;
  tree[root].num = r - l + 1;
  BuildTree(lc, l, mid);
  BuildTree(rc, mid + 1, r);
}
void Query(int root, int ind, int v) {
  if (tree[root].L == tree[root].R) {
    ans[v] = tree[root].L;
    tree[root].num = 0;
    return;
  }
  int lc = 2 * root;
  int rc = 2 * root + 1;
  tree[root].num -= 1;
  if (ind <= tree[lc].num) {
    Query(lc, ind, v);
  } else {
    Query(rc, ind - tree[lc].num, v);
  }
}
int main() {
  scanf("%d", &N);
  indexx[1] = 1;
  for (int i = 2; i <= N; ++i) {
    scanf("%d", &indexx[i]);
    indexx[i]++;
  }
  BuildTree(1, 1, N);
  for (int i = N; i >= 1; --i) {
    Query(1, indexx[i], i);
  }
  for (int i = 1; i <= N; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}