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

ListNode *getKthFromEnd(ListNode *head, int k)
{
    k++;
    if (head == NULL || k <= 0)
    {
        return NULL; // 空链表或者无效的k
    }

    ListNode *first = head;
    ListNode *second = head;

    // Move first pointer k steps ahead
    for (int i = 0; i < k; ++i)
    {
        if (first == NULL)
        {
            return NULL; // k大于链表的长度
        }
        first = first->next;
    }

    // Move both pointers until first reaches the end
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    // second points to the kth node from the end
    return second;
}

int main()
{
    ListNode *head;
    int k;
    head = createList();
    cin >> k;

    ListNode *ans = getKthFromEnd(head, k);
    if (ans == NULL)
    {
        cout << "-1";
    }
    else
    {
        cout << ans->val;
    }

    return 0;
}
