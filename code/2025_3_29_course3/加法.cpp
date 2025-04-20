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

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // 反转链表 l1 和 l2
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    int carry = 0;
    ListNode *result = NULL;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;

        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        // 创建新节点并添加到结果链表
        ListNode *newNode = new ListNode;
        newNode->val = sum % 10;
        newNode->next = result;
        result = newNode;
    }

    return result;
}

int main()
{
    ListNode *head1, *head2;
    head1 = createList();
    head2 = createList();
    ListNode *ans = addTwoNumbers(head1, head2);
    if (ans == NULL)
        cout << "-1";
    else
    {
        while (ans != NULL)
        {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout << "-1";
    }
    return 0;
}
