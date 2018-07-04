bool checkPossibility(int* nums, int numsSize)
{
	int i;
	int k;
	int index;
	k = 0;
	for(i = 1;i < numsSize;i++)
	{
		if(nums[i-1] > nums[i])
		{
			index = i-1;
			k++;
		}
	}
	if(k <= 1)
	{
		if(k == 0 || index == 0 || index+1 == numsSize-1)
			return true;
		if(nums[index-1] > nums[index+1] && nums[index] > nums[index+2])
			return false;
		return true;
	}
	else
		return false;
}