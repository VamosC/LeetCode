bool isSubsequence(char* s, char* t)
{
	int m, n;
	int i, j;
	m = strlen(s);
	n = strlen(t);
    int r[n+1];
    int p[n+1];
	if(n == 0 && m > 0)
		return false;
	if(m == 0)
		return true;
	
    for(i = 0;i <= n;i++)
        p[i] = 0;
	for(i = 0;i < m;i++)
	{
		for(j = 0;j < n;j++)
		{
			if(s[i] == t[j])
			{
				r[j+1] = p[j] + 1;
			}
			else
			{
				r[j+1] = max(p[j+1], r[j]);
			}
		}
        for(j = 1;j <= n;j++)
            p[j] = r[j];
	}
	return  p[n] == m ? true : false; 
}

int max(int a, int b)
{
	return a > b ? a : b;
}