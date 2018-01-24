/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int m;
struct TreeNode* insert(struct TreeNode* root, int* preorder, int* inorder, int l, int r);
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
	struct TreeeNode* root;
	m = 0;
	if(preorderSize == 0)
		return NULL;
	root = insert(root, preorder, inorder, 0, inorderSize-1);
	return root;
}

struct TreeNode* insert(struct TreeNode* root, int* preorder, int* inorder, int l, int r)
{
	int i;
	if(l > r)
		return NULL;

	root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = preorder[m++];
	root->left = root->right = NULL;
	for(i = l; i <= r;i++)
	{
		if(inorder[i] == root->val)
			break;
	}
	root->left = insert(root->left, preorder, inorder, l, i - 1);
	root->right = insert(root->right, preorder, inorder, i + 1, r);
	return root;
}