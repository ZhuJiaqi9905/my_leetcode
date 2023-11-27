#include <deque>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  struct Point {
    int x;
    int y;
  };
  struct Element {
    int id;
    int val;
  };
  // 这个背下来
  Point getPos(int id) {
    int x = (id - 1) / n_;
    int y = (id - 1) % n_;
    if (1 == x % 2) {
      y = n_ - 1 - y;
    }
    x = n_ - 1 - x;
    return Point{x, y};
  }

  int n_;

  int snakesAndLadders(vector<vector<int>> &board) {
    n_ = board.size();
    deque<bool> visited(n_ * n_ + 1, false);
    queue<Element> que;
    que.push(Element{1, 0});
    visited[1] = true;
    while (!que.empty()) {
      Element ele = que.front();
      que.pop();
      if (ele.id == n_ * n_) {
        return ele.val;
      }
      for (int i = 1; i <= 6; ++i) {
        int next = ele.id + i;
        if (next > n_ * n_) {
          break;
        }
        Point p = getPos(next);
        /// 注意审题。这里如果能传送就直接传送走了
        if (board[p.x][p.y] != -1) {
          int new_id = board[p.x][p.y];
          if (!visited[new_id]) {
            visited[new_id] = true;
            que.push(Element{new_id, ele.val + 1});
          }
        } else {
          if (!visited[next]) {
            visited[next] = true;
            que.push(Element{next, ele.val + 1});
          }
        }
      }
    }
    return -1;
  }
};

int main() {}