/*
左旋字符串
描述

字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。

请编写一个函数实现字符串左旋转操作的功能。

比如输入字符串 "abcdefg" 和数字 2，该函数将返回左旋转 2 位得到的结果 "cdefgab" 。


输入

输入一个字符串和一个整数 n 。


输出

输出左旋转后的字符串。
*/

#include <iostream>
#include <string>
using namespace std;

struct CharNode
{
    char val;
    CharNode *next;
    CharNode(char c) : val(c), next(NULL) {}
};

// 将字符串转为链表
CharNode *StringToList(const string &str)
{
    CharNode dummy(0);
    CharNode *tail = &dummy;
    for (int i = 0; i < str.size(); ++i)
    {
        CharNode *newNode = new CharNode(str[i]);
        tail->next = newNode;
        tail = newNode;
    }
    return dummy.next;
}

// 获取链表长度
int ListLength(CharNode *head)
{
    int length = 0;
    while (head)
    {
        length++;
        head = head->next;
    }
    return length;
}

// 链表转为字符串
string ListToString(CharNode *head)
{
    string result = "";
    while (head)
    {
        result += head->val;
        head = head->next;
    }
    return result;
}

// 释放链表内存
void FreeList(CharNode *head)
{
    while (head)
    {
        CharNode *temp = head;
        head = head->next;
        delete temp;
    }
}

// 左旋操作
CharNode *LeftRotate(CharNode *head, int n)
{
    if (!head || n <= 0)
    {
        return head;
    }

    // 找到第 n 个节点
    CharNode *current = head;
    for (int i = 1; i < n && current; ++i)
    {
        current = current->next;
    }

    // 如果 n 大于链表长度，直接返回原链表
    if (!current || !current->next)
    {
        return head;
    }

    // 新链表的头节点
    CharNode *newHead = current->next;

    // 断开链表
    current->next = NULL;

    // 找到原链表的尾部
    CharNode *tail = newHead;
    while (tail->next)
    {
        tail = tail->next;
    }

    // 连接链表
    tail->next = head;

    return newHead;
}

int main()
{
    string s;
    getline(cin, s);               // 读取带引号的字符串，比如 "abcdefg"
    s = s.substr(1, s.size() - 2); // 去掉前后的引号
    string n_str;
    getline(cin, n_str); // 读取数字 n
    int n = stoi(n_str); // 转换为整数

    // 字符串 → 链表
    CharNode *head = StringToList(s);

    // 左旋操作
    CharNode *rotated = LeftRotate(head, n);

    // 输出结果
    cout << ListToString(rotated) << endl;

    // 清理内存
    FreeList(rotated);

    return 0;
}
