#include<iostream>
using namespace std;

struct node {
    int val;
    node* next;
};

// 创建链表的函数
node* createList() {
    node* head = NULL;
    node* tail = NULL;
    int num;

    while (true) {
        cin >> num;
        if (num == -1) {
            break;  // 输入为-1时结束
        }

        // 创建新节点
        node* newNode = new node;
        newNode->val = num;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;  // 第一个节点作为头节点
            tail = head;     // 第一个节点也是尾节点
        } else {
            tail->next = newNode;  // 将新节点链接到尾节点后
            tail = newNode;        // 更新尾节点为新节点
        }
    }

    return head;
}

node* reverseList(node* head) {
    node* prev = NULL;   // 初始化前一个节点为空
    node* curr = head;   // 当前节点从头节点开始
    node* next = NULL;   // 下一个节点初始化为空

    while (curr != NULL) {
        next = curr->next;   // 暂时保存下一个节点
        curr->next = prev;   // 反转当前节点的指向
        prev = curr;         // 将 prev 指向当前节点
        curr = next;         // 将 curr 移动到下一个节点
    }

    return prev;  // 当 curr 为 NULL 时，prev 指向新的头节点
}

int main() {
    node* head = NULL;
    head = createList();

    if (head == NULL) {
        cout << "-1 ";  // 如果链表为空，输出-1
    } else {
        node* p = head;
        while (p != NULL) {
            cout << p->val << " ";  // 输出链表中的每个节点值
            p = p->next;
        }
    }

    return 0;
}
