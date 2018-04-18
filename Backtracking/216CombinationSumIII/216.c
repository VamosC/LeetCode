/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX 100
#define NUM 9
void findSolution(int k, int curNum, int left, int n, int** columnSizes, int *returnSize, int **res, int *S, int *buf);
int** combinationSum3(int k, int n, int** columnSizes, int* returnSize) 
{
	int i;
	int* S;
	int* buf;
	int** res;
	*returnSize = 0;
	res = (int**)malloc(MAX*sizeof(int*));
	(*columnSizes) = (int*)malloc(MAX*sizeof(int));
	S = (int*)malloc(NUM*sizeof(int));
	buf = (int*)malloc(k*sizeof(int));
	for(i = 0;i < NUM;i++)
		S[i] = i + 1;
	findSolution(k, 0, 0, n, columnSizes, returnSize, res, S, buf);
	return res;
}
void findSolution(int k, int curNum, int left, int n, int** columnSizes, int *returnSize, int **res, int *S, int *buf)
{
	int i;
	if(curNum > k)
		return;
	if(curNum == k && n == 0)
	{
		(*returnSize)++;
		(*columnSizes)[(*returnSize) - 1] = k;
		res[(*returnSize) - 1] = (int*)malloc(k*sizeof(int));
		for(i = 0;i < k;i++)
			res[(*returnSize) - 1][i] = buf[i];
	}
	else
	{
		for(i = left;i < NUM;i++)
		{
			if(n - S[i] >= 0)
			{
				buf[curNum] = S[i];
				findSolution(k, curNum + 1, i + 1, n - S[i], columnSizes, returnSize, res, S, buf);
			}
		}
	}
}