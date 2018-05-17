#define MAX 101
int uniquePaths(int m, int n) {
    int s[MAX][MAX];
    int i, j;
    s[0][0] = 1;
    for(i = 1;i < n;i++)
    {
    	s[0][i] = s[0][i-1];
    }
    for(i = 1;i < m;i++)
    {
    	s[i][0] = s[i-1][0];
    }
    for(i = 1;i < m;i++)
    {
    	for(j = 1;j < n;j++)
    	{
    		s[i][j] = s[i-1][j] + s[i][j-1];
    	}
    }
    return s[m-1][n-1];
}