/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode* Position;
Position FindMin(struct TreeNode* root);
Position FindMax(struct TreeNode* root);
bool isValidBST(struct TreeNode* root)
{
	if(root == NULL)
		return 1;
	if(root->left == NULL && root->right == NULL)
		return 1;
	if(root->left == NULL)
	{
		if(root->val < FindMin(root->right)->val && isValidBST(root->right))
			return 1;
		else
			return 0;
	}
	if(root->right == NULL)
	{
		if(root->val > FindMax(root->left)->val && isValidBST(root->left))
			return 1;
		else
			return 0;
	}

	if(root->val < FindMin(root->right)->val && root->val > FindMax(root->left)->val && isValidBST(root->left)
		&& isValidBST(root->right))
		return 1;
	return 0;
}

Position FindMin(struct TreeNode* root)
{
	if(root == NULL)
		return NULL;
	if(root->left)
		return FindMin(root->left);
	return root;
}

Position FindMax(struct TreeNode* root)
{
	if(root == NULL)
		return NULL;
	if(root->right)
		return FindMax(root->right);
	return root;
}
