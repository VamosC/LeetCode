/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void findSolution(int* nums, int left, int right, int** columnSizes, int* returnSize, int** res, int* buf, int curNum);
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize)
{
    int i;
    int size;
    int** res;
    int* buf;
    size = 1 << numsSize;
    buf = (int*)malloc(numsSize*sizeof(int));
    *returnSize = 0;
    *columnSizes = (int*)malloc(size*sizeof(int));
    res = (int**)malloc(size*sizeof(int*));
    res[0] = (int*)malloc(sizeof(int));
    for(i = 0;i < numsSize;i++)
    {
        findSolution(nums, i, numsSize - 1, columnSizes, returnSize, res, buf, 0);
    }
    res[(*returnSize)++] = (int*)malloc(sizeof(int));
    (*columnSizes)[(*returnSize) - 1] = 0;
    return res;
}

void findSolution(int* nums, int left, int right, int** columnSizes, int* returnSize, int** res, int* buf, int curNum)
{
    int i;
    if(left <= right)
    {
        buf[curNum] = nums[left];
        (*returnSize)++;
        (*columnSizes)[(*returnSize) - 1] = curNum + 1;
        res[*returnSize - 1] = (int*)malloc((curNum+1)*sizeof(int));
        for(i = 0;i <= curNum;i++)
        {
            res[(*returnSize) - 1][i] = buf[i];
        }
        for(i = left;i <= right;i++)
        {
            findSolution(nums, i + 1, right, columnSizes, returnSize, res, buf, curNum + 1);
        }
    }
}
