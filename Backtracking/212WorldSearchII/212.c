/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findSolution(char** board, int boardRowSize, int boardColSize, char* word, int*returnSize, int curNum, int x, int y, char** s);
char** findWords(char** board, int boardRowSize, int boardColSize, char** words, int wordsSize, int* returnSize)
{
	char** s;
	int i, j, k, m, n;
	int flag, flag1;
	s = (char**)malloc(wordsSize*sizeof(char*));
	*returnSize = 0;
	for(i = 0;i < wordsSize;i++)
	{
        flag1 = 1;
		flag = 0;
        for(m = 0;m < i;m++)
        {
            n = 0;
            while(words[i][n] != '\0' && words[m][n] != '\0')
            {
                if(words[i][n] != words[m][n])
                {
                    break;
                }
                n++;
            }
            if(words[i][n] == '\0' && words[m][n] == '\0')
                flag1 = 0;
        }
        if(flag1)
        {
            for(j = 0;j < boardRowSize;j++)
		    {
		        for(k = 0;k < boardColSize;k++)
			    {
				    if(board[j][k] == words[i][0])
				    {
					    flag = findSolution(board, boardRowSize, boardColSize, words[i], returnSize, 1, j, k, s);
				    }
				    if(flag == 1)
					    break;
			}
			    if(flag == 1)
				    break;
		}
        }
	}
	return s;
}

int findSolution(char** board, int boardRowSize, int boardColSize, char* word, int*returnSize, int curNum, int x, int y, char** s)
{
	int flag;
	int i;
	flag = 0;
	if(word[curNum] == '\0')
	{
		flag = 1;
		(*returnSize)++;
		s[(*returnSize) - 1] = (char*)malloc((curNum+1)*sizeof(char));
		for(i = 0;i <= curNum;i++)
			s[(*returnSize) - 1][i] = word[i];
	}
	else
	{
		board[x][y] = '\0';
		if(x + 1 < boardRowSize && board[x + 1][y] != '\0' && board[x + 1][y] == word[curNum])
			flag = findSolution(board, boardRowSize, boardColSize, word, returnSize, curNum + 1, x + 1, y, s);
		if(!flag && x - 1 >= 0 && board[x - 1][y] != '\0' && board[x - 1][y] == word[curNum])
			flag = findSolution(board, boardRowSize, boardColSize, word, returnSize, curNum + 1, x - 1, y, s);
		if(!flag && y + 1 < boardColSize && board[x][y + 1] != '\0' && board[x][y + 1] == word[curNum])
			flag = findSolution(board, boardRowSize, boardColSize, word, returnSize, curNum + 1, x, y + 1, s);
		if(!flag && y - 1 >= 0 && board[x][y - 1] != '\0' && board[x][y - 1] == word[curNum])
			flag = findSolution(board, boardRowSize, boardColSize, word, returnSize, curNum + 1, x, y - 1, s);
		board[x][y] = word[curNum - 1];
	}
	return flag;
}