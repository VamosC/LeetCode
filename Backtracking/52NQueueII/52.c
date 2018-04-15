typedef struct position* point;
struct position
{
    int x;
    int y;
    point next;
};

void findSolutionNum(int n, int* solutionNum, int curNum, point list);
int totalNQueens(int n) {
    int solutionNum;
    point list;

    list = (point)malloc(sizeof(struct position));
    list->next = NULL;
    solutionNum = 0;
    findSolutionNum(n, &solutionNum, 0, list);
    return solutionNum;
}

void findSolutionNum(int n, int* solutionNum, int curNum, point list)
{
    point p, newNode;
    int flag, i;
    if(curNum < n)
    {
        for(i = 0;i < n;i++)
        {
            flag = 1;
            p = list->next;
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
                    if((p->x - curNum) == (p->y - i) ||(p->x - curNum) == (i - p->y))
                    {
                        flag = 0;
                        break;
                    }
                    p = p->next;
                }
                if(flag)
                {
                    newNode = (point)malloc(sizeof(struct position));
                    newNode->x = curNum;
                    newNode->y = i;
                    newNode->next = NULL;
                    p = list;
                    while(p->next)
                        p = p->next;
                    p->next = newNode;
                    findSolutionNum(n, solutionNum, curNum+1, list);
                    free(newNode);
                    p->next = NULL;
                }
            }
        }
    }
    else
    {
        (*solutionNum)++;
    }
}