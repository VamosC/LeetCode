/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n)
{
    if(n == 0)
    {
        return NULL;
    }
    int i, j, k;
    int** matrix;
    int** visit;
    matrix = (int**)malloc(n*sizeof(int*));
    visit = (int**)malloc(n*sizeof(int*));
    for(i = 0;i < n;i++)
    {
        matrix[i] = (int*)malloc(n*sizeof(int));
        visit[i] = (int*)malloc(n*sizeof(int));
    }
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            visit[i][j] = 1;
        }
    }
    i = 0;
    j = -1;
    k = 1;
    while(k <= pow(n, 2))
    {
        while(j+1 < n && visit[i][j+1])
        {
            j++;
            matrix[i][j] = k++;
            visit[i][j] = 0;
        }
        while(i+1 < n && visit[i+1][j])
        {
            i++;
            matrix[i][j] = k++;
            visit[i][j] = 0;
        }
        while(j-1 > -1 && visit[i][j-1])
        {
            j--;
            matrix[i][j] = k++;
            visit[i][j] = 0;
        }
        while(i-1 > -1 && visit[i-1][j])
        {
            i--;
            matrix[i][j] = k++;
            visit[i][j] = 0;
        }
    }
    return matrix;
}