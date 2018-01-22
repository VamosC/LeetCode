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
#define MAX 10000
int* largestValues(struct TreeNode* root, int* returnSize)
{
	int* result;
	struct TreeNode* queue[MAX];
	struct TreeNode* T;
	int front, rear;
	int queueSize;
	int i;
	int level;
	int flag;

	*returnSize = 0;
	if(root == NULL)
		return NULL;

	result = (int*)malloc(MAX*sizeof(int));
	front = 0;
	rear = -1;
	level = 0;
	flag = 0;
	queue[++rear] = root;
	queueSize = rear - front + 1;
	while(queueSize > 0)
	{
		while(queueSize > 0)
		{
			T = queue[front++];
			if(flag == 0)
			{
				result[level] = T->val;
				flag = 1;
			}
			else
			{
				if(T->val > result[level])
					result[level] = T->val;
			}
			if(T->left)
				queue[++rear] = T->left;
			if(T->right)
				queue[++rear] = T->right;
			queueSize--;
		}
		level++;
		flag = 0;
		queueSize = rear - front + 1;
	}
	*returnSize = level;
	return result;
}