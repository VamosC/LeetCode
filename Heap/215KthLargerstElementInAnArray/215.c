int findKthLargest(int* nums, int numsSize, int k)
{
    int i;
    for(i = numsSize / 2;i >= 0;i--)
    {
        PercDown(nums, numsSize, i);
    }
    for(i = numsSize - 1;i > numsSize - k;i--)
    {
        Swap(&nums[i], &nums[0]);
        PercDown(nums, i, 0);
    }
    
    return nums[0];
}

void PercDown(int* nums, int numsSize, int i)
{
    int Tmp;
    int Child;
    for(Tmp = nums[i];2 * i + 1 < numsSize;i = Child)
    {
        Child = 2 * i + 1;
        if(Child != numsSize - 1 && nums[Child + 1] > nums[Child])
            Child++;
        if(Tmp < nums[Child])
            nums[i] = nums[Child];
        else
            break;
    }
    nums[i] = Tmp;
}

void Swap(int* p, int* q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}