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
int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
	struct TreeNode** queue;
	int front, rear;
	int QueueSize;
	struct TreeNode** stack;
	int top;
	int level, i;
    int j, k;
	int** result;
	struct TreeNode* T;
	*returnSize = 0;

	if(root == NULL)
		return NULL;

	front = 0;
	rear = -1;
	top = -1;
	level = 0;
    j = 1;
    k = 0;
	*columnSizes = (int*)malloc(sizeof(int));
	result = (int**)malloc(sizeof(int*));
    queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
	queue[++rear] = root;
	QueueSize= rear - front + 1;
	while(QueueSize > 0)
	{
		i = 0;
        
        result = (int**)realloc(result, (level+1)*sizeof(int*));
        result[level] = (int*)malloc(sizeof(int));
		if(level % 2 == 0)
		{
			while(QueueSize > 0)
			{
				T = queue[front++];
                result[level] = (int*)realloc(result[level], (i+1)*sizeof(int));
				result[level][i++] = T->val;
				if(T->left)
                {
                    queue = (struct TreeNode**)realloc(queue, (++j)*sizeof(struct TreeNode*));
                    queue[++rear] = T->left;
                }
				if(T->right)
                {
                    queue = (struct TreeNode**)realloc(queue, (++j)*sizeof(struct TreeNode*));
                    queue[++rear] = T->right;
                }
				QueueSize--;
			}
		}
		else
		{
			while(QueueSize > 0)
			{
				T = queue[front++];
                stack = (struct TreeNode**)realloc(stack, (++k)*sizeof(struct TreeNode*));
				stack[++top] = T;
				if(T->left)
                {
                    queue = (struct TreeNode**)realloc(queue, (++j)*sizeof(struct TreeNode*));
                    queue[++rear] = T->left;
                }
				if(T->right)
                {
                    queue = (struct TreeNode**)realloc(queue, (++j)*sizeof(struct TreeNode*));
                    queue[++rear] = T->right;
                }
				QueueSize--;
			}
			while(top != -1)
			{
				T = stack[top--];
                result[level] = (int*)realloc(result[level], (i+1)*sizeof(int));
				result[level][i++] = T->val;
			}
		}
        (*columnSizes) = (int*)realloc((*columnSizes), (level+1)*sizeof(int));
		(*columnSizes)[level++] = i;
		QueueSize = rear - front + 1;
	}

	*returnSize = level;
	return result;
}