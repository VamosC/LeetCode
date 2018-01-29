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
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) 
{
	struct TreeNode** queue;
	struct TreeNode* T;
	int front, rear;
	int level, QueueSize, num;
	int i, j;
	int** result;

	*returnSize = 0;
	if(root == NULL)
		return NULL;
	result = (int**)malloc(sizeof(int*));
    queue = (struct TreeNode**)malloc(sizeof(struct TreeNode));
    *columnSizes = (int*)malloc(sizeof(int));
	front = 0;
	rear = -1;
	level = 0;
    j = 1;
	queue[++rear] = root;
	QueueSize = rear - front + 1;
	while(QueueSize > 0)
	{
        *columnSizes = (int*)realloc((*columnSizes),(level+1)*sizeof(int));
		(*columnSizes)[level] = QueueSize;
        result = (int**)realloc(result, (level+1)*sizeof(int*));
        result[level] = (int*)malloc(sizeof(int));
		num = 0;
		while(QueueSize > 0)
		{
			T = queue[front++];
            result[level] = (int*)realloc(result[level], (num+1)*sizeof(int));
			result[level][num] = T->val;
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
			num++;
			QueueSize--;
		}
		level++;
		QueueSize = rear - front + 1;
	}
	*returnSize = level;
	return result;
}