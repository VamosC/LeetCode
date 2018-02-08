/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum(struct TreeNode* root);
int findTilt(struct TreeNode* root)
{
	int leftTilt, rightTilt;
	int thisTilt;
	if(root == NULL)
	{
		return 0;
	}
	leftTilt = findTilt(root->left);
	rightTilt = findTilt(root->right);
	thisTilt = 0;
	thisTilt = abs(sum(root->left) - sum(root->right));
	return leftTilt + thisTilt + rightTilt;
}

int sum(struct TreeNode* root)
{
	if(root == NULL)
	{
		return 0;
	}
	return root->val + sum(root->left) + sum(root->right);
} 