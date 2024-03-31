#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct RLine { // 存纵边
  int x, y1, y2;
  bool bLeft; // 是否是左边
} rline[10010];
struct CLine { // 橫边
  int x1, x2, y;
  bool bDown;
} cline[10010];

struct Node {
  int L, R;
  Node *pLeft, *pRight;
  int len;
  int covers; // 区间被覆盖次数
} tree[40010];
int nc = 0; // 线段树结点的个数
void buildTree(Node *pRoot, int l, int r);
int myCompareR(const void *e1, const void *e2);
int myCompareC(const void *e1, const void *e2);
void Insert(Node *tree, int l, int r,
            int k); // k==0是从左往右扫，k==1是从下往上扫
void Delete(Node *tree, int l, int r);
int Y[20010]; // 存橫边用于离散化
int X[20010]; // 存纵边用于离散化
int yc = 0;   // 记录橫边离散化后的区间数目
int xc = 0;   // 记录纵边离散化后的区间数目
template <class F, class T> F bin_search(F s, F e, T val) {
  F L = s;
  F R = e - 1;
  while (L <= R) {
    F mid = L + (R - L) / 2;
    if (!(*mid < val || val < *mid))
      return mid;
    else if (val < *mid)
      R = mid - 1;
    else
      L = mid + 1;
  }
  return e;
}
int main() {
  int n; // n个矩形
  int x1, x2, y1, y2;
  int rlc = 0; // 纵边的个数
  int clc = 0; // 橫边的个数
  int ans = 0;
  scanf("%d", &n);
  for (int j = 0; j <= 20000; ++j) {
    Y[j] = j;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    Y[yc++] = y1;
    Y[yc++] = y2;
    X[xc++] = x1;
    X[xc++] = x2;
    rline[rlc].x = x1;
    rline[rlc].y1 = y1;
    rline[rlc].y2 = y2;
    rline[rlc].bLeft = 1;
    rlc++;
    rline[rlc].x = x2;
    rline[rlc].y1 = y1;
    rline[rlc].y2 = y2;
    rline[rlc].bLeft = 0;
    rlc++;
    cline[clc].x1 = x1;
    cline[clc].x2 = x2;
    cline[clc].y = y1;
    cline[clc].bDown = 1;
    clc++;
    cline[clc].x1 = x1;
    cline[clc].x2 = x2;
    cline[clc].y = y2;
    cline[clc].bDown = 0;
    clc++;
  }
  sort(Y, Y + yc);
  sort(X, X + xc);
  yc = unique(Y, Y + yc) - Y;
  xc = unique(X, X + xc) - X;
  --yc;
  --xc; // 之前是yc个橫边，因此区间数要减一
  buildTree(tree, 0, yc - 1);
  qsort(rline, rlc, sizeof(RLine), myCompareR);
  int last = 0; // 记录上一次的结果
  // 从左往右扫一遍
  for (int i = 0; i < rlc; ++i) {
    int L = bin_search(Y, Y + yc, rline[i].y1) - Y;
    int R = bin_search(Y, Y + yc, rline[i].y2) - Y;
    if (rline[i].bLeft)
      Insert(tree, L, R - 1, 0);
    // 这里线段树是离散的，但是你要处理的是连续的区间，相当于你给区间标了号，
    //  你用线段树造的是标号的区间
    else
      Delete(tree, L, R - 1);
    ans += abs(tree->len - last);
    last = tree->len;
  }
  // 重新建树
  nc = 0;
  buildTree(tree, 0, xc - 1);
  qsort(cline, clc, sizeof(CLine), myCompareC);
  last = 0;
  for (int i = 0; i < clc; ++i) {
    int L = bin_search(X, X + xc, cline[i].x1) - X;
    int R = bin_search(X, X + xc, cline[i].x2) - X;
    if (cline[i].bDown)
      Insert(tree, L, R - 1, 1);
    else
      Delete(tree, L, R - 1);
    ans += abs(tree->len - last);
    last = tree->len;
  }
  printf("%d\n", ans);
}
void buildTree(Node *pRoot, int l, int r) {
  pRoot->L = l;
  pRoot->R = r;
  pRoot->covers = 0;
  pRoot->len = 0;
  if (l == r)
    return;
  nc++;
  pRoot->pLeft = tree + nc;
  nc++;
  pRoot->pRight = tree + nc;
  int mid = (l + r) >> 1;
  buildTree(pRoot->pLeft, l, mid);
  buildTree(pRoot->pRight, mid + 1, r);
}
int myCompareR(const void *e1, const void *e2) {
  RLine *p1 = (RLine *)e1;
  RLine *p2 = (RLine *)e2;
  if (p1->x < p2->x) {
    return -1;
  } else if (p1->x == p2->x) {
    if (p1->bLeft && !p2->bLeft) {
      return -1;
    } else if (!p1->bLeft && p2->bLeft) {
      return 1;
    } else
      return 0;
  } else
    return 1;
}
int myCompareC(const void *e1, const void *e2) {
  CLine *p1 = (CLine *)e1;
  CLine *p2 = (CLine *)e2;
  if (p1->y < p2->y) {
    return -1;
  } else if (p1->y == p2->y) {
    if (p1->bDown && !p2->bDown) {
      return -1;
    } else if (!p1->bDown && p2->bDown) {
      return 1;
    } else
      return 0;
  } else
    return 1;
}
void Insert(Node *pRoot, int l, int r, int k) {
  if (l == pRoot->L && r == pRoot->R) {
    if (k == 0)
      pRoot->len = Y[r + 1] - Y[l]; // 注意这里的+1
    else
      pRoot->len = X[r + 1] - X[l];
    pRoot->covers++;
    return;
  }
  int mid = (pRoot->L + pRoot->R) / 2;
  if (r <= mid) {
    Insert(pRoot->pLeft, l, r, k);
  } else if (l > mid) {
    Insert(pRoot->pRight, l, r, k);
  } else {
    Insert(pRoot->pLeft, l, mid, k);
    Insert(pRoot->pRight, mid + 1, r, k);
  }
  if (pRoot->covers == 0) {
    pRoot->len = pRoot->pLeft->len + pRoot->pRight->len;
  }
}
void Delete(Node *pRoot, int l, int r) {
  if (pRoot->L == l && pRoot->R == r) {
    pRoot->covers--;
    if (pRoot->covers == 0) {
      if (pRoot->L == pRoot->R) {
        pRoot->len = 0;
      } else
        pRoot->len = pRoot->pLeft->len + pRoot->pRight->len;
    }
    return;
  }
  int mid = (pRoot->L + pRoot->R) / 2;
  if (r <= mid)
    Delete(pRoot->pLeft, l, r);
  else if (mid < l)
    Delete(pRoot->pRight, l, r);
  else {
    Delete(pRoot->pLeft, l, mid);
    Delete(pRoot->pRight, mid + 1, r);
  }
  if (pRoot->covers == 0)
    pRoot->len = pRoot->pLeft->len + pRoot->pRight->len;
}