int jump(int* nums, int numsSize)
{
	int m, n;
	int index;
	int max;
	int times;
	times = 0;
	m = 0;
	max = 0;
	while(1)
	{
		n = m + 1;
		while(n < numsSize && m + nums[m] >= n)
		{
			if(max < nums[n] + n)
			{
				max = nums[n] + n;
				index = n;
			}
			n++;
		}
		if(nums[m] + m >= numsSize-1)
		{
			if(numsSize != 1)
			{
				times++;
			}
			break;
		}
		else
		{
			times++;
			m = index;
		}
	}
	return times;
}