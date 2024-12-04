#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 插入节点到链表尾部
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 在指定位置插入节点
void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("位置超出范围\n");
        free(newNode); // 释放内存
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

// 删除指定节点
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    // 如果头节点是要删除的节点
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // 更改头节点
        free(temp); // 释放旧头节点
        return;
    }

    // 查找要删除的节点
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // 如果没有找到节点
    if (temp == NULL) {
        printf("节点未找到\n");
        return;
    }

    // 断开链表中的节点并释放内存
    prev->next = temp->next;
    free(temp);
}

// 查找节点
Node* findNode(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL; // 未找到
}

// 打印链表
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 反转链表
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next; // 暂存下一个节点
        current->next = prev; // 反转当前节点的指针
        prev = current; // 移动prev到当前节点
        current = next; // 移动到下一个节点
    }
    *head = prev; // 更新头指针
}

// 释放链表内存
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;  // 初始化链表头

    // 插入节点
    append(&head, 1);
    append(&head, 3);
    append(&head, 4);
    
    // 打印链表
    printf("链表内容: ");
    printList(head);

    // 在指定位置插入节点
    insertAtPosition(&head, 2, 1);
    printf("插入2后: ");
    printList(head);

    // 删除节点
    deleteNode(&head, 3);
    printf("删除3后: ");
    printList(head);

    // 查找节点
    Node* foundNode = findNode(head, 2);
    if (foundNode) {
        printf("找到节点: %d\n", foundNode->data);
    } else {
        printf("节点未找到\n");
    }

    // 反转链表
    reverseList(&head);
    printf("反转后: ");
    printList(head);

    // 释放链表内存
    freeList(head);
    
    return 0;
}
