//delete the kth nodes in the linked list
/*
示例 1：

输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]*/

struct ListNode {
     int val;
     struct ListNode *next;
};


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* p = dummy;
    struct ListNode* q = dummy;
    
    // Move q n nodes ahead
    for (int i = 0; i < n + 1; i++) {
        q = q->next;
    }
    
    // Move p and q together until q reaches the end
    while (q != NULL) {
        p = p->next;
        q = q->next;
    }
    
    // Delete the nth node from the end
    struct ListNode* temp = p->next;
    p->next = temp->next;
    free(temp);
    
    return dummy->next;
}