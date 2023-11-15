//Judge if the linked list has a circle;
/*
示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。

*/
#include <stddef.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
int hasCycle(struct ListNode *head) {
    if(head==NULL)
        return 0;
    struct ListNode *p;//p is the slow pointer;
    struct ListNode *q;//q is the fast pointer;
    p=head;
    q=head;
    while(p!=NULL&&q!=NULL&&q->next!=NULL){
        p=p->next;
        q=q->next->next;
        if(p==q){
            return 1;
        }
    }
    return 0;//flag is if the LinkedList is the circle list.
}