int lengthOfLIS(int* nums, int numsSize) 
{
	int i;
	int j;
    if(numsSize == 0)
        return 0;
	int d[numsSize];
	int length;
    int max;
	max = 0;
	d[0] = 1;
	for(i = 1;i < numsSize;i++)
	{
		d[i] = 1;
		for(j = i-1;j >=0;j--)
		{
			if(nums[i] > nums[j])
			{
				if(d[j]+1 > d[i])
					d[i] = d[j]+1;
			}
		}
	}
	for(i = 0;i < numsSize;i++)
	{
		if(d[i] > max)
			max = d[i];
	}
	return max;
}