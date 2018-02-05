/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Max(int a, int b, int c);
int DFS(struct TreeNode* root, int val);
int longestUnivaluePath(struct TreeNode* root)
{
	int LeftSize, RightSize;
	int TotalSize;

	LeftSize = RightSize = TotalSize = 0;
	if(root == NULL)
	{
		return 0;
	}
	LeftSize = longestUnivaluePath(root->left);
	RightSize = longestUnivaluePath(root->right);
    TotalSize = DFS(root->left, root->val) + DFS(root->right, root->val);
	return Max(LeftSize, RightSize, TotalSize);
}

int Max(int a, int b, int c)
{
	return a > (b > c ? b : c) ? a : (b > c ? b : c);
}

int DFS(struct TreeNode* root, int val)
{
	if(root == NULL)
	{
		return 0;
	}
	if(root->val != val)
	{
		return 0;
	}

	return Max(DFS(root->left, val), DFS(root->right, val), -1) + 1;
}