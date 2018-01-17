/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool visit(struct TreeNode* root, int sum, int length);
bool hasPathSum(struct TreeNode* root, int sum)
{
	if(root == NULL)
		return 0;

	if(visit(root, sum, 0))
		return 1;
	return 0;
}

bool visit(struct TreeNode* root, int sum, int length)
{
	if(root == NULL) 
		return 0;
	if(root->left == NULL && root->right == NULL)
		return (length + root->val) == sum ? 1 : 0;

	return visit(root->left, sum, length + root->val) || visit(root->right, sum, length + root->val);
}