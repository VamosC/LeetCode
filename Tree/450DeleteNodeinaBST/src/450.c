/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* FindMin(struct TreeNode* root);
struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
	if(root == NULL)
		return NULL;

	if(root->val > key)
		root->left = deleteNode(root->left, key);

	else if(root->val < key)
		root->right = deleteNode(root->right, key);

	else
	{
        if(root->left&&root->right)
        {
        	Tmp = FindMin(root->right);
        	root->val = Tmp->val;
        	root->right = deleteNode(root->right, root->val);
        }
        else
        {
        	if(root->left)
        		root = root->left;
        	else if(root->right)
        		root = root->right;
        	else
        		root = NULL;
	    }
	} 
	return root;
}

struct TreeNode* FindMin(struct TreeNode* root)
{
	struct TreeNode* T;
	T = root;
	if(T == NULL)
		return NULL;
	while(T->left)
		T = T->left;
	return T;
}