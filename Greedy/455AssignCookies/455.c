void quickSort(int* A, int left, int right);
void median(int* A, int left, int right);
void swap(int* p, int* q);
int findContentChildren(int* g, int gSize, int* s, int sSize)
{
	int i, j;
	int num;
	num = 0;
	quickSort(g, 0, gSize-1);
	quickSort(s, 0, sSize-1);
	i = j = 0;
	while(i < gSize && j < sSize)
	{
		if(s[j] >= g[i])
		{
			num++;
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}
	return num;
}

void quickSort(int* A, int left, int right)
{
	int i, j;
	if(left < right)
	{
		i = left;
		j = right - 1;
		median(A, left, right);
		while(i < j)
		{
			while(A[++i] < A[right - 1]);
			while(A[--j] > A[right - 1]);
			if(i < j)
			{
				swap(&A[i], &A[j]);
			}
			else
			{
				break;
			}
		}
		swap(&A[i],&A[right - 1]);
		quickSort(A, left, i-1);
		quickSort(A, i+1, right);
	}
}

void median(int* A, int left, int right)
{
	int center;
	center = (left + right)/2;
	if(A[left] > A[center])
	{
		swap(&A[left], &A[center]);
	}
	if(A[left] > A[right])
	{
		swap(&A[left], &A[right]);
	}
	if(A[center] > A[right])
	{
		swap(&A[center], &A[right]);
	}
	swap(&A[center], &A[right-1]);
}

void swap(int* p, int* q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}