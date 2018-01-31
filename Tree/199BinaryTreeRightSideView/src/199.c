/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize)
{
	int* result;
	struct TreeNode** queue;
	int front, rear;
	int QueueSize, i, j;
	struct TreeNode* T;
	*returnSize = 0;
	if(root == NULL)
		return NULL;
	front = 0;
	rear = -1;
	i = 1;
	j = 0;
	queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
	result = (int*)malloc(sizeof(int));
	queue[++rear] = root;
	QueueSize = rear - front + 1;

	while(QueueSize > 0)
	{
		while(QueueSize > 0)
		{
			T = queue[front++];
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
			QueueSize--;
			if(QueueSize == 0)
			{
				result = (int*)realloc(result, (++j)*sizeof(int));
				result[j-1] = T->val;
			}

		}
	QueueSize = rear - front + 1;
	}
	*returnSize = j;
	return result;
}