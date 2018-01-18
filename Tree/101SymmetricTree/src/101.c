/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool judegeSymmetric(struct TreeNode* root1, struct TreeNode* root2);

bool isSymmetric(struct TreeNode* root)
{
	if(root == NULL)
		return 0;
	else
		if(judegeSymmetric(root->left, root->right))
			return 1;
		else
			return 0;
}

bool judegeSymmetric(struct TreeNode* root1, struct TreeNode* root2)
{
	if(root1 == NULL && root2 == NULL)
		return 1;
	if(root1 && root2)
		if(root1->val == root2->val)
			if(judegeSymmetric(root1->left, root2->right) && judegeSymmetric(root1->right, root2->left))
				return 1;

	return 0;

}