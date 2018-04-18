/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX 10000
void findSolution(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize, int* buf, int curNum, int** res, int left);
void quickSort(int* A, int left, int right);
void swapPosition(int* x, int* y);
int median(int* A, int left, int right, int middle);
int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
	int** res;
	int* buf;
	int i;
	*returnSize = 0;
	(*columnSizes) = (int*)malloc(MAX*sizeof(int));
	res = (int**)malloc(MAX*sizeof(int*));
	buf = (int*)malloc(MAX*sizeof(int));
	quickSort(candidates, 0, candidatesSize - 1);
	findSolution(candidates, candidatesSize, target, columnSizes, returnSize, buf, 0, res, i);
	return res;
}

void findSolution(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize, int* buf, int curNum, int** res, int left)
{
	int i, j;
	int flag = 1;
	if(curNum >= candidates)
		return;
	if(target == 0)
	{
		for(i = 0;i < (*returnSize);i++)
		{
			if((*columnSizes)[i] == curNum)
			{
				for(j = 0;j < curNum;j++)
					if(res[i][j] != buf[j])
						break;
                if(j >= curNum)
                    flag = 0;
			}
		}
		if(flag)
		{
			(*returnSize)++;
			res[(*returnSize) - 1] = (int*)malloc(curNum * sizeof(int));
			(*columnSizes)[(*returnSize) - 1] = curNum;
			for(i = 0;i < curNum;i++)
				res[(*returnSize) - 1][i] = buf[i];
		}
	}
	else
	{
		for(i = left;i < candidatesSize;i++)
		{
			if(target - candidates[i] >= 0)
			{			
				buf[curNum] = candidates[i];
				findSolution(candidates, candidatesSize, target - candidates[i], columnSizes, returnSize, buf, curNum + 1, res, i
                             + 1);
			}
		}
	}
}

void quickSort(int* A, int left, int right)
{
	int i, j;
	int middle;
	int pivot;
	middle = (left + right)/2;
	i = left;
	j = right -1;
	if(left < right)
	{
		pivot = median(A, left, right, middle);
		while(i < j)
		{
			while(A[++i] < pivot);
			while(A[--j] > pivot);
			if(i < j)
				swapPosition(&A[i], &A[j]);
			else
				break;
		}
		swapPosition(&A[i], &A[right - 1]);
		quickSort(A, left, i - 1);
		quickSort(A, i + 1, right);
	}
}

int median(int* A, int left, int right, int middle)
{
	int Tmp;
	if(A[left] > A[middle])
		swapPosition(&A[left], &A[middle]);
	if(A[left] > A[right])
		swapPosition(&A[left], &A[right]);
	if(A[middle] > A[right])
		swapPosition(&A[middle], &A[right]);
	swapPosition(&A[middle], &A[right - 1]);
	return A[right - 1];
}

void swapPosition(int* x, int* y)
{
    int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}