/*
删除重复的节点
描述

给定一个按升序排列的链表，链表中可能包含一些重复的节点。

请编写一个函数，删除链表中所有重复的节点，使得最终链表中只包含唯一出现过的节点。

注意，重复的节点不保留。


输入

输入一个已经排序的链表。


输出

输出删除重复节点后的链表，重复的节点不保留
*/

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

struct ListNode
{

    int val;

    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {} // 在struct中也可以写构造函数，用于对数据的初始化。例如，ListNode x(5) 表示：创建结构体变量x，其中x.val为5，x.next为空。
};

// create_list函数用于从输入数据中创建链表，并返回链表头指针

ListNode *create_list(const string &s)
{

    stringstream ss(s);

    string token;

    ListNode *head = NULL;

    ListNode *tail = NULL;

    while (getline(ss, token, '-'))
    {

        while (!token.empty() && !isdigit(token[0]))
        { // 删除非数字的字符

            token.erase(token.begin());
        }

        if (token.empty() || token == "NULL")
            continue;

        int num = stoi(token);

        ListNode *node = new ListNode(num);

        if (!head)
        {

            head = node;

            tail = node;
        }
        else
        {

            tail->next = node;

            tail = node;
        }
    }

    return head;
}

// delete_duplicates函数用于删除链表中的重复结点，并返回新链表的头指针

ListNode *delete_duplicates(ListNode *head)
{
    if (!head || !head->next)
    {
        return head; // 如果链表为空或只有一个节点，直接返回
    }

    // 创建哑节点，其 next 指向头节点
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *prev = dummy; // 前一个节点
    ListNode *curr = head;  // 当前节点

    while (curr)
    {
        // 如果当前节点和下一个节点的值相同，说明有重复
        if (curr->next && curr->val == curr->next->val)
        {
            int val = curr->val; // 记录重复值
            // 删除所有值为 val 的节点
            while (curr && curr->val == val)
            {
                ListNode *temp = curr;
                curr = curr->next;
                delete temp; // 释放内存
            }
            prev->next = curr; // 将前一个节点的 next 指向当前节点
        }
        else
        {
            // 如果没有重复，移动 prev 和 curr 指针
            prev = curr;
            curr = curr->next;
        }
    }

    ListNode *new_head = dummy->next;
    delete dummy; // 释放哑节点的内存
    return new_head;
}

// print_list函数用于将链表打印出来

void print_list(ListNode *head)
{

    ListNode *cur = head;

    while (cur)
    {

        cout << cur->val;

        if (cur->next)
            cout << "->";

        cur = cur->next;
    }

    cout << "->NULL" << endl;
}

int main()
{

    string list_str;

    getline(cin, list_str); // 从输入中读取一整行数据到list_str中

    ListNode *head = create_list(list_str);

    ListNode *new_head = delete_duplicates(head);

    print_list(new_head);

    return 0;
}