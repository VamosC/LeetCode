/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef int ElementType;
typedef struct TreeNode* SearchTree;
SearchTree Insert(ElementType X, struct TreeNode* root);
SearchTree buildBalanceBST(int* nums, int l, int r, SearchTree root);

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) 
{
    SearchTree T;

    T = buildBalanceBST(nums, 0, numsSize - 1, T); 

    return T;
}

SearchTree buildBalanceBST(int* nums, int l, int r, SearchTree root)
{
	int median;
	if(l <= r)
	{
		median = (l + r)/2;
		root = Insert(nums[median], root);
		root = buildBalanceBST(nums, l, median - 1, root);
		root = buildBalanceBST(nums, median + 1, r,  root);
	}
	return root;
}

SearchTree Insert(ElementType X, struct TreeNode* root)
{
	if(root == NULL)
	{
		root = (SearchTree)malloc(sizeof(struct TreeNode));
		root->val = X;
		root->left = root->right = NULL;
	}

	else
	{
		if(X > root->val)
			root->right = Insert(X, root->right);
		else if(X < root->val)
			root->left = Insert(X, root->left);
	}

	return root;
}