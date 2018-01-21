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
#define MAX 10000
#define SIZE 800
int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) 
{
	struct TreeNode* queue[MAX];
	struct TreeNode* T;
	int front, rear;
	int level, queueSize, num;
	int i;
	int** result;

	*returnSize = 0;
	if(root == NULL)
		return NULL;
	result = (int**)malloc(SIZE*sizeof(int*));
	for(i = 0;i < SIZE;i++)
	{
		result[i] = (int*)malloc(SIZE*sizeof(int));
	}
    *columnSizes = (int*)malloc(SIZE*sizeof(int));
	front = 0;
	rear = -1;
	level = 0;
	queue[++rear] = root;
	queueSize = rear - front + 1;
	while(queueSize > 0)
	{
		(*columnSizes)[level] = queueSize;
		num = 0;
		while(queueSize > 0)
		{
			T = queue[front++];
			result[level][num] = T->val;
			if(T->left)
				queue[++rear] = T->left;
			if(T->right)
				queue[++rear] = T->right;
			num++;
			queueSize--;
		}
		level++;
		queueSize = rear - front + 1;
	}
	*returnSize = level;
	return result;
}