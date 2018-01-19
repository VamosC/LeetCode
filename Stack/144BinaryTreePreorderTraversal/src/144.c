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
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	struct TreeNode* Stack[MAX];
	struct TreeNode* p;
	int top;
	int i;

	//init
	top = -1;
	i = 0;
	if(root == NULL)
		return NULL;

	returnSize = (int*)malloc(MAX*sizeof(int));
	Stack[++top] = root;
	while(top != -1)
	{
		p = Stack[top--];
		a[i++] = p->val;
		if(p->right)
			Stack[++top] = p->right;
		if(p->left)
			Stack[++top] = p->left;
	}

	return returnSize;
}