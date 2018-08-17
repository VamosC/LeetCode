int removeDuplicates(int* nums, int numsSize) 
{
    int length, i;
    int lastNum;
    length = 0;
    if(numsSize == 0)
    {
    	return length;
    }
    for(i = 0;i < numsSize;i++)
    {
    	if(nums[length] != nums[i])
    	{
    		nums[++length] = nums[i];
    	}
    }
    return length+1;
}