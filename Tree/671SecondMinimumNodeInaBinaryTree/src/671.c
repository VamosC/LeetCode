/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int findSecondMinimumValue(struct TreeNode* root)
{
	int MinimumVal, SecondVal;
	int i;
	struct TreeNode** queue;
	struct TreeNode* T;
	int front, rear;
	if(root == NULL)
		return -1;

	MinimumVal = root->val;
	SecondVal = -1;
	i = 0;
	front = 0;
	rear = -1;
	queue = (struct TreeNode**)malloc((++i)*sizeof(struct TreeNode*));
	queue[++rear] = root;
	while(rear - front != -1)
	{
		T =queue[front++];
		if(T->val != MinimumVal)
		{
			if(SecondVal == -1)
			{
				SecondVal = T->val;
			}
			else
			{
				if(T->val < SecondVal)
				{
					SecondVal = T->val;
				}
			}
		}
		else
		{
			if(T->left)
			{
				queue = (struct TreeNode**)realloc(queue, (++i)*sizeof(struct TreeNode*));
				queue[++rear] = T->left;
			}
			if(T->right)
			{
				queue = (struct TreeNode**)realloc(queue, (++i)*sizeof(struct TreeNode*));
				queue[++rear] = T->right;
			}
		}
	}
	return SecondVal;
}