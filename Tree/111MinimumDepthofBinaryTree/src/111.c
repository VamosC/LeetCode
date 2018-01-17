/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int min(int a, int b);
int minDepth(struct TreeNode* root) 
{
	if(root == NULL)
		return 0;
	if(root->left&&root->right)
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	if(root->left)
		return minDepth(root->left) + 1;
	if(root->right)
		return minDepth(root->right) + 1;
	return 1;
}

int min(int a, int b)
{
	return a < b ? a : b;
}