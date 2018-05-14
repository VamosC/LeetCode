bool canJump(int* nums, int numsSize) 
{
	int i;
	int n;
	int index;
	int max;
	int flag;
	flag = 1;
	max = 0;
	i = 0;
	while(1)
	{
		n = i + 1;
		index = i;
		while(n < numsSize && nums[i] + i >= n)
		{
			if(nums[n] + n > max)
			{
				index = n;
				max = nums[n] + n;
			}
			n++;
		}
		if(max >= numsSize-1)
		{
			break;
		}
		else if(index == i)
		{
			flag = 0;
			break;
		}
		else
		{
			i = index;
		}
	}
	return flag == 1 ? true : false;
}