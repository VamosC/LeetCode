/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef int Position;
struct TreeNode* formTree(int* nums, int l, int r);
Position findMax(int* nums, int l, int r);
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
{
	return formTree(nums, 0, numsSize - 1);
}
struct TreeNode* formTree(int* nums, int l, int r)
{
	int index;
	struct TreeNode* T;
	T = NULL;
	if(l <= r)
	{
		index = findMax(nums, l, r);
		T = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		T->val = nums[index];
		T->left = formTree(nums, l, index - 1);
		T->right = formTree(nums, index + 1, r);
	}
	return T;
}

Position findMax(int* nums, int l, int r)
{
	Position index;
	int max, i;

	max = nums[l];
    index = l;
	for(i = l+1;i <= r;i++)
	{
		if(max < nums[i])
		{
			index = i;
			max = nums[i];
		}
	}
	return index;
}