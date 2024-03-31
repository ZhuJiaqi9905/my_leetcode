#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
inline int Lowbit(int x) { return x & (-x); }
struct Node {
  int val;
  int pos; // pos[i]表示n[i]在a中的位置
};
const int MAX = 300000;
int N;            // 长度
int a[MAX + 10];  // 原数组
Node n[MAX + 10]; // 原数组从小到大排序得新数组
int C[MAX +
      10]; // C[i]表示a中终点位于a[i-Lowbit(i)+1]到a[i]之间（含两端）的LIS长度
void Update(int k, int val);
int Query(int k);
int MyCompare(const void *e1, const void *e2);
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &a[i]);
    n[i].val = a[i];
    n[i].pos = i;
  }
  qsort(n + 1, N, sizeof(Node), MyCompare);
  int LIS = 1;
  for (int i = 1; i <= N; ++i) {
    LIS = Query(n[i].pos) + 1; // 求a中以a[n[i].pos]为终点的LIS长度
    Update(n[i].pos, LIS);
  }
  int answer = 1;
  for (int i = 1; i <= N; ++i) {
    answer = max(answer, C[i]);
  }
  printf("%d\n", answer);

  return 0;
}
int MyCompare(const void *e1, const void *e2) {
  Node *p1 = (Node *)e1;
  Node *p2 = (Node *)e2;
  if (p1->val < p2->val) // 从小到大排序
    return -1;
  else if (p1->val == p2->val) { // 如果值相等，按pos从大到小排
    if (p1->pos > p2->pos)
      return -1;
    else
      return 1;
  } else
    return 1;
}
int Query(int k) // 求a[1]到a[k]的最长上升子序列长度(此时还不包括a[k])
{
  int ans = 0;
  while (k > 0) {
    ans = max(ans, C[k]);
    k -= Lowbit(k);
  }
  return ans;
}
void Update(int k, int val) {
  while (k <= N) {
    C[k] = max(C[k], val);
    k += Lowbit(k);
  }
}