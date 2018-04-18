/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 1000
#define NEGATIVE -100000
void findSolution(int* nums, int numsSize, int curNum, int** res, int* returnSize, int* buf);
int** permuteUnique(int* nums, int numsSize, int* returnSize)
{
	int** res;
	int* buf;
	res = (int**)malloc(MAX*sizeof(int*));
	buf = (int*)malloc(numsSize*sizeof(int));
	*returnSize = 0;
	findSolution(nums, numsSize, 0, res, returnSize, buf);
	return res;
}

void findSolution(int* nums, int numsSize, int curNum, int** res, int* returnSize, int* buf)
{
	int flag;
	int i, j;
	flag = 1;
	if(curNum == numsSize)
	{
		for(i = 0;i < (*returnSize);i++)
		{
			for(j = 0;j < curNum;j++)
			{
				if(buf[j] != res[i][j])
					break;
			}
			if(j >= curNum)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			(*returnSize)++;
			res[(*returnSize) - 1] = (int*)malloc(curNum*sizeof(int));
			for(i = 0;i < curNum;i++)
				res[(*returnSize) - 1][i] = buf[i];
		}
	}
	else
	{
		for(i = 0;i < numsSize;i++)
		{
			if(nums[i] != NEGATIVE)
			{
				buf[curNum] = nums[i];
				nums[i] = NEGATIVE;
				findSolution(nums, numsSize, curNum + 1, res, returnSize, buf);
				nums[i] = buf[curNum];
			}
		}
	}
}