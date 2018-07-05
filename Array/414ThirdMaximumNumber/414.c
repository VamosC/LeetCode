int thirdMax(int* nums, int numsSize)
{
	int k;
	int pre;
	int max;
	int i;

	for(i = (numsSize-1)/2;i >= 0;i--)
	{
		perDown(nums, i, numsSize);
	}
	k = 1;
	pre = nums[0];
	max = nums[0];
	while(k < 3 && numsSize > 0)
	{
		if(nums[0] != pre)
		{
			pre = nums[0];
			k++;
		}
		nums[0] = nums[numsSize-1];
		perDown(nums, 0, numsSize-1);
		numsSize--;
	}

	return k == 3 ? pre : max;
}

void perDown(int* heap, int p, int numsSize)
{
	int i;
	int child;
	int tmp;
	tmp = heap[p];
	for(i=p;2*i+1 < numsSize;i=child)
	{
		child = 2*i+1;
		if(child+1 < numsSize && heap[child] <= heap[child+1])
			child++;
		if(heap[child] > tmp)
			heap[i] = heap[child];
		else
			break;
	}
	heap[i] = tmp;
}