/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
	int Ci, Co;
	struct ListNode *head, *tail, *l;
	struct ListNode *p, *q;
	struct ListNode *l3;

	if(l1 == NULL || l2 == NULL)
	{
		if(l1)
			return l2;
		else
			return l1;
	}

	p = l1;
	q = l2;
	head = tail =  NULL;
	Ci = Co = 0;

	while(p && q)
	{
		Co = Ci + p->val + q->val;
		if(Co >= 10)
		{
			Co -= 10;
			Ci = 1;
		}
		else
			Ci = 0;
		if(head == NULL)
		{
			l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
			l3->next = NULL;
			l3->val = Co;
			head = tail = l3;
		}
		else
		{
			l = (struct ListNode*)malloc(sizeof(struct ListNode));
			l->val = Co;
			l->next = NULL;
			tail->next = l;
			tail = l;
		}
		p = p->next;
		q = q->next;
	}

	while(p)
	{
		Co = Ci + p->val;
		if(Co >= 10)
		{
			Co -= 10;
			Ci = 1;
		}
		else
			Ci = 0;

		l = (struct ListNode*)malloc(sizeof(struct ListNode));
		l->val = Co;
		l->next = NULL;
		tail->next = l;
		tail = l;
		p = p->next;
	}

	while(q)
	{
		Co = Ci + q->val;
		if(Co >= 10)
		{
			Co -= 10;
			Ci = 1;
		}
		else
			Ci = 0;

		l = (struct ListNode*)malloc(sizeof(struct ListNode));
		l->val = Co;
		l->next = NULL;
		tail->next = l;
		tail = l;
		q = q->next;
	}

	if(p == NULL &&  q == NULL && Ci == 1)
	{
		l = (struct ListNode*)malloc(sizeof(struct ListNode));
		l->val = 1;
		l->next = NULL;
		tail->next = l;
		tail = l;
	}
	
	return l3;
}