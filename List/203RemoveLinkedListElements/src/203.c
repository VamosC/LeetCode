/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* p;
	struct ListNode* Tmp;
	p = head;
	if(head == NULL)
		return NULL;

	while(head && head->val == val)
	{
		head = head->next;
		free(p);
		p = head;
	}

	while(p && p->next)
	{
		Tmp = p->next;
		if(Tmp->val == val)
		{
			p->next = Tmp->next;
			free(Tmp);
		}
		else
		{
			p = p->next;
		}
	}
	return head;
}