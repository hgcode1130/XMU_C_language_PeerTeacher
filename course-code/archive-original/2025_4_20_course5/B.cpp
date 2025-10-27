/*
第一个公共结点
描述

输入两个链表，编写一个函数来找出它们的第一个公共结点。

第一个公共结点的定义：从这一结点开始，两个链表的后续结点序列的值相同。

如果两个链表没有公共结点，则返回NULL。


输入

输入为两个链表。保证两个链表不会完全相同。


输出

输出为第一个公共结点。
*/

#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

// 本题使用的数据结构为双链表，每个结点都有prev和next指针，可以从链表的任意位置向前或向后遍历。使用node->prev访问node结点的前一结点，使用node->next访问node结点的后一结点。

// 头结点（链表的第一个结点）的prev指针和尾结点（最后一个结点）的next指针均为NULL。

struct ListNode
{

    string val; // string类，用于处理字符串

    ListNode *next; // 指向下一个结点的指针

    ListNode *prev; // 指向前一个结点的指针

    ListNode(string x) : val(x), prev(NULL), next(NULL) {} // struct中的构造函数，用于对链表结点的初始化
};

// buildList函数用于从输入字符串input创建链表，创建好的链表头指针存储在head中，尾指针存储在tail中

void buildList(const string &input, ListNode *&head, ListNode *&tail)
{

    if (input.empty())

    {

        head = NULL;

        tail = NULL;

        return;
    }

    // 移除结尾的 "->NULL"

    const string tail_str = "->NULL";

    string trimmedInput = input;

    if (trimmedInput.size() >= tail_str.size() && trimmedInput.substr(trimmedInput.size() - tail_str.size()) == tail_str)
    {

        trimmedInput = trimmedInput.substr(0, trimmedInput.size() - tail_str.size());
    }

    // 分割字符串并构建链表

    stringstream ss(trimmedInput);

    string item;

    ListNode *dummyHead = new ListNode("");

    ListNode *current = dummyHead;

    tail = dummyHead;

    while (getline(ss, item, '-'))
    {

        if (item.back() == '>')
        {

            item.pop_back();
        }

        if (!item.empty() && (item.front() == '>' && item.size() > 1))
        {

            item = item.substr(1);
        }

        if (!item.empty())
        {

            ListNode *newNode = new ListNode(item);

            current->next = newNode;

            newNode->prev = current;

            current = current->next;

            tail = newNode;
        }
    }

    head = dummyHead->next;

    return;
}

ListNode *findFirstCommonNode(ListNode *headA, ListNode *tailA,
                              ListNode *headB, ListNode *tailB)
{
    // 从尾部开始比较
    ListNode *pA = tailA;
    ListNode *pB = tailB;

    // 向前走，只要值相等就继续
    while (pA && pB && pA->val == pB->val)
    {
        pA = pA->prev;
        pB = pB->prev;
    }

    // 如果根本没有匹配（一次循环都没进），则没有公共后缀
    if (pA == tailA)
    {
        return NULL;
    }

    // 否则公共后缀的起点就是 pA 的下一个结点
    // （当比较失败跳出时，pA 已经指向第一个不匹配的结点）
    return pA ? pA->next : headA;
}

int main()
{

    string lineA, lineB;

    getline(cin, lineA); // 从输入中读取一整行数据到lineA中

    getline(cin, lineB); // 从输入中读取一整行数据到lineB中

    ListNode *headA, *tailA;

    ListNode *headB, *tailB;

    headA = tailA = headB = tailB = NULL;

    buildList(lineA, headA, tailA); // 从输入数据中创建链表

    buildList(lineB, headB, tailB); // 从输入数据中创建链表

    ListNode *commonNode = findFirstCommonNode(headA, tailA, headB, tailB);

    if (commonNode != NULL)
    {

        cout << commonNode->val << endl;
    }
    else
    {

        cout << "NULL" << endl;
    }

    return 0;
