
// 自底向上进行归并排序
// 思路不难，但是链表操作很麻烦
// 可以增加虚拟头结点，便于进行链表操作
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* sortList(ListNode* head) {
      if(head == nullptr){
        return head;
      }
      int n = 0;
      ListNode* node = head;
      //得到链表长度
      while(node != nullptr){
        ++n;
        node = node->next;
      }
      ListNode* dummy_head = new ListNode(0, head);
      //枚举sub_len的长度，把两个sub_len长的子链表进行归并
      for(int sub_len = 1; sub_len < n; sub_len <<= 1){
        ListNode* prev = dummy_head;
        ListNode* curr = dummy_head->next;
        while(curr != nullptr){
          ListNode* head1 = curr;
          for(int i = 1; i < sub_len && curr->next != nullptr; ++i){
            curr = curr->next;
          }
          ListNode* head2 = curr->next;
          curr->next = nullptr;
          curr = head2;
          for(int i = 1; i < sub_len && curr != nullptr && curr->next != nullptr; ++i){
            curr = curr->next;
          }
          ListNode* next = nullptr;
          if(curr != nullptr){
            next = curr->next;
            curr->next = nullptr;
          }
          //把两个长度sub_len的子链表合并
          ListNode* merged = merge(head1, head2);
          prev->next = merged;
          while(prev->next != nullptr){
            prev = prev->next;
          }
          curr = next;
        }
      }

      ListNode* new_head = dummy_head->next;
      dummy_head->next = nullptr;
      delete dummy_head;
      return new_head;
    }
    ListNode* merge(ListNode *head1, ListNode *head2){
      ListNode* dummyHead = new ListNode(0);
      ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
      while (temp1 != nullptr && temp2 != nullptr) {
          if (temp1->val <= temp2->val) {
              temp->next = temp1;
              temp1 = temp1->next;
          } else {
              temp->next = temp2;
              temp2 = temp2->next;
          }
          temp = temp->next;
      }
      if (temp1 != nullptr) {
          temp->next = temp1;
      } else if (temp2 != nullptr) {
          temp->next = temp2;
      }
      ListNode* head = dummyHead->next;
      dummyHead->next = nullptr;
      delete dummyHead;
      return head;
    }
};