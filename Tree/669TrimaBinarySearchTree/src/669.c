/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* trimBST(struct TreeNode* root, int L, int R)
{
	if(root == NULL)
		return NULL;

	if(root->val >= L && root->val <= R)
	{
		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);
	}

	if(root->val < L)
	{
		root->left = NULL;
		root = trimBST(root->right, L, R);
	}
    
	else if(root->val > R)
	{
		root->right = NULL;
		root = trimBST(root->left, L, R);
	}

	return root;
}