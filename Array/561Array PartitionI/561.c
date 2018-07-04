int arrayPairSum(int* nums, int numsSize) 
{
	int sum;
	int i;
	quickSort(nums, 0, numsSize-1);
	sum = 0;
	for(i = 0;i < numsSize;i+=2)
	{
		sum+=nums[i];
	}
	return sum;
}

void quickSort(int* A, int left, int right)
{
	int i, j;
	if(left < right)
	{
		Middle(A, left, right);
		i = left;
		j = right - 1;
		while(i < j)
		{
			while(A[++i] < A[right-1]);
			while(A[--j] > A[right-1]);
			if(i < j)
				Swap(&A[i],&A[j]);
			else
				break;
		}
		Swap(&A[i],&A[right-1]);
		quickSort(A, left, i-1);
		quickSort(A, i+1, right);
	}

}

void Middle(int*A, int left, int right)
{
	int center;
	center = (left + right)/2;
	if(A[left] > A[center])
		Swap(&A[left], &A[center]);
	if(A[left] > A[right])
		Swap(&A[left], &A[right]);
	if(A[center] > A[right])
		Swap(&A[center], &A[right]);

	Swap(&A[center], &A[right-1]);
}

void Swap(int* p, int* q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
