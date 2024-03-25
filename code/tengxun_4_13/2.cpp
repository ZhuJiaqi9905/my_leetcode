#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 2 * 1e5 + 10;
struct Node {
  int cnt2;
  int cnt5;
  bool null;
  Node() : cnt2(0), cnt5(0), null(true) {}
};

Node nodes[MAX_NODES];
int n; // nodes

int getCnt(int val, int m) {
  if (val % m != 0) {
    return 0;
  }
  int cnt = 0;
  while (true) {
    if (val % m != 0) {
      break;
    }
    val /= m;
    cnt++;
  }
  return cnt;
}
void dfs(int id) {
  int l = (id << 1) + 1;
  int r = l + 1;
  if (nodes[l].null && nodes[r].null) { // node[id] is leaf
    return;
  }
  if (!nodes[l].null) {
    dfs(l);
  }
  if (!nodes[r].null) {
    dfs(r);
  }
  nodes[id].cnt2 += nodes[l].cnt2 + nodes[r].cnt2;
  nodes[id].cnt5 += nodes[l].cnt5 + nodes[r].cnt5;
}
// 7
// 2 5 10 -1 -1 4 5

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    if (val < 0) {
      continue;
    }
    nodes[i].cnt2 = getCnt(val, 2);
    nodes[i].cnt5 = getCnt(val, 5);
    nodes[i].null = false;
  }
  dfs(0);

  for (int i = 0; i < n; ++i) {
    if (nodes[i].null) {
      cout << -1 << " ";
      continue;
    }
    cout << min(nodes[i].cnt2, nodes[i].cnt5) << " ";
  }
  cout << endl;
}