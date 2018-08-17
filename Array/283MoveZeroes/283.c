void moveZeroes(int* nums, int numsSize)
{
    int i;
    int length;
    length = 0;
    for(i = 0;i < numsSize;i++)
    {
        if(nums[i] != 0)
        {
            nums[length++] = nums[i];
        }
    }    
    for(i = length;i < numsSize;i++)
    {
        nums[length++] = 0;
    }
}