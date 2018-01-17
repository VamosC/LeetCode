/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int visit(struct TreeNode* root, int sum, int length);
int pathSum(struct TreeNode* root, int sum)
{
	if(root == NULL)
		return 0;

	return visit(root, sum, 0) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int visit(struct TreeNode* root, int sum, int length)
{
	int pathNum;
	pathNum = 0;
	if(root == NULL)
		return 0;
	if(length + root->val == sum)
		pathNum++;
	pathNum += visit(root->left, sum, length + root->val) + visit(root->right, sum, length + root->val);

	return pathNum;
}
