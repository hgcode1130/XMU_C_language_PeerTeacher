struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
    node->next=head; //创建哑结点，链接
    struct ListNode* cur=node;//迭代 

    while(cur->next)
    {
        if(cur->next->val==val)
        {
            struct ListNode*x=cur->next;
            cur->next=cur->next->next;
            free(x);           //释放被删除结点空间
        }
        else
        {
            cur=cur->next;
        }
    }
    return node->next;
}
