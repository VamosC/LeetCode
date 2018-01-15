/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int judgeHeight(struct TreeNode* root);
int max(int a, int b);
bool isBalanced(struct TreeNode* root) 
{
	if(root == NULL)
		return 1;

	if(root->left == NULL)
		if(root->right == NULL)
			return 1;
		else
			if(root->right->right || root->right->left)
				return 0;
			else
				return 1;

	if(root->right == NULL)
		if(root->left == NULL)
			return 1;
		else
			if(root->left->left || root->left->right)
				return 0;
			else
				return 1;

	if(isBalanced(root->left)&&isBalanced(root->right))
		if(judgeHeight(root->left) == judgeHeight(root->right) ||
			judgeHeight(root->left) == judgeHeight(root->right) + 1 ||
			judgeHeight(root->right) == judgeHeight(root->left) + 1)
			return 1;
		else
			return 0;
	else
		return 0;
}

int judgeHeight(struct TreeNode* root)
{
	int height;
	if(root == NULL)
		return 0;

	height = max(judgeHeight(root->left),judgeHeight(root->right));
	return height + 1;

}

int max(int a, int b)
{
	return a > b ? a : b;
}

