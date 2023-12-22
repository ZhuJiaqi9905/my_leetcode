#include <bits/stdc++.h>
using namespace std;
// Definition for a QuadTree node.
class Node {
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
       Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
public:
  Node *construct(vector<vector<int>> &grid) {
    int val;
    Node *nd = dfsConstruct(grid, 0, 0, grid.size(), val);
    if (nd == nullptr) {
      nd = new Node(val, true);
    }
    return nd;
  }

  Node *dfsConstruct(vector<vector<int>> &grid, int x, int y, int n, int &val) {
    if (n == 1) {
      val = grid[x][y];
      return nullptr;
    }
    n = n / 2;
    int val_a;
    int val_b;
    int val_c;
    int val_d;
    auto a = dfsConstruct(grid, x, y, n, val_a);
    auto b = dfsConstruct(grid, x, y + n, n, val_b);
    auto c = dfsConstruct(grid, x + n, y, n, val_c);
    auto d = dfsConstruct(grid, x + n, y + n, n, val_d);
    if (a == nullptr && b == nullptr && c == nullptr && d == nullptr) {
      if (val_a == val_b && val_b == val_c && val_c == val_d) {
        val = val_a;
        return nullptr;
      }
    }
    val = 0;
    if (a == nullptr) {
      a = new Node(val_a, true);
    }
    if (b == nullptr) {
      b = new Node(val_b, true);
    }
    if (c == nullptr) {
      c = new Node(val_c, true);
    }
    if (d == nullptr) {
      d = new Node(val_d, true);
    }
    Node *nd = new Node(val, false, a, b, c, d);
    return nd;
  }
};

int main() {
  Solution s;
  vector<vector<int>> g{{1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}};
  s.construct(g);
}