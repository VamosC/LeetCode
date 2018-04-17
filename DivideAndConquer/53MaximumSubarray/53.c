#define NEGATIVE -100000
int findMaxSum(int* nums, int left, int right);
int Max(int a, int b, int c);
int maxSubArray(int* nums, int numsSize)
{
	return findMaxSum(nums, 0, numsSize - 1);
}

int findMaxSum(int* nums, int left, int right)
{
	int i, median;
	int leftMaxSum, rightMaxSum;
	int leftMedianMaxSum, rightMedianMaxSum;
	int sum;
	if(left == right)
	{
		return nums[left];
	}
	else
	{
		median = (left + right)/2;
		leftMaxSum = findMaxSum(nums, left, median);
		rightMaxSum = findMaxSum(nums, median + 1, right);
		leftMedianMaxSum = rightMedianMaxSum = NEGATIVE;
		sum = 0;
		for(i = median;i >= left;i--)
		{
			sum += nums[i];
			if(sum > leftMedianMaxSum)
				leftMedianMaxSum = sum;
		}
		sum = 0;
		for(i = median + 1;i <= right;i++)
		{
			sum += nums[i];
			if(sum > rightMedianMaxSum)
				rightMedianMaxSum = sum;
		}
	}
	return Max(leftMaxSum, rightMaxSum, leftMedianMaxSum + rightMedianMaxSum);
}

int Max(int a, int b, int c)
{
	if(a > b)
		return a > c ? a : c;
	else
		return b > c ? b : c;
}