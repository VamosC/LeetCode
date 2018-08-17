/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *l, *head, *tail;
    if(l1 == NULL)
    {
        return l2;
    }
    if(l2 == NULL)
    {
        return l1;
    }
    head = l = NULL;
    while(l1 && l2)
    {
        l = (struct ListNode*)malloc(sizeof(struct ListNode));
        l->next = NULL;
        if(l1->val < l2->val)
        {
            l->val = l1->val;
            l1 = l1->next;
        }
        
        else
        {
            l->val = l2->val;
            l2 = l2->next;
        }
        if(head == NULL)
        {
            head = l;
        }
        
        else
        {
            tail->next = l;
        }
        tail = l;
    }

    while(l1)
    {
        l = (struct ListNode*)malloc(sizeof(struct ListNode));
        l->next = NULL;
        l->val = l1->val;
        tail->next = l;
        tail = l;
        l1 = l1->next;
    }

    while(l2)
    {
        l = (struct ListNode*)malloc(sizeof(struct ListNode));
        l->next = NULL;
        l->val = l2->val;
        tail->next = l;
        tail = l;
        l2 = l2->next;
    }

    return head;
}