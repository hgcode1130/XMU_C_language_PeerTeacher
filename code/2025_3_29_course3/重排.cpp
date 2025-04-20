#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *createList()
{
    ListNode *head = NULL;
    ListNode *p1, *p2;
    p1 = new ListNode;
    p2 = p1;
    cin >> p1->val;
    while (p1->val != -1)
    {
        if (head == NULL)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = new ListNode;
        cin >> p1->val;
    }
    p2->next = NULL;
    delete p1;
    return head;
}

ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    // odd 和 even 的链表
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even; // 保存偶数链表的头部

    // 遍历链表，将奇数和偶数节点分别连接
    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    // 将奇数链表的尾部连接到偶数链表
    odd->next = evenHead;

    return head;
}

int main()
{
    ListNode *head;
    head = createList();
    ListNode *ans = oddEvenList(head);

    if (ans == NULL)
    {
        cout << "-1";
    }
    else
    {
        while (ans != NULL)
        {
            cout << ans->val << " ";
            ans = ans->next;
        }
    }

    return 0;
}
