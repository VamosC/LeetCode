/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) 
{
    struct ListNode *p, *q, *tail;
    p = head;
    tail = NULL;
    while(p && p->next)
    {
        q = p->next;
        p->next = q->next;
        q->next = p;
        if(tail == NULL)
        {
            head = q;
        }
        else
        {
            tail->next = q;
        }
        tail = p;
        p = p->next;
    }
    return head;
}