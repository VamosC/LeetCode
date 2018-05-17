#define MAX 101
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int s[MAX][MAX];
    int i, j;
    if(obstacleGrid[0][0] == 1)
    	return 0;
    s[0][0] = 1;
    for(i = 1;i < obstacleGridColSize;i++)
    {
    	if(obstacleGrid[0][i] != 1)
    	{
    		s[0][i] = s[0][i-1];
    	}
    	else
    	{
    		s[0][i] = 0;
    	}
    }
    for(i = 1;i < obstacleGridRowSize;i++)
    {
    	if(obstacleGrid[i][0] != 1)
    	{
    		s[i][0] = s[i-1][0];
    	}
    	else
    	{
    		s[i][0] = 0;
    	}
    }

    for(i = 1;i < obstacleGridRowSize;i++)
    {
    	for(j = 1;j < obstacleGridColSize;j++)
    	{
    		if(obstacleGrid[i][j] != 1)
    		{
    			s[i][j] = s[i-1][j] + s[i][j-1];
    		}
    		else
    		{
    			s[i][j] = 0;
    		}
    	}
    }

    return s[obstacleGridRowSize-1][obstacleGridColSize-1];
}