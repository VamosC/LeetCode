/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int m;
struct TreeNode* insert(struct TreeNode* root, int* inorder, int l, int r, int* postorder);
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
	struct TreeNode* root;
	m = postorderSize - 1;
	if(inorderSize == 0)
		return NULL;
	root = insert(root, inorder, 0, inorderSize - 1, postorder);
	return root;
}

struct TreeNode* insert(struct TreeNode* root, int* inorder, int l, int r, int* postorder)
{
	int i;
	if(l > r)
		return NULL;

	root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = postorder[m--];
	root->left = root->right = NULL;

	for(i = l;i <= r;i++)
		if(inorder[i] == root->val)
			break;

	root->right = insert(root->right, inorder, i + 1, r, postorder);
	root->left = insert(root->left, inorder, l, i - 1, postorder);

	return root;
}