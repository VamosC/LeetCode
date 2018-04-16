void findSolution(char* s, char* problemSet, int n, int k, int curNum, int* position, int* found);
char* getPermutation(int n, int k)
{
	char* s, *problemSet;
	int i, position, found;
	problemSet = (char*)malloc(n*sizeof(char));
	s = (char*)malloc((n+1)*sizeof(char));
	s[n] = '\0';
	position = 0;
	found = 0;
	for(i = 0;i < n;i++)
	{
		problemSet[i] = '0' + i + 1;
	}
	findSolution(s, problemSet, n, k, 0, &position, &found);
	return s;
}

void findSolution(char* s, char* problemSet, int n, int k, int curNum, int* position, int* found)
{
	int i;
	if(curNum < n)
	{
		for(i = 0;i < n;i++)
		{
			if(problemSet[i] != '0')
			{
				s[curNum] = problemSet[i];
				problemSet[i] = '0';
				findSolution(s, problemSet, n, k, curNum+1, position, found);
				if(*found)
					return;
				problemSet[i] = '0' + i + 1;
			}
		}
	}
	else
	{
		(*position)++;
		if((*position) == k)
		{
			*found = 1;
		}

	}
}