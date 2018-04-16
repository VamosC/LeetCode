/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define INFINITE 1000000
typedef struct solution* Solutions;
struct solution
{
	int** s;
};
void findSolutions(int* nums, int numsSize, int* returnSize, Solutions res, int curNum, int* buf);
int** permute(int* nums, int numsSize, int* returnSize)
{
	Solutions res;
	int* buf;
	*returnSize = 0;
	res = (Solutions)malloc(sizeof(struct solution));
	res->s = (int**)malloc(sizeof(int*));
	buf = (int*)malloc(numsSize*sizeof(int));
	findSolutions(nums, numsSize, returnSize, res, 0, buf);
	return res->s;
}

void findSolutions(int* nums, int numsSize, int* returnSize, Solutions res, int curNum, int* buf)
{
	int i;
	if(curNum < numsSize)
	{
		for(i = 0;i < numsSize;i++)
		{
			if(nums[i] != INFINITE)
			{
				buf[curNum] = nums[i];
				nums[i] = INFINITE;
				findSolutions(nums, numsSize, returnSize, res, curNum+1, buf);
				nums[i] = buf[curNum];
			}
		}
	}
	else
	{
		(*returnSize)++;
		res->s = (int**)realloc(res->s, (*returnSize)*sizeof(int*));
		res->s[(*returnSize) - 1] = (int*)malloc(numsSize*sizeof(int));
		for(i = 0;i < numsSize;i++)
		{
			res->s[(*returnSize) - 1][i] = buf[i];
		}
	}
}