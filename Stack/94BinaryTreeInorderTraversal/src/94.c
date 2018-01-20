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
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	int* result;
	struct TreeNode* Stack[MAX];
	struct TreeNode* T;
	int top;
	int i;

	*returnSize = 0;
	if(root == NULL)
		return NULL;

	result = (int*)malloc(MAX*sizeof(int));
	top = -1;
	i = 0;
	T = root;
	while(1)
	{
		for(;T;T = T->left)
			Stack[++top] = T;
		T = Stack[top--];
        result[i++] = T->val;
		T = T->right;
        if(T == NULL && top == -1)
            break;
	}
	*returnSize = i;
	return result;
}