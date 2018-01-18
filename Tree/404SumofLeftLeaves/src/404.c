/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root)
{
	if(root == NULL)
		return 0;

	if(root->left)
	{
		if(root->right && root->left->left == NULL && root->left->right == NULL)
			return root->left->val + sumOfLeftLeaves(root->right);

		if(root->right == NULL && root->left->left == NULL && root->left->right == NULL)
			return root->left->val;
	}

	return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}