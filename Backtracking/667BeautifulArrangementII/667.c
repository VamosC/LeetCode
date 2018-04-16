/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct dupNode* duplicate;
struct dupNode
{
	int val;
	int times;
};
void findSolution(int n, int k,int* solution, duplicate* difference, int* S, int curNum, int* dupNum, int* found);
int checkSolution(int* solution, int curNum, duplicate* difference, int k, int* dupNum, int n);
void undoSolution(int* solution, int curNum, duplicate* difference, int k, int* dupNum);
int* constructArray(int n, int k, int* returnSize) 
{
	int* solution;
	duplicate* difference;
	int* S;
	int dupNum = 0;
	int i;
	int found = 0;
	solution = (int*)malloc(n*sizeof(int));
	difference = (duplicate*)malloc(k*sizeof(duplicate));
	S = (int*)malloc(n*sizeof(int));
	for(i = 0;i < k;i++)
	{
		difference[i] = (duplicate)malloc(sizeof(struct dupNode));
		difference[i]->times = 0;
	}
	for(i = 0;i < n;i++)
	{
		S[i] = i+1;
	}
	*returnSize = 0;
	findSolution(n, k, solution, difference, S, 0, &dupNum, &found);
	if(found)
		*returnSize = n;
	return solution;
}

void findSolution(int n, int k,int* solution, duplicate* difference, int* S, int curNum, int* dupNum, int* found)
{
	int i;
	if(curNum < n)
	{
		for(i = 0;i < n;i++)
		{
			if(S[i] != -1)
			{
				solution[curNum] = S[i];
				S[i] = -1;
				if(checkSolution(solution, curNum, difference, k, dupNum, n))
				{
					findSolution(n, k, solution, difference, S, curNum + 1, dupNum, found);
					if(*found)
					{
						return;
					}
					undoSolution(solution, curNum, difference, k, dupNum);
				}
				S[i] = i+1;
			}
		}
	}
	else
	{
		if((*dupNum) == k)
			*found = 1;
	}
}
int checkSolution(int* solution, int curNum, duplicate* difference, int k, int* dupNum, int n)
{
	int j;
	int flag;
	int dif;
    if(curNum == 0)
        return 1;
    if(n - curNum + *dupNum < k)
    	return 0;
	dif = abs(solution[curNum] - solution[curNum - 1]);
	flag = 1;
	for(j = 0;j < k;j++)
	{
		if(difference[j]->times != 0)
		{
			if(dif == difference[j]->val)
			{
			    difference[j]->times++;
				flag = 0;
				break;
			}
		}
		else
			break;
	}

	if(flag && j < k)
	{
		difference[j]->times++;
		difference[j]->val = dif;
		(*dupNum)++;
		flag = 0;
	}
	return !flag;
}

void undoSolution(int* solution, int curNum, duplicate* difference, int k, int* dupNum)
{
	int dif;
	int i;
	dif = abs(solution[curNum] - solution[curNum - 1]);
    if(curNum == 0)
        return;
	for(i = 0;i < k;i++)
	{
		if(difference[i]->val == dif)
		{
			if(difference[i]->times == 1)
				(*dupNum)--;
			difference[i]->times--;
			break;
		}
	}
}