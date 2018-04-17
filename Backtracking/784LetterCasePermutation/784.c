/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX 10000
void findSolution(char** res, char* S, int* returnSize, int curNum, int k, int* A);
char** letterCasePermutation(char* S, int* returnSize)
{
    char** res;
    int* A;
    int k;
    int i;
    k = 0;
    *returnSize = 0;
    while(S[k] != '\0')
    {
        if(S[k] >= 'A' && S[k] <= 'Z')
            S[k] = 'a' + S[k] - 'A';
        k++;
    }
    A = (int*)malloc(k*sizeof(int));
    for(i = 0;i < k;i++)
    {
        if(S[i] >= '0' && S[i] <= '9')
            A[i] = 0;
        else
            A[i] = 1;
    }
    res = (char**)malloc(MAX*sizeof(char*));
    findSolution(res, S, returnSize, 0, k, A);
    return res;
}

void findSolution(char** res, char* S, int* returnSize, int curNum, int k, int* A)
{
    int i;
    i = 0;
    if(curNum < k)
    {
        while(A[i] != -1 && i < k)
        {
            if(A[i] == 1)
            {
                A[i] = -1;
                findSolution(res, S, returnSize, curNum + 1, k, A);
                S[i] = S[i] - 'a' + 'A';
                findSolution(res, S, returnSize, curNum + 1, k, A);
                S[i] = S[i] - 'A' + 'a';
                A[i] = 1;
            }
            else
            {
                A[i] = -1;
                findSolution(res, S, returnSize, curNum + 1, k, A);
                A[i] = 0;
            }
            i++;
        }
    }
    else
    {
        (*returnSize)++;
        res[(*returnSize) - 1] = (char*)malloc((k+1)*sizeof(char));
        for(i = 0;i < k;i++)
        {
            res[(*returnSize) - 1][i] = S[i];
        }
        res[(*returnSize) - 1][i] = '\0';
    }
}