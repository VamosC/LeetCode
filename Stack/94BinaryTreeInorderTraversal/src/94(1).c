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
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	int* result;
	struct TreeNode** Stack;
	struct TreeNode* T;
	int top;
	int i, j;

	*returnSize = 0;
    Stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
	if(root == NULL)
		return NULL;

	result = (int*)malloc(sizeof(int));
	top = -1;
	i = 0;
    j = 0;
	T = root;
	while(1)
	{
		for(;T;T = T->left)
        {
            Stack = (struct TreeNode**)realloc(Stack, (++j)*sizeof(struct TreeNode*));
            Stack[++top] = T;
        }
		T = Stack[top--];
        result = (int*)realloc(result, (i+1)*sizeof(int));
        result[i++] = T->val;
		T = T->right;
        if(T == NULL && top == -1)
            break;
	}
	*returnSize = i;
	return result;
}