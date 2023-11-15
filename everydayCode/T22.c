//combine 2 sorted-linked list;
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy; // 使用一个虚拟头节点，使得操作更简单
    struct ListNode* current = &dummy; // 用于遍历新链表的指针

    while (l1 && l2) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // 处理剩余的节点
    if (l1) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    return dummy.next;
}