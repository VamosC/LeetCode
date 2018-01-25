/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* p, *q;
    if(head == NULL)
        return NULL;
	if(head->next == NULL)
		return head;
	q = p = reverseList(head->next);
	while(p->next)
		p = p->next;

	head->next = NULL;
	p->next = head;
	return q;
}