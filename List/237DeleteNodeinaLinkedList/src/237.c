/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node)
{
	struct ListNode* p;
	p = node;
	while(p->next && p->next->next)
	{
		p->val = p->next->val;
		p = p->next;
	}
    p->val = p->next->val;
    p->next = NULL;
    
}