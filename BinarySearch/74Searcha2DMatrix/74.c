bool findTargetRow(int** matrix, int left, int right, int matrixColSize, int target);
bool findTargetCol(int** matrix, int left, int right, int row, int target);
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{ 
    if(matrixRowSize == 0)
        return false;
	return findTargetRow(matrix, 0, matrixRowSize - 1, matrixColSize, target);
}

bool findTargetRow(int** matrix, int left, int right, int matrixColSize, int target)
{
	int median;
	if(left == right)
	{
        if(matrix[left][0] == target)
            return true;
		else if(left > 0 && matrix[left][0] > target)
			left--;
		return findTargetCol(matrix, 0, matrixColSize - 1, left, target);
	}
	else if(left < right)
	{
		median = (left + right)/2;
		if(matrix[median][0] > target)
			return findTargetRow(matrix, left, median - 1, matrixColSize, target);
		else if(matrix[median][0] < target)
			return findTargetRow(matrix, median + 1, right, matrixColSize, target);
		else
			return true;
	}
    else
        return findTargetRow(matrix, left, right + 1, matrixColSize, target);
}

bool findTargetCol(int** matrix, int left, int right, int row, int target)
{
	int median;
	if(left <= right)
	{
		median = (left + right)/2;
		if(matrix[row][median] > target)
			return findTargetCol(matrix, left, median - 1, row, target);
		else if(matrix[row][median] < target)
			return findTargetCol(matrix, median + 1, right, row, target);
		else
			return true;
	}
	else
		return false;
}