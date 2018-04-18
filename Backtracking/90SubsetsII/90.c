/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX 10000
void quickSort(int* A, int l, int r);
int median(int* A, int l, int r, int m);
void swapPosition(int* x, int* y);
void findSolution(int* nums, int left, int numsSize, int curNum, int** res, int** columnSizes, int* returnSize, int* buf);
int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize)
{
	int** res;
	int* buf;
	*returnSize = 0;
	res = (int**)malloc(MAX*sizeof(int*));
	buf = (int*)malloc(MAX*sizeof(int));
	(*columnSizes) = (int*)malloc(MAX*sizeof(int));
	quickSort(nums, 0, numsSize - 1);
	findSolution(nums, 0, numsSize, 0, res, columnSizes, returnSize, buf);
	(*returnSize)++;
	res[(*returnSize) - 1] = (int*)malloc(sizeof(int));
	(*columnSizes)[(*returnSize) - 1] = 0;
	return res;
}

void findSolution(int* nums, int left, int numsSize, int curNum, int** res, int** columnSizes, int* returnSize, int* buf)
{
	int i, j, k;
	int flag;
	if(curNum > numsSize)
		return;
	if(curNum != 0 && curNum <= numsSize)
	{
		flag = 1;
		for(j = 0;j < (*returnSize);j++)
		{
			if((*columnSizes)[j] == curNum)
			{
				for(k = 0;k < (*columnSizes)[j];k++)
				{
					if(res[j][k] != buf[k])
						break;
				}
				if(k >= (*columnSizes)[j])
				{
					flag = 0;
					break;
				}
			}
		}
		if(flag)
		{
			(*returnSize)++;
			res[(*returnSize) - 1] = (int*)malloc((curNum)*sizeof(int));
			(*columnSizes)[(*returnSize) - 1] = curNum;
			for(i = 0;i < curNum;i++)
			{
				res[(*returnSize) - 1][i] = buf[i];
			}
		}
	}
	for(i = left;i < numsSize;i++)
	{
		buf[curNum] = nums[i];
		findSolution(nums, i + 1, numsSize, curNum + 1, res, columnSizes, returnSize, buf);
	}
}

void quickSort(int* A, int l, int r)
{
	int m;
	int pivot;
	int i, j;
	i = l;
	j = r - 1;
	if(l < r)
	{
		m = (l+r)/2;
		pivot = median(A, l, r, m);
		while(i < j)
		{
			while(A[++i] < pivot);
			while(A[--j] > pivot);
			if(i < j)
				swapPosition(&A[i], &A[j]);
			else
				break;
		}
		swapPosition(&A[i], &A[r - 1]);
		quickSort(A, l, i - 1);
		quickSort(A, i + 1, r);
	}
}

int median(int* A, int l, int r, int m)
{
	if(A[l] > A[m])
		swapPosition(&A[l], &A[m]);
	if(A[l] > A[r])
		swapPosition(&A[l], &A[r]);
	if(A[m] > A[r])
		swapPosition(&A[m], &A[r]);
	swapPosition(&A[m], &A[r - 1]);
	return A[r - 1];
}

void swapPosition(int* x, int* y)
{
	int Tmp;
	Tmp = *x;
	*x = *y;
	*y = Tmp;
}