/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX 10000
void findSolution(int left, int n, int curNum, int k, int** res, int** columnSizes, int* returnSize, int* S, int* buf);
int** combine(int n, int k, int** columnSizes, int* returnSize)
{
	int i;
	int *S;
	int *buf;
	int** res;
	*returnSize = 0;
	res = (int**)malloc(MAX*sizeof(int*));
	(*columnSizes) = (int*)malloc(MAX*sizeof(int));
	S = (int*)malloc(n*sizeof(int));
	buf = (int*)malloc(k*sizeof(int));
	for(i = 0;i < n;i++)
		S[i] = i + 1;
	for(i = 0;i <= n - k;i++)
		findSolution(i, n, 0, k, res, columnSizes, returnSize, S, buf);
	return res;
}

void findSolution(int left, int n, int curNum, int k, int** res, int** columnSizes, int* returnSize, int* S, int* buf)
{
	int i;
	if(curNum == k - 1)
	{
        buf[curNum] = S[left];
		(*returnSize)++;
		res[(*returnSize) - 1] = (int*)malloc(k*sizeof(int));
		(*columnSizes)[(*returnSize) - 1] = k;
		for(i = 0;i < k;i++)
			res[(*returnSize) - 1][i] = buf[i];
	}
	else
	{
		buf[curNum] = S[left];
		for(i = left + 1;i < n;i++)
		{
			findSolution(i, n, curNum + 1, k, res, columnSizes, returnSize, S, buf);
		}
	}
}