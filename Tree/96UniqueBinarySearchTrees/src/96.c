int odd(int n);
int numTrees(int n) {
    int i;
    int sum;

    if(n == 0)
        return 1;
    if(n == 1)
        return 1;

    sum = 0;

    for(i = 1;i <= n/2;i++)
    {
        sum += numTrees(i-1) * numTrees(n-i);
    }
    
    //double sum
    sum += sum;
    
    if(odd(n))
        sum += numTrees(i-1) * numTrees(n-i);
        

    return sum;
}

int odd(int n)
{
    return n%2;
}