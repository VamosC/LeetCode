/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX 10000
void findSolution(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize, int* buf, int curNum, int** res);
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
	int** res;
	int* buf;
	*returnSize = 0;
	(*columnSizes) = (int*)malloc(MAX*sizeof(int));
	res = (int**)malloc(MAX*sizeof(int*));
	buf = (int*)malloc(MAX*sizeof(int));
	findSolution(candidates, candidatesSize, target, columnSizes, returnSize, buf, 0, res);
	return res;
}

void findSolution(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize, int* buf, int curNum, int** res)
{
	int i;
	if(target == 0)
	{
		(*returnSize)++;
		res[(*returnSize) - 1] = (int*)malloc(curNum * sizeof(int));
		(*columnSizes)[(*returnSize) - 1] = curNum;
		for(i = 0;i < curNum;i++)
			res[(*returnSize) - 1][i] = buf[i];
	}
	else
	{
		for(i = 0;i < candidatesSize;i++)
		{
			if(target - candidates[i] >= 0)
			{
				if(curNum > 0 && candidates[i] < buf[curNum - 1]);
				else
				{
					buf[curNum] = candidates[i];
					findSolution(candidates, candidatesSize, target - candidates[i], columnSizes, returnSize, buf, curNum + 1, res);
				}
			}
		}
	}
}