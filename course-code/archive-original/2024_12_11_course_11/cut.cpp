struct ListNode *partition(struct ListNode *head, int x) {
  struct ListNode *small = malloc(sizeof(struct ListNode));
  struct ListNode *smallHead = small;
  struct ListNode *large = malloc(sizeof(struct ListNode));
  struct ListNode *largeHead = large;
  while (head) {
    if (head->val < x) {
      small->next = head;
      small = small->next;
    } else {
      large->next = head;
      large = large->next;
    }
    head = head->next;
  }
  large->next = NULL;
  small->next = largeHead->next; // 把large哑结点后的结点链接给small
  return smallHead->next;        // 返回small哑结点后的结点
}
