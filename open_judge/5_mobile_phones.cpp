#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
inline int Lowbit(int x) { return x & (-x); }
int S;
const int MAX = 1024;
int a[MAX + 10][MAX + 10];
int C[MAX + 10][MAX + 10];
void Update(int x, int y, int val);
int GetSum(int i, int j);
int main() {
  int op;
  int X, Y, A;
  int L, B, R, T;
  while (scanf("%d", &op) != EOF) {
    if (op == 0) {
      scanf("%d", &S);
    } else if (op == 1) {
      scanf("%d%d%d", &X, &Y, &A);
      a[X + 1][Y + 1] += A;
      Update(X + 1, Y + 1, A);
    } else if (op == 2) {
      scanf("%d%d%d%d", &L, &B, &R, &T);
      printf("%d\n", GetSum(R + 1, T + 1) - GetSum(L, T + 1) -
                         GetSum(R + 1, B) + GetSum(L, B));
    } else
      break;
  }

  return 0;
}
void Update(int x, int y, int val) {
  for (int i = x; i <= S; i += Lowbit(i)) {
    for (int j = y; j <= S; j += Lowbit(j)) {
      C[i][j] += val;
    }
  }
  return;
}
int GetSum(int x, int y) {
  int total = 0;
  for (int i = x; i > 0; i -= Lowbit(i)) {
    for (int j = y; j > 0; j -= Lowbit(j)) {
      total += C[i][j];
    }
  }
  return total;
}