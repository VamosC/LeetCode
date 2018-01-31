/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root)
{
	struct TreeLinkNode** queue;
	int i;
	int front, rear;
	int QueueSize;
	struct TreeLinkNode* T;

	if(root == NULL)
		return NULL;

	front = 0;
	rear = -1;
	i = 1;
	queue = (struct TreeLinkNode**)malloc(sizeof(struct TreeLinkNode*));
	queue[++rear] = root;
	QueueSize = rear - front + 1;
	while(QueueSize > 0)
	{
		while(QueueSize > 0)
		{
			T = queue[front++];
			QueueSize--;
			if(QueueSize == 0)
				T->next = NULL;
			else
				T->next = queue[front];
			if(T->left)
			{
				queue = (struct TreeLinkNode**)realloc(queue, (++i)*sizeof(struct TreeLinkNode*));
				queue[++rear] = T->left;
			}
			if(T->right)
			{
				queue = (struct TreeLinkNode**)realloc(queue, (++i)*sizeof(struct TreeLinkNode*));
				queue[++rear] = T->right;
			}
		}
		QueueSize = rear - front + 1;
	}
	free(queue);
}