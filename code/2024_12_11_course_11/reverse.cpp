struct ListNode *reverseList(struct ListNode *head) {
  struct ListNode *prev = NULL; // 新建一个prev指针置为NULL
  struct ListNode *cur = head;  // cur指针赋值为头结点head
  struct ListNode *next = NULL; // 新建一个next
  while (cur) {
    next = cur->next; // next保存下一个结点
    cur->next = prev; // cur指向前一个结点prev
    prev = cur;       // prev移动到当前cur位置
    cur = next;       // cur移动到当前next位置
  }
  return prev;
}
