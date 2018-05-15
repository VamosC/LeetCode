#define MAX 1001
char* longestPalindrome(char* s) {
	int i, j, l;
	int sLength;
	int tLength;
	char* t;
	sLength = 0;
	tLength = 0;
	int m[MAX][MAX];
	int f[MAX][MAX];
	i = 0;
	while(s[i] != '\0')
	{
		i++;
	}
	sLength = i;
	for(i = 0;i < sLength;i++)
	{
		m[i][i] = i;
		f[i][i] = i;
	}
	for(l = 1;l < sLength;l++)
	{
		for(i = 0;i+l < sLength;i++)
		{
			j = i+l;
			if(s[i] == s[j] && ((i + 1 >= j - 1) ||(m[i+1][j-1] == i+1 && f[i+1][j-1] == j-1)))
			{
				m[i][j] = i;
				f[i][j] = j;
			}
			else
			{
				if((f[i+1][j] - m[i+1][j]) > (f[i][j-1] - m[i][j-1]))
				{
					m[i][j] = m[i+1][j];
					f[i][j] = f[i+1][j];
				}
				else
				{
					m[i][j] = m[i][j-1];
					f[i][j] = f[i][j-1];
				}
			}
		}
	}
	tLength = f[0][sLength - 1] - m[0][sLength - 1] + 1;
	t = (char*)malloc((tLength+1)*sizeof(char));
	for(i = 0;i + m[0][sLength - 1] <= f[0][sLength - 1];i++)
	{
		t[i] = s[i+m[0][sLength - 1]];
	}
	t[i] = '\0';
	return t;
}