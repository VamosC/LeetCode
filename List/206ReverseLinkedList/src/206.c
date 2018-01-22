/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* p;
	struct ListNode* tail, *Tmp;

	if(head == NULL)
		return NULL;

	tail = head;
	p = head->next;
    tail->next = NULL;
	while(p)
	{
		Tmp = p->next;
		p->next = tail;
		tail = p;
		p = Tmp;
	}
	return tail;
}