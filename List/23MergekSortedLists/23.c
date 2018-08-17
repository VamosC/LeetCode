/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* add(struct ListNode* l1, struct ListNode* l2);
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    struct ListNode* p;
    int i;
    if(listsSize == 0)
    {
        return NULL;
    }    
    if(listsSize == 1)
    {
        return lists[0];
    }
    p = NULL;
    p = add(lists[0], lists[1]);
    for(i = 2;i < listsSize;i++)
    {
        p = add(p, lists[i]);
    }
    return p;
}

struct ListNode* add(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *l, *head, *tail;
    struct ListNode *old;
    head = l = tail = NULL;
    if(l1 == NULL)
    {
        return l2;
    }
    if(l2 == NULL)
    {
        return l1;
    }

    while(l1 && l2)
    {
        l = (struct ListNode*)malloc(sizeof(struct ListNode));
        l->next = NULL;
        if(l1->val < l2->val)
        {
            l->val = l1->val;
            old = l1;
            l1 = l1->next;
            free(old);
        }
        
        else
        {
            l->val = l2->val;
            old = l2;
            l2 = l2->next;
            free(old);
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
        old = l1;
        l1 = l1->next;
        free(old);
        tail->next = l;
        tail = l;
    }

    while(l2)
    {
        l = (struct ListNode*)malloc(sizeof(struct ListNode));
        l->next = NULL;
        l->val = l2->val;
        old = l2;
        l2 = l2->next;
        free(old);
        tail->next = l;
        tail = l;
    }

    return head;
}