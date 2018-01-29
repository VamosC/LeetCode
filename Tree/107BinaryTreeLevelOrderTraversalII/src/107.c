/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize)
{
	int** result;
	int i, j;
	int* stack;
	int top;
	struct TreeNode** queue;
	int front, rear;
	int QueueSize;
	struct TreeNode* T;
	int* num;
	int level;

	*returnSize = 0;
	if(root == NULL)
		return NULL;

	i = 0;
	j = 1;
	level = 0;
	top = -1;
	front = 0;
	rear = -1;
	num = (int*)malloc(sizeof(int));
	stack = (int*)malloc(sizeof(int));
    queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
	queue[++rear] = root;
	QueueSize = rear - front + 1;

	while(QueueSize > 0)
	{
		num = (int*)realloc(num, (level+1)*sizeof(int));
		num[level] = QueueSize;
		while(QueueSize > 0)
		{
			T = queue[front++];
			stack = (int*)realloc(stack, (++i)*sizeof(int));
			stack[++top] = T->val;

			if(T->right)
			{
				queue = (struct TreeNode**)realloc(queue, (++j)*sizeof(struct TreeeNode*));
				queue[++rear] = T->right;
			}
			if(T->left)
			{
				queue = (struct TreeNode**)realloc(queue, (++j)*sizeof(struct TreeNode*));
				queue[++rear] = T->left;
			}
			QueueSize--;
		}
		level++;
		QueueSize = rear - front + 1;
	}
	*returnSize = level;
	*columnSizes = (int*)malloc(level*sizeof(int));
	result = (int**)malloc(level*sizeof(int*));
	for(i = 0;i < level;i++)
	{
		(*columnSizes)[i] = num[level - 1 - i];
		result[i] = (int*)malloc(num[level - 1 - i]*sizeof(int));
		for(j = 0;j < num[level - 1 -i];j++)
			result[i][j] = stack[top--];
	}

	return result;
}