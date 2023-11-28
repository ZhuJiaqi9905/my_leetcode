#include <assert.h>
#include <iostream>
using namespace std;
class FrontMiddleBackQueue {
public:
  struct Node {
    Node *next{nullptr};
    Node *prev{nullptr};
    int val{0};
    Node() {}
    Node(int val) : val(val) {}
  };
  Node *head_;
  Node *tail_;
  Node *mid_;
  int size_;
  FrontMiddleBackQueue() {
    head_ = tail_ = mid_ = nullptr;
    size_ = 0;
  }

  void pushFront(int val) {
    Node *nd = new Node(val);
    if (size_ == 0) {
      head_ = tail_ = mid_ = nd;
    } else {
      nd->next = head_;
      head_->prev = nd;
      if (size_ % 2 == 1) { // 如果原来是奇数
        mid_ = mid_->prev;
      }
      head_ = nd;
    }
    size_++;
  }

  void pushMiddle(int val) {
    if (size_ == 0) {
      pushFront(val);
      return;
    }
    Node *nd = new Node(val);
    if (size_ % 2 == 0) {
      nd->next = mid_->next;
      nd->prev = mid_;
      mid_->next->prev = nd;
      mid_->next = nd;
      mid_ = mid_->next;
    } else {
      nd->next = mid_;
      nd->prev = mid_->prev;
      if (mid_->prev != nullptr) {
        mid_->prev->next = nd;
      }
      mid_->prev = nd;
      mid_ = mid_->prev;
      if (size_ == 1) {
        head_ = mid_;
      }
    }
    size_++;
  }

  void pushBack(int val) {
    if (size_ == 0) {
      pushFront(val);
      return;
    }
    Node *nd = new Node(val);
    nd->prev = tail_;
    tail_->next = nd;
    tail_ = nd;
    if (size_ % 2 == 0) {
      mid_ = mid_->next;
    }
    size_++;
  }

  int popFront() {
    if (size_ == 0) {
      return -1;
    }
    int val = head_->val;
    if (head_->next != nullptr) {
      head_->next->prev = nullptr;
      Node *nd = head_;
      head_ = head_->next;
      if (size_ % 2 == 0) {
        mid_ = mid_->next;
      }
      delete nd;
    } else {
      assert(size_ == 1);
      delete head_;
      head_ = tail_ = mid_ = nullptr;
    }
    size_--;
    return val;
  }

  int popMiddle() {
    if (size_ == 0) {
      return -1;
    }
    int val = mid_->val;
    if (mid_->prev != nullptr) {
      mid_->prev->next = mid_->next;
      mid_->next->prev = mid_->prev;
      Node *nd = mid_;
      if (size_ % 2 == 1) {
        mid_ = mid_->prev;
      } else {
        mid_ = mid_->next;
      }
      delete nd;
    } else {
      if (size_ == 1) {
        delete mid_;
        head_ = tail_ = mid_ = nullptr;
      } else {
        // size == 2
        mid_->next->prev = mid_->prev;
        Node *nd = mid_;
        mid_ = mid_->next;
        head_ = head_->next;
        delete nd;
      }
    }
    size_--;
    return val;
  }

  int popBack() {
    if (size_ == 0) {
      return -1;
    }
    int val = tail_->val;
    if (tail_->prev != nullptr) {
      tail_->prev->next = nullptr;
      Node *nd = tail_;
      tail_ = tail_->prev;
      if (size_ % 2 == 1) {
        mid_ = mid_->prev;
      }
      delete nd;
    } else {
      assert(size_ == 1);
      delete tail_;
      head_ = tail_ = mid_ = nullptr;
    }
    size_--;
    return val;
  }
  void printList() {
    Node *nd = head_;
    int s = 0;
    while (nd != nullptr) {
      cout << nd->val << " ";
      nd = nd->next;
      s++;
    }
    cout << "\n";
    assert(s == size_);
  }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

int main() {
  FrontMiddleBackQueue q;

  q.pushMiddle(493299);
  q.printList();
  q.popMiddle();
  q.printList();
  q.pushMiddle(75427);
  q.printList();
  q.popMiddle();
  q.printList();
  q.pushFront(753523);
  q.printList();
  q.pushMiddle(677444);
  q.printList();
  q.pushMiddle(431158);
  q.printList();
  q.popMiddle();
  q.printList();
  q.popMiddle();

  q.printList();
  q.pushBack(47949);
  q.printList();
  q.popMiddle();
  q.printList();
  //   q.pushFront(1); // [1]
  //   q.printList();
  //   q.pushBack(2); // [1, 2]
  //   q.printList();
  //   q.pushMiddle(3); // [1, 3, 2]
  //   q.printList();
  //   q.pushMiddle(4); // [1, 4, 3, 2]
  //   q.printList();
  //   q.popFront(); // 返回 1 -> [4, 3, 2]
  //   q.printList();
  //   q.popMiddle(); // 返回 3 -> [4, 2]
  //   q.printList();
  //   q.popMiddle(); // 返回 4 -> [2]
  //   q.printList();
  //   q.popBack(); // 返回 2 -> []
  //   q.printList();
  //   q.popFront(); // 返回 -1 -> [] （队列为空）
  //   q.printList();
}