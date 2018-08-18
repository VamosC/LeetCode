/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int* res;
    int i;
    int bit;
    bit = 1;
    for(i = digitsSize-1;i >= 0;i--)
    {
        digits[i] += bit;
        if(digits[i] == 10)
        {
            digits[i] = 0;
            bit = 1;
            if(i == 0)
            {
                break;
            }
        }
        
        else
        {
            bit = 0;
        }
    }
    *returnSize = digitsSize+bit;    
    res = (int*)malloc((bit+digitsSize)*sizeof(int));
    if(bit)
    {
        res[0] = bit;
        for(i = 1;i < *returnSize;i++)
        {
            res[i] = digits[i-1];
        }
    }
    else
    {
        for(i = 0;i < *returnSize;i++)
        {
            res[i] = digits[i];
        }
    }
    return res;
}