bool findTarget(int** matrix, int rup, int rbottom, int cleft, int cright, int target);

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    return findTarget(matrix, 0, matrixRowSize - 1, 0, matrixColSize - 1, target);
}

bool findTarget(int** matrix, int rup, int rbottom, int cleft, int cright, int target)
{
	int rowMedian, colMedian;
	if(cleft > cright || rup > rbottom)
		return false;

	else
	{
		rowMedian = (rup + rbottom)/2;
		colMedian = (cleft + cright)/2;
		if(matrix[rowMedian][colMedian] > target)
			return findTarget(matrix, rup, rowMedian , cleft, colMedian - 1, target) ||
		findTarget(matrix, rup, rowMedian - 1, colMedian, cright, target) || findTarget(matrix, rowMedian + 1, rbottom, cleft, colMedian - 1, target);
		else if(matrix[rowMedian][colMedian] < target)
			return findTarget(matrix, rup, rowMedian, colMedian + 1, cright, target) ||
		findTarget(matrix, rowMedian + 1, rbottom, cleft, colMedian, target) || findTarget(matrix, rowMedian + 1, rbottom, colMedian + 1, cright, target);
		else
			return true;
	}
}