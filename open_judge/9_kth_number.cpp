#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
struct Node {
  int L, R;
  vector<int> v;
} tree[400010];
const int INF = 1000000000;
int a[100010];
int sort_a[100010];
int ans = 0; // 记录答案
int n;
int m;
void buildTree(int root, int l, int r); // 根节点从1开始
int binSearch(int b, int e, int val);
int query(int b, int e, int val, int root);
int binAns(int root, int K);
int minn = INF;
int maxx = -INF;
int main() {

  scanf("%d%d", &n, &m); // n个数，m次查询

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sort_a[i] = a[i];
    maxx = max(maxx, a[i]);
    minn = min(minn, a[i]);
  }
  sort(sort_a + 1, sort_a + 1 + n);
  buildTree(1, 1, n);
  int li, ri, k;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &li, &ri, &k);
    ans = binSearch(li, ri, k);
    printf("%d\n", ans);
  }

  return 0;
}

void buildTree(int root, int l, int r) // 根节点从1开始
{
  tree[root].L = l;
  tree[root].R = r;
  if (r == l) {
    tree[root].v.push_back(a[l]);
    return;
  }
  int mid = (l + r) / 2;
  int lc = root << 1;
  int rc = (root << 1) + 1;
  buildTree(lc, l, mid);
  buildTree(rc, mid + 1, r);
  int i, j;
  i = j = 0;
  while (i < tree[lc].v.size() || j < tree[rc].v.size()) {
    if (i < tree[lc].v.size()) {
      if (j < tree[rc].v.size()) {
        if (tree[lc].v[i] < tree[rc].v[j]) {
          tree[root].v.push_back(tree[lc].v[i]);
          i++;
        } else {
          tree[root].v.push_back(tree[rc].v[j]);
          j++;
        }
      } else {
        tree[root].v.push_back(tree[lc].v[i]);
        i++;
      }
    } else {
      tree[root].v.push_back(tree[rc].v[j]);
      j++;
    }
  }

  return;
}
int binSearch(int b, int e, int val) {
  int tmp = 0;
  int l = 1;
  int r = n;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    int num = query(b, e, sort_a[mid], 1);

    if (val <= num) {
      tmp = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return sort_a[tmp];
}

int query(int b, int e, int val, int root) {
  if (e < tree[root].L || b > tree[root].R)
    return 0;
  else if (b <= tree[root].L && tree[root].R <= e) {
    int k = binAns(root, val);
    return k;
  } else {
    int lnum = query(b, e, val, root << 1);
    int rnum = query(b, e, val, (root << 1) + 1);
    return lnum + rnum;
  }
}
int binAns(int root, int K) {
  int temp = -1; // 这里要注意，因为如果K最小要输出0，所以从-1开始
  int l = 0;
  int r = tree[root].v.size() - 1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (tree[root].v[mid] <= K) {
      temp = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  temp += 1;
  return temp;
}