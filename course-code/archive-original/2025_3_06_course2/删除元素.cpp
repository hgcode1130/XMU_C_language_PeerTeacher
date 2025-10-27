#include<iostream>
using namespace std;

struct node {
    int val;
    node* next;
};

// 创建链表
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

// 删除指定元素
node* deleteElements(node* head, int v) {
    // 处理链表头节点需要删除的情况
    while (head != NULL && head->val == v) {
        node* temp = head;
        head = head->next;
        delete temp;  // 释放原头节点的内存
    }

    // 处理剩余节点
    node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->val == v) {
            node* temp = curr->next;
            curr->next = curr->next->next;  // 跳过需要删除的节点
            delete temp;  // 释放被删除节点的内存
        } else {
            curr = curr->next;  // 移动到下一个节点
        }
    }

    return head;
}

int main() {
    node* head = NULL;
    head = createList();  // 创建链表

    int v;
    cin >> v;  // 输入需要删除的元素值

    head = deleteElements(head, v);  // 删除指定元素

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
