struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *p1 = l1, *p2 = l2;
  struct ListNode *newhead = NULL, *tail = NULL;

  if (p1 == NULL) {
    return p2;
  }
  if (p2 == NULL) {
    return p1;
  }

  newhead = tail = (struct ListNode *)malloc(sizeof(struct ListNode));
  // 创建新结点

  while (p1 && p2) // 开始一一比较并进行连接
  {
    (p1->val) <= (p2->val) ? // 比较谁小
        (tail->next = p1, p1 = p1->next, tail = tail->next)
                           :
                           // p1的值更小,则连接p1,然后tail和p1迭代
        (tail->next = p2, p2 = p2->next, tail = tail->next);
    // p2的值更小,则连接p2,然后tail和p2迭代
  }
  // 特别注意下这里，第一次刷犯错了
  p1 ? (tail->next = p1) : (p1); // 如果p1还有值,则把剩下的p1连接
  p2 ? (tail->next = p2) : (p2); // 如果p2还有值,则把剩下的p2连接

  struct ListNode *pp = newhead->next; // 保存哑结点后面的结点
  free(newhead);                       // 释放哑结点
  newhead = NULL;
  return pp;
}
