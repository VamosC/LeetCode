/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MaxData 1000000
typedef struct TreeNode* position;
position findMin(struct TreeNode* root);
position findMax(struct TreeNode* root);
int absolute(int x);
int minCompare(int a, int b);

int getMinimumDifference(struct TreeNode* root) 
{
    int minLeft, minRight;
    struct TreeNode* T;

    minLeft = minRight = MaxData;

    if(root == NULL)
    	return MaxData;

    if(root->left)
        minLeft = minCompare(absolute(root->val -  findMax(root->left)->val), getMinimumDifference(root->left));

    if(root->right)
        minRight = minCompare(absolute(root->val - findMin(root->right)->val), getMinimumDifference(root->right));

    return minCompare(minLeft, minRight);
}

int absolute(int x)
{
	return x < 0 ? -x : x;
}

int minCompare(int a, int b)
{
	return a < b ? a : b;
}

position findMax(struct TreeNode* root)
{
	if(root == NULL)
		return NULL;
	if(root->right)
		return findMax(root->right);
	return root;
}

position findMin(struct TreeNode* root)
{
	if(root == NULL)
		return NULL;
	if(root->left)
		return findMin(root->left);
	return root;
}
