struct AdjList
{
    int val;
    struct AdjList* next;
};

bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize) {
    struct AdjList* course[numCourses];
    struct AdjList* p;
    int queue[numCourses];
    int vertex;
    int degree[numCourses];
    int i;
    int front, rear;
    int count;
    
    front = 0;
    rear = -1;
    count = 0;
    
    for(i = 0;i < numCourses;i++)
    {
        course[i] = NULL;
        degree[i] = 0;
    }
    for(i = 0;i < prerequisitesRowSize;i++)
    {
        vertex = prerequisites[i][0];
        if(course[vertex] == NULL)
        {
            course[vertex] = (struct AdjList*)malloc(sizeof(struct AdjList));
            course[vertex]->val = prerequisites[i][1];
            course[vertex]->next = NULL;
        }
        else
        {
            p = course[vertex];
            while(p->next)
                p = p->next;
            p->next = (struct AdjList*)malloc(sizeof(struct AdjList));
            p->next->val = prerequisites[i][1];
            p->next->next = NULL;
        }
        degree[prerequisites[i][1]]++;
    }
    
    for(i = 0;i < numCourses;i++)
        if(degree[i] == 0)
            queue[++rear] = i;
    
    while(rear - front != -1)
    {
        vertex = queue[front++];
        count++;
        p = course[vertex];
        while(p)
        {
            degree[p->val]--;
            if(degree[p->val] == 0)
                queue[++rear] = p->val;
            p = p->next;
        }
    }
    
    if(count < numCourses)
        return 0;
    return 1;
}