/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int deepest,leftmost;
void visitTree(struct TreeNode* root, int depth);
int findBottomLeftValue(struct TreeNode* root)
{
	leftmost = 0;
	deepest = -1;
	visitTree(root, 0);
	return leftmost;
}

void visitTree(struct TreeNode* root, int depth)
{
	if(root == NULL)
		return;

	if(root->left == NULL && root->right == NULL)
	{
		if(depth > deepest)
		{
			deepest = depth;
			leftmost = root->val;
		}
	}
	visitTree(root->left, depth+1);
	visitTree(root->right, depth+1);
}
