//rotate the linked-list
/*
示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
示例 2：


输入：head = [0,1,2], k = 4
输出：[2,0,1]
*/
#include <stddef.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p;
    if(head==NULL||head->next==NULL)
        return head;
    dummy->next=head;
    p=head;
    int a[501]={0};
    int i=-1;
    while(p!=NULL){
        a[++i]=p->val;
        p=p->next;
    }//put all the elements into the array;i represents the last element of the linked list;
    int b[501]={0};
    for(int j=0;j<=i;j++)
        b[(j+k)%(i+1)]=a[j];
    p=head;
    int j=0;
    while(p!=NULL){
        p->val=b[j];
        j++;
        p=p->next;
    }
    return dummy->next;

}