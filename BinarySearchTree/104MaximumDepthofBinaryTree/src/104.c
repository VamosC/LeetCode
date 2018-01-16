/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b);
int maxDepth(struct TreeNode* root) 
{
	if(root == NULL)
		return 0;

	if(root->left&&root->right)
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;

	if(root->left)
		return maxDepth(root->left) + 1;

	if(root->right)
		return maxDepth(root->right) + 1;

	return 1;
}

int max(int a, int b)
{
	return a > b ? a : b;
}