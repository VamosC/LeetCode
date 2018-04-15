void findSolutionNum(int* A, int N, int curNum, int* solutionNum);
int countArrangement(int N)
{
	int* A;
	int solutionNum, i;
	solutionNum = 0;
	A = (int)malloc((N+1)*sizeof(int));
	for(i = 1;i <= N;i++)
	{
		A[i] = 1;
	}
	findSolutionNum(A, N, 1, &solutionNum);
	return solutionNum;
}

void findSolutionNum(int* A, int N, int curNum, int* solutionNum)
{
	int i;
	if(curNum > N)
	{
		(*solutionNum)++;
	}
	else
	{
		for(i = 1;i <= N;i++)
		{
			if(A[i] != -1)
			{
				A[i] = -1;
				if(i % curNum == 0 || curNum % i == 0)
				{
					findSolutionNum(A, N, curNum+1, solutionNum);
				}
				A[i] = 1;
			}
		}
	}
}