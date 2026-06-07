
#include <stdlib.h>
#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    struct ListNode *head;
    struct ListNode *cur;
    struct ListNode *cur1;
    struct ListNode *cur2;
    if (list1->val <= list2->val)
    {
        head = list1;
        
        cur1 = list1->next;
        cur2 = list2;
    }
    else
    {
        head = list2;
        cur1 = list1;
        cur2 = list2->next;
    }
    cur = head;
    while (cur->next != NULL)
    {
        if(cur1->val <= cur2->val){
            cur->next = cur1;
            cur1 = cur1->next;
            if(cur1 == NULL){
                cur->next->next = cur2;
                break;
            }
        }else {
            cur->next = cur2;
            cur2 = cur2->next;
            if(cur2 == NULL){
                cur->next->next = cur1;
                break;
            }
        }
        cur = cur->next;
    }

    
    return head;
}

int main(int argc, char const *argv[])
{
    struct ListNode *list1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    ;
    list1->val = 1;
    list1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list1->next->val = 2;
    list1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list1->next->next->val = 4;
    list1->next->next->next = NULL;
    struct ListNode *list2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    ;
    list2->val = 1;
    list2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list2->next->val = 3;
    list2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    struct ListNode *mergedList = mergeTwoLists(list1, list2);
    while (mergedList != NULL)
    {
        printf("%d \n", mergedList->val);
        mergedList = mergedList->next;
    }
    return 0;
}
