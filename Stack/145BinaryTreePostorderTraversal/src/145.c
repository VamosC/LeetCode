/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 10000
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
	struct TreeNode* Stack[MAX];
	struct TreeNode *p, *q, *t;
	int* result;
	int Known[MAX];
	int i;
	int top;

	if(root == NULL)
		return NULL;

	for(i = 0;i < MAX;i++)
		Known[i] = 0;
	//init
	top = -1;
	i = 0;
	result = (int*)malloc(MAX*sizeof(int));
	Stack[++top] = root;
	while(top != -1)
	{
		p = Stack[top--];
		if(p->left == NULL && p->right == NULL && Known[p->val] == 1)
			result[i++] = p->val;
		else
		{
			Known[p->val] = 1;
			Stack[++top] = p;
			if(p->right)
				Stack[++top] = p->right;
			if(p->left)
				Stack[++top] = p->left;
		}
	}
	*returnSize = i;
	return result;
}