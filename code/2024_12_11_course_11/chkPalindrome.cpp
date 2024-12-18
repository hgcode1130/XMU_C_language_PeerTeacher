class PalindromeList {
public:
  //判断链表是否是回文的
  //思路：
  // 1. 找到链表的中间节点
  // 2. 后半部分逆置
  // 3. 逐点比对
  // 4. 若全部比对成功，则是回文链表

  bool chkPalindrome(ListNode *A) {
    if (A == NULL || A->next == NULL)
      return true;
    ListNode *slow, *fast, *prev, *cur, *nxt;
    slow = fast = A;
    // 找到中间节点
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    prev = NULL;
    // 后半部分逆置
    cur = slow;
    while (cur) {
      nxt = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nxt;
    }
            
    // 逐点比对
    while (A && prev) {
      if (A->val != prev->val)
        return false;
      A = A->next;
      prev = prev->next;
    }
    return true;
  }
};
