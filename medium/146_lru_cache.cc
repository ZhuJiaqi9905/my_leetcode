#include <unordered_map>
using namespace std;

/// 双向链表 + 哈希表
/// 链表有伪头部节点，用tail_存尾指针的值。（也可以伪头部节点+伪尾部节点）
class LRUCache {
private:
  struct Node {
    int key{0};
    int value{0};
    Node *prev{nullptr};
    Node *next{nullptr};
    Node(int key, int value) : key(key), value(value) {}
    Node() {}
  };

  int cap_;
  int size_{0};
  unordered_map<int, Node *> mp_;
  Node dummy_head_;
  Node *tail_;

public:
  LRUCache(int capacity) : cap_(capacity) { tail_ = &dummy_head_; }

  void insertNode(Node *prev, Node *node) {
    node->next = prev->next;
    node->prev = prev;
    if (prev->next != nullptr) {
      prev->next->prev = node;
    }
    prev->next = node;
    if (prev == tail_) {
      tail_ = node;
    }
  }
  void removeNode(Node *node) {
    if (tail_ == node) {
      tail_ = node->prev;
    }
    node->prev->next = node->next;
    if (node->next != nullptr) {
      node->next->prev = node->prev;
    }
    node->prev = nullptr;
    node->next = nullptr;
  }

  int get(int key) {
    auto iter = mp_.find(key);
    if (iter == mp_.end()) {
      return -1;
    } else {
      auto node = iter->second;
      removeNode(node);
      insertNode(&dummy_head_, node);
      return node->value;
    }
  }

  void put(int key, int value) {
    auto iter = mp_.find(key);
    if (iter == mp_.end()) {

      if (size_ == cap_) {
        Node *node = tail_;
        removeNode(node);
        mp_.erase(node->key);
        node->key = key;
        node->value = value;
        insertNode(&dummy_head_, node);
        mp_.emplace(key, node);
      } else {
        Node *node = new Node(key, value);
        size_++;
        insertNode(&dummy_head_, node);
        mp_.emplace(key, node);
      }

    } else {
      auto node = iter->second;
      removeNode(node);
      insertNode(&dummy_head_, node);
      node->value = value;
    }
  }
};
int main() {}