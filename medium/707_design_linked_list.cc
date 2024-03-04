class MyLinkedList {
public:
  struct Node {
    int val;
    Node *next;
    Node *prev;
  };
  Node head_;
  int len_{0};
  MyLinkedList() {
    head_.prev = &head_;
    head_.next = &head_;
  }

  int get(int index) {
    if (index >= len_) {
      return -1;
    }
    Node *p = &head_;
    for (int i = 0; i <= index; i++) {
      p = p->next;
    }
    return p->val;
  }

  void addAtHead(int val) {
    Node *nd = new Node();
    nd->val = val;
    add(nd, &head_);
    len_++;
  }
  void add(Node *nd, Node *prev) {
    nd->prev = prev;
    nd->next = prev->next;
    prev->next->prev = nd;
    prev->next = nd;
  }

  void addAtTail(int val) {
    Node *nd = new Node();
    nd->val = val;
    add(nd, head_.prev);
    len_++;
  }

  void addAtIndex(int index, int val) {
    if (index == 0) {
      addAtHead(val);
      return;
    }
    if (index == len_) {
      addAtTail(val);
      return;
    }
    if (index > len_) {
      return;
    }
    Node *p = &head_;
    for (int i = 0; i <= (index - 1); i++) {
      p = p->next;
    }
    Node *nd = new Node();
    nd->val = val;
    add(nd, p);
    len_++;
  }

  void deleteAtIndex(int index) {
    if (index >= len_) {
      return;
    }
    Node *p = &head_;
    for (int i = 0; i <= index; ++i) {
      p = p->next;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    p->prev = nullptr;
    p->next = nullptr;
    len_--;
    delete p;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main() {}