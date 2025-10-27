#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义链表结构，包含头节点
typedef struct LinkedList {
    Node* head;
} LinkedList;

// 创建链表，并初始化头节点
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = (Node*)malloc(sizeof(Node)); // 创建头节点
    list->head->next = NULL;  // 头节点的下一个指针为空
    return list;
}

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

// 在链表尾部插入节点
void append(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    Node* temp = list->head;

    // 移动到链表的最后一个节点
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; // 将新节点插入到尾部
}

// 删除指定节点
void deleteNode(LinkedList* list, int key) {
    Node* temp = list->head;
    Node* prev = NULL;

    // 查找要删除的节点
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("节点 %d 未找到\n", key);
        return;
    }

    // 断开链表中的节点并释放内存
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next; // 跳过要删除的节点
    free(nodeToDelete); // 释放内存
}

// 查找节点
Node* findNode(LinkedList* list, int key) {
    Node* current = list->head->next; // 跳过头节点
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL; // 未找到
}

// 打印链表
void printList(LinkedList* list) {
    Node* temp = list->head->next; // 跳过头节点
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(LinkedList* list) {
    Node* current = list->head;
    Node* next;
  
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list); // 释放链表结构
}

int main() {
    LinkedList* list = createLinkedList(); // 创建链表

    // 插入节点
    append(list, 1);
    append(list, 2);
    append(list, 3);
    append(list, 4);

    // 打印链表
    printf("链表内容: ");
    printList(list);

    // 删除节点
    deleteNode(list, 3);
    printf("删除3后: ");
    printList(list);

    // 查找节点
    Node* foundNode = findNode(list, 2);
    if (foundNode) {
        printf("找到节点: %d\n", foundNode->data);
    } else {
        printf("节点未找到\n");
    }

    // 释放链表内存
    freeList(list);
    
    return 0;
}
