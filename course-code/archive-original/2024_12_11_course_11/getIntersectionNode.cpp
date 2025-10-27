/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA,
                                     struct ListNode *headB) {
  int lenA = 0, lenB = 0;
  struct ListNode *curA = headA, *curB = headB;
  // 计算两个链表的长度
  while (curA) {
    lenA++;
    curA = curA->next;
  }
  while (curB) {
    lenB++;
    curB = curB->next;
  }
  //
  int len = abs(lenA - lenB);
  struct ListNode *LongList = headA, *ShortList = headB;
  if (lenA < lenB) {
    LongList = headB;
    ShortList = headA;
  }
  // 让长链表先走len步
  while (len--) {
    LongList = LongList->next;
  }
  // 双链表同时走，直到相遇
  while (LongList && ShortList) {
    if (LongList == ShortList)
      return LongList;
    else {
      LongList = LongList->next;
      ShortList = ShortList->next;
    }
  }
  return NULL;
}