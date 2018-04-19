bool findSolution(char** board, int boardRowSize, int boardColSize, char* word, int curNum, int x, int y);
bool exist(char** board, int boardRowSize, int boardColSize, char* word)
{
	bool flag;
	char Tmp;
    int i, j;
	flag = false;
	if(word == NULL || word[0] == '\0')
		return false;
	for(i = 0;i < boardRowSize;i++)
	{
		for(j = 0;j < boardColSize;j++)
			if(word[0] == board[i][j])
			{
				Tmp = board[i][j];
				board[i][j] = '\0';
				flag = findSolution(board, boardRowSize, boardColSize, word, 1, i, j);
				board[i][j] = Tmp;
				if(flag == true)
					return true;
			}
	}
	return false;
}
bool findSolution(char** board, int boardRowSize, int boardColSize, char* word, int curNum, int x, int y)
{
	bool flag;
	char Tmp;
	flag = false;
	if(word[curNum] == '\0')
	{
		flag = true;
	}
	else
	{
		if(x + 1 < boardRowSize && board[x + 1][y] != '\0' && board[x + 1][y] == word[curNum])
		{
			Tmp = board[x + 1][y];
			board[x + 1][y] = '\0';
			flag = findSolution(board, boardRowSize, boardColSize, word, curNum+1, x+1, y);
			board[x + 1][y] = Tmp;
		}

		if(!flag && x - 1 >= 0 && board[x - 1][y] != '\0' && board[x - 1][y] == word[curNum])
		{
			Tmp = board[x - 1][y];
			board[x - 1][y] = '\0';
			flag = findSolution(board, boardRowSize, boardColSize, word, curNum+1, x-1, y);
			board[x - 1][y] = Tmp;
		}

		if(!flag && y + 1 < boardColSize && board[x][y + 1] != '\0' && board[x][y + 1] == word[curNum])
		{
			Tmp = board[x][y + 1];
			board[x][y + 1] = '\0';
			flag = findSolution(board, boardRowSize, boardColSize, word, curNum+1, x, y+1);
			board[x][y + 1] = Tmp;
		}

		if(!flag && y - 1 >= 0 && board[x][y - 1] != '\0' && board[x][y - 1] == word[curNum])
		{
			Tmp = board[x][y - 1];
			board[x][y - 1] = '\0';
			flag = findSolution(board, boardRowSize, boardColSize, word, curNum+1, x, y-1);
            board[x][y - 1] = Tmp;
		}
	}
	return flag;
}