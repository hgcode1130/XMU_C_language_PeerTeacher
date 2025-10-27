/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;
struct ListNode *detectCycle(struct ListNode *head) {
  Node *slow, *fast;
  slow = fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    // 标记相遇点,并重新建个指针指向头
    if (slow == fast) {
      Node *meet = slow;
      Node *start = head;

      while (meet != start) {
        meet = meet->next;
        start = start->next;
      }
      return meet;
    }
  }
  return NULL;
}
