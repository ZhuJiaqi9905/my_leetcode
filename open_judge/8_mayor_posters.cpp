#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int MAX = 10000;
int point[MAX * 2 + 10]; // 记录端点
int point_count = 0;     // 端点个数
int node_count = 0;      // 线段树结点个数
int ans = 0;             // 记录没被完全盖住的海报数
struct Line {
  int b, e;
};
Line poster[MAX + 10];
Line discrete[MAX * 4 + 10]; // 记录离散区间
int dis_count = 0;           // 记录离散区间的个数
struct Node {                // 线段树的结点
  int L, R;
  bool cover;
  Node *pLeft, *pRight;
} tree[MAX * 8 + 10];
void buildDiscrete(); // 离散化
void buildTree(Node *pRoot, int l, int r);
int binSearch(int s, int e, int val); // 二分查找[s,e)中，val对应的离散化的序号
bool getCover(Node *pRoot, int l, int r); // 判断该区间是否被完全盖住
int main() {
  int c;
  int n; // n个海报
  int kase = 0;
  scanf("%d", &c);
  while (kase < c) {
    ++kase;
    point_count = 0;
    node_count = 0;
    dis_count = 0;
    ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &poster[i].b, &poster[i].e);
      point[point_count] = poster[i].b;
      ++point_count;
      point[point_count] = poster[i].e;
      ++point_count;
    }
    sort(point, point + point_count);
    point_count = unique(point, point + point_count) - point;
    buildDiscrete(); // 离散化
    buildTree(tree, 0, dis_count - 1);
    for (int i = n - 1; i >= 0; --i) {
      int ll = binSearch(0, dis_count, poster[i].b);
      int rr = binSearch(0, dis_count, poster[i].e);
      if (!getCover(tree, ll, rr)) {
        ans++;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
void buildDiscrete() // 离散化
{
  for (int i = 0; i < (point_count - 1); ++i) {
    discrete[dis_count].e = discrete[dis_count].b = point[i];
    ++dis_count;
    if (point[i] + 1 < point[i + 1]) {
      discrete[dis_count].b = point[i] + 1;
      discrete[dis_count].e = point[i + 1] - 1;
      ++dis_count;
    }
  }
  discrete[dis_count].e = discrete[dis_count].b = point[point_count - 1];
  ++dis_count;
  return;
}
void buildTree(Node *pRoot, int l, int r) {
  pRoot->L = l;
  pRoot->R = r;
  pRoot->cover = 0;
  if (l == r)
    return;
  int mid = (l + r) / 2;
  node_count++;
  pRoot->pLeft = tree + node_count;
  ++node_count;
  pRoot->pRight = tree + node_count;
  buildTree(pRoot->pLeft, l, mid);
  buildTree(pRoot->pRight, mid + 1, r);
  return;
}
int binSearch(int s, int e, int val) // 二分查找[s,e)中，val对应的离散化的序号
{
  int l = s;
  int r = e - 1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if ((val >= discrete[mid].b) && (val <= discrete[mid].e))
      return mid;
    else if (val < discrete[mid].b) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return e;
}
bool getCover(Node *pRoot, int l, int r) // 判断该区间是否被完全盖住
{
  bool flag = 0;
  if (pRoot->L == l && pRoot->R == r) {
    flag = pRoot->cover;
    pRoot->cover = 1;
    return flag;
  }
  if (pRoot->L <= l && pRoot->R >= r && pRoot->cover) {
    return 1;
  }
  int mid = (pRoot->L + pRoot->R) / 2;
  if (r <= mid) {
    flag = getCover(pRoot->pLeft, l, r);
    pRoot->cover = pRoot->pLeft->cover & pRoot->pRight->cover;
    return flag;
  } else if (l > mid) {
    flag = getCover(pRoot->pRight, l, r);
    pRoot->cover = pRoot->pLeft->cover & pRoot->pRight->cover;
    return flag;
  } else {
    flag = getCover(pRoot->pLeft, l, mid) & getCover(pRoot->pRight, mid + 1, r);
    pRoot->cover = pRoot->pLeft->cover & pRoot->pRight->cover;
    return flag;
  }
}