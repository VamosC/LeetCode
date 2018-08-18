int lengthOfLastWord(char* s)
{
    if(s == NULL)
    {
        return 0;
    }
    int k;
    char* token;
    char* pre;
    k = 0;
    token = strtok(s, " ");
    while(token != NULL)
    {
        pre = token;
        k++;
        token = strtok(NULL, " ");
    }
    if(k == 0)
    {
        return 0;
    }
    
    else
    {
        return strlen(pre);
    }
    
}