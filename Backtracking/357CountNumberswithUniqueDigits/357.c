void findSolution(int curNum, int k, int* S, int* total);
int countNumbersWithUniqueDigits(int n)
{
	int* S;
	int i;
	int total;
	if(n == 0)
		return 1;
	S = (int*)malloc(10*sizeof(int));
	for(i = 0;i < 10;i++)
		S[i] = 1;
	total = 0;

	for(i = 1;i <= n;i++)
		findSolution(0, i, S, &total);
	return total;
}

void findSolution(int curNum, int k, int* S, int* total)
{
	int i;
	if(curNum == k)
		(*total)++;
	else
	{
		for(i = 0;i < 10;i++)
		{
			if(S[i])
			{
				if(i == 0 && curNum == k - 1 && k > 1);
				else
				{
					S[i] = 0;
					findSolution(curNum + 1, k, S, total);
					S[i] = 1;
				}
			}
		}
	}
}