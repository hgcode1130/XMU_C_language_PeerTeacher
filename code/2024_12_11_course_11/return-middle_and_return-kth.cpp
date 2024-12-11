// struct ListNode *getKthFromEnd(struct ListNode *head, int k) {
//   struct ListNode *slow, *fast;
//   slow = fast = head; // 创建快慢指针

//   while (k--) // fast先走K步
//   {
//     if (fast) // 注意!!!!这里必须要判断,为什么呢?因为题目并没有规定k是小于等于链表长度的哦
//       fast = fast->next;
//     else
//       return NULL;
//   }
//   while (fast) // 同步
//   {
//     fast = fast->next;
//     slow = slow->next;
//   }
//   return slow;
// }

struct ListNode *middleNode(struct ListNode *head) {
  struct ListNode *fast, *slow; // 定义快慢指针
  fast = slow = head;
  while (fast && (fast->next))
  // 当fast为空,或者fast->next为空,就结束循环,说明此时slow已经走到了中间结点
  {
    fast = fast->next->next; // fast走两步
    slow = slow->next;       // slow走一步
  }
  return slow;
}
