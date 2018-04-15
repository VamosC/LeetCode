/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct position* point;
typedef struct solutionNode* Solution;
struct position
{
    int x;
    int y;
    point next;
};
struct solutionNode
{
    char***s;
};
void findSolution(Solution* s, int n, int curNum, point list, int* returnSize);
void createSolution(Solution* s, point list, int* returnSize, int n);

char*** solveNQueens(int n, int* returnSize) {
    point list;
    Solution s;
    int i, j;
    *returnSize = 0;
    list = (point)malloc(sizeof(struct position));
    list->next = NULL;
    s = (Solution)malloc(sizeof(struct solutionNode));
    s->s = (char***)malloc(sizeof(char**));
    findSolution(&s, n, 0, list, returnSize);
    return s->s;
}


void findSolution(Solution* s, int n, int curNum, point list, int* returnSize)
{
    int i;
    int flag;
    point p, newNode;
    if(curNum < n)
    {
        for(i = 0;i < n;i++)
        {
            p = list->next;
            flag = 1;
            while(p)
            {
                if(p->y == i)
                {
                    flag = 0;
                    break;
                }
                p = p->next;
            }

            if(flag)
            {
                p = list->next;
                while(p)
                {
                    if((p->x - curNum) == (p->y - i) || (p->x - curNum) == (i - p->y))
                    {
                        flag = 0;
                        break;
                    }
                    p = p->next;
                }
            }
            
            if(flag)
            {
                newNode = (point)malloc(sizeof(struct position));
                newNode->x = curNum;
                newNode->y = i;
                newNode->next = NULL;
                p = list;
                while(p->next)
                {
                    p = p->next;
                }
                p->next = newNode;
                findSolution(s, n, curNum+1, list, returnSize);
                free(newNode);
                p->next = NULL;
            }
        }
    }
    else
    {
        createSolution(s, list, returnSize, n);
    }
}

void createSolution(Solution* s, point list, int* returnSize, int n)
{
    int i, j;
    point p;
    *returnSize = *returnSize + 1;
    (*s)->s = (char***)realloc((*s)->s, (*returnSize)*sizeof(char**));
    ((*s)->s)[(*returnSize) - 1] = (char**)malloc(n*sizeof(char*));
    for(i = 0;i < n;i++)
    {
        ((*s)->s)[(*returnSize) - 1][i] = (char*)malloc((n+1)*sizeof(char));
        for(j = 0;j < n;j++)
        {
            ((*s)->s)[(*returnSize) - 1][i][j] = '.';
        }
        ((*s)->s)[(*returnSize) - 1][i][j] = '\0';
    }

    p = list->next;
    while(p)
    {
        ((*s)->s)[(*returnSize) - 1][p->x][p->y] = 'Q';
        p = p->next;
    }
}
