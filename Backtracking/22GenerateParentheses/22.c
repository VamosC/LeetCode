/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 10000
void findSolution(char** s, int t, int m, int n, int curNum, int*returnSize, char* buf);
char** generateParenthesis(int n, int* returnSize)
{
	char* buf;
	char** s;
	*returnSize = 0;
	s = (char**)malloc(MAX*sizeof(char*));
	buf[n] = '\0';
	buf = (char*)malloc((2*n+1)*sizeof(char));
	findSolution(s, n, n, n, 0, returnSize, buf);
	return s;
}

void findSolution(char** s, int t, int m, int n, int curNum, int* returnSize, char* buf)
{
	int i;
	if(m == 0 && n == 0)
	{
		(*returnSize)++;
		s[(*returnSize) - 1] = (char*)malloc((t+1)*sizeof(char));
		for(i = 0;i <= 2*t + 1;i++)
		{
			s[(*returnSize) - 1][i] = buf[i];
		}
	}
	else
	{
		if(m != 0 && n != 0)
		{
			if(m == n)
			{
				buf[curNum] = '(';
				findSolution(s, t, m-1, n, curNum+1, returnSize, buf);
			}
			else
			{
				buf[curNum] = '(';
				findSolution(s, t, m-1, n, curNum+1, returnSize, buf);
				buf[curNum] = ')';
				findSolution(s, t, m, n-1, curNum+1, returnSize, buf);
			}
		}
		else
		{
			buf[curNum] = ')';
			findSolution(s, t, m, n-1, curNum+1, returnSize, buf);
		}
	}
}