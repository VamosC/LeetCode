/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize)
{
    int i, j, k;
    if(matrixRowSize == 0 && matrixColSize == 0)
    {
        return NULL;
    }
    int visit[matrixRowSize][matrixColSize];
    int* res;
    int size;
    res = (int*)malloc(sizeof(int)*matrixRowSize*matrixColSize);
    for(i = 0;i < matrixRowSize;i++)
    {
        for(j = 0;j < matrixColSize;j++)
        {
            visit[i][j] = 1;
        }
    }
    size = matrixRowSize * matrixColSize;
    i = 0;
    j = -1;
    k = 0;
    while(k < size)
    {
        while(j+1 < matrixColSize && visit[i][j+1])
        {
            j++;
            res[k++] = matrix[i][j];
            visit[i][j] = 0;
        }
        while(i+1 < matrixRowSize && visit[i+1][j])
        {
            i++;
            res[k++] = matrix[i][j];
            visit[i][j] = 0;
        }
        while(j-1 > -1 && visit[i][j-1])
        {
            j--;
            res[k++] = matrix[i][j];
            visit[i][j] = 0;
        }
        while(i-1 > -1 && visit[i-1][j])
        {
            i--;
            res[k++] = matrix[i][j];
            visit[i][j] = 0;
        }
    }

    return res;
}