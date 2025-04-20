/*
把字符串转换成整数
描述

请你写一个函数 StrToInt，实现把字符串转换成整数这个功能。

注意以下各种情况，都需要处理：

1) 空字符串：空输入。

2) 普通数字：基本转换。

3) 前导零：去掉前导零的逻辑。

4) 负号：需处理负号。

5) 前导空格：空格忽略。

6) 非数字字符：只提取数字部分。


输入

输入一个字符串。


输出

输出转换后的整数。
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

CharNode *StringToList(const string &str)
{
    CharNode dummy(0);
    CharNode *tail = &dummy;
    for (int i = 0; i < str.size(); ++i)
    {
        char c = str[i];
        CharNode *newNode = new CharNode(c);
        tail->next = newNode;
        tail = newNode;
    }
    return dummy.next;
}

void FreeList(CharNode *head)
{
    while (head)
    {
        CharNode *temp = head;
        head = head->next;
        delete temp;
    }
}

string StrToInt(CharNode *head)
{
    string result;
    bool isNegative = false;
    bool hasNumber = false;

    // 跳过前导空格
    while (head && head->val == ' ')
    {
        head = head->next;
    }

    // 处理符号
    if (head && (head->val == '+' || head->val == '-'))
    {
        if (head->val == '-')
        {
            isNegative = true;
        }
        head = head->next;
    }

    // 跳过前导零
    while (head && head->val == '0')
    {
        head = head->next;
    }

    // 提取数字
    while (head && isdigit(head->val))
    {
        result += head->val;
        hasNumber = true;
        head = head->next;
    }

    // 如果没有任何数字，返回0
    if (!hasNumber)
    {
        return "0";
    }

    // 添加符号
    if (isNegative)
    {
        result = "-" + result;
    }

    return result;
}

int main()
{
    string input;
    getline(cin, input);
    if (!input.empty() && input.front() == '"')
    {
        input = input.substr(1);
    }
    if (!input.empty() && input.back() == '"')
    {
        input = input.substr(0, input.size() - 1);
    }
    CharNode *head = StringToList(input);
    string result = StrToInt(head);
    cout << result << endl;
    FreeList(head);
    return 0;
}
