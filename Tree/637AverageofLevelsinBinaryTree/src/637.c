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
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
	struct TreeNode* queue[MAX];
	struct TreeNode* T;
	int rear, front;
	int queueSize;
	int level;
	int i, num;
	double* sumAverage;

	*returnSize = 0;
	if(root == NULL)
		return NULL;
    
    sumAverage = (double*)malloc(MAX * sizeof(double));
	for(i = 0;i < MAX;i++)
		sumAverage[i] = 0;

	front = 0;
	rear = -1;
	level = 0;
	queue[++rear] = root;
	queueSize = rear - front + 1;
	while(queueSize > 0)
	{
		num = 0;
		while(queueSize > 0)
		{
			T = queue[front++];
			sumAverage[level] += T->val;
			num++;
			if(T->left)
				queue[++rear] = T->left;
			if(T->right)
				queue[++rear] = T->right;
			queueSize--;
		}
		sumAverage[level] = sumAverage[level] * 1.0/ num;
		level++;
		queueSize = rear - front + 1;
	}
	*returnSize = level;
	return sumAverage;
}