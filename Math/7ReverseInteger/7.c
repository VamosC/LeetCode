int reverse(int x) 
{
    long long x_reverse;
    int flag = 0;
    
    if(x < 0)
    {
        flag = 1;
        x = -x;
    }
    x_reverse = 0;
    while(x > 0)
    {
        x_reverse *= 10;
        x_reverse += x%10;
        x /= 10;
    }
    
    if(flag)
    {
        x_reverse = -x_reverse;
    }
    
    if(x_reverse > pow(2, 31) - 1 || x_reverse < -pow(2, 31))
    {
        return 0;
    }
    return (int)x_reverse;
}