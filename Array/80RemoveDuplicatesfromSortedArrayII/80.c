int removeDuplicates(int* nums, int numsSize) 
{
    int i;
    int length;
    int times;
    length = -1;
    times = 2;
    for(i = 0;i < numsSize;i++)
    {
    	if(nums[length] != nums[i])
    	{
    		nums[++length] = nums[i];
    		times = 1;
    	}
    	else
    	{
    		if(times == 0)
    		{
    			continue;
    		}
    		nums[++length] = nums[i];
    		times--;
    	}
    }
    return length + 1;
}