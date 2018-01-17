/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root)
{
	struct TreeNode* T;
	if(root == NULL)
		return NULL;

	T = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(T);
	return root;
}