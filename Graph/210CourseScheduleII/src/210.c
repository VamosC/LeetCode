/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct adjList
{
	int val;
	struct adjList* next;
};
int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int *prerequisitesColSizes, int* returnSize)
{
	int i;
	int indegree[numCourses];
	int queue[numCourses];
	int front, rear;
	int count;
	int vertex;
	struct adjList* course[numCourses];
	struct adjList* p;
	int* result;

	for(i = 0;i < numCourses;i++)
	{
		course[i] = NULL;
		indegree[i] = 0;
	}

	result = (int*)malloc(numCourses * sizeof(int));
	for(i = 0;i < prerequisitesRowSize;i++)
	{
		vertex = prerequisites[i][1];
		if(course[vertex] == NULL)
		{
			course[vertex] = (struct adjList*)malloc(sizeof(struct adjList));
			course[vertex]->val = prerequisites[i][0];
			course[vertex]->next = NULL;
		}
		else
		{
			p = course[vertex];
			while(p->next)
				p = p->next;
			p->next = (struct adjList*)malloc(sizeof(struct adjList));
			p->next->val = prerequisites[i][0];
			p->next->next = NULL;
		}
		indegree[prerequisites[i][0]]++;
	}
    
    front = 0;
	rear = -1;
	count = 0;
	for(i = 0;i < numCourses;i++)
	{
		if(indegree[i] == 0)
			queue[++rear] = i;
	}

	while(rear - front != -1)
	{
		vertex = queue[front++];
		result[count++] = vertex;
		p = course[vertex];
		while(p)
		{
			indegree[p->val]--;
			if(indegree[p->val] == 0)
				queue[++rear] = p->val;
			p = p->next;
		}
	}
	if(count < numCourses)
	{
		*returnSize = 0;
		return NULL;
	}
	*returnSize = count;
	return result;
}