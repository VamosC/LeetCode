/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLength;
int max(int a, int b);
int findLongest(struct TreeNode* root);
int diameterOfBinaryTree(struct TreeNode* root)
{
    maxLength = 0;
	if(root == NULL)
		return 0;
	findLongest(root);
	return maxLength;
}

int findLongest(struct TreeNode* root)
{
	int MaxLeft, MaxRight;
	int LongestPath;
	if(root == NULL)
		return -1;
	if(root->left == NULL && root->right == NULL)
		return 0;

	MaxLeft = findLongest(root->left);
	MaxRight = findLongest(root->right);
	LongestPath = MaxLeft + MaxRight + 2;
	if(maxLength < LongestPath)
		maxLength = LongestPath;

	return max(MaxLeft, MaxRight) + 1;
}

int max(int a, int b)
{
	return a > b ? a : b;
}