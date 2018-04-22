int findMaxSubSum(int* price, int l, int r);
int Max(int a, int b, int c);
int maxProfit(int* prices, int pricesSize)
{
    if(pricesSize == 0 || pricesSize == 1)
        return 0;
        
	int price[pricesSize - 1];
	int i;
	int sum;
	for(i = 0;i < pricesSize - 1;i++)
		price[i] = prices[i + 1] - prices[i];
	sum = findMaxSubSum(price, 0, pricesSize - 2);
    if(sum < 0)
        sum = 0;
	return sum;
}

int findMaxSubSum(int* price, int l, int r)
{
	int i;
	int m;
	int leftMaxSum;
	int rightMaxSum;
	int leftMaxTotal, rightMaxTotal;
	int total;
    if(l > r)
        return 0;
	if(l == r)
		return price[l];
	m = (l + r)/2;
	leftMaxSum = findMaxSubSum(price, l, m-1);
	rightMaxSum = findMaxSubSum(price, m+1, r);
	leftMaxTotal = rightMaxTotal = 0;
    total = 0;
	for(i = m;i >= l;i--)
	{
		total += price[i];
		if(total > leftMaxTotal)
			leftMaxTotal = total;
	}
    total = 0;
	for(i = m + 1;i <= r;i++)
	{
		total += price[i];
		if(total > rightMaxTotal)
			rightMaxTotal = total;
	}
	return Max(leftMaxSum, rightMaxSum, leftMaxTotal + rightMaxTotal);
}

int Max(int a, int b, int c)
{
	if(a > b)
		return a > c ? a : c;
	else
		return b > c ? b : c;
}