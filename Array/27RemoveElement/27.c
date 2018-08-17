int removeElement(int* nums, int numsSize, int val)
{
    int i, length;
    length = 0;
    if(numsSize == 0)
    {
        return length;
    }    
    for(i = 0;i < numsSize;i++)
    {
        if(nums[i] == val)
        {
            continue;
        }
        
        else
        {
            nums[length++] = nums[i];
        }
        
    }

    return length;
}