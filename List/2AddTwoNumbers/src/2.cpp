/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static int speed = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l;
        ListNode* p;
        ListNode* newNode;
        int carry;

        l = NULL;
        p = NULL;
        carry = 0;

        while(l1 || l2 || carry)
        {
        	carry += (l1 ? l1->val : 0);
        	carry += (l2 ? l2->val : 0);

        	newNode = new ListNode(carry%10);
        	carry /= 10;

        	if(!l)
        		l = newNode;
        	if(p)
        		p->next = newNode;
        	p = newNode;
        	if(l1)
        		l1 = l1->next;
        	if(l2)
        		l2 = l2->next;
        }
        return l;

    }
};