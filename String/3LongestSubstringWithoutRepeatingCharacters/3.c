int lengthOfLongestSubstring(char* s)
{
    int i, j;
    int size;
    int hashTable[102];
    int maxLength;
    int curLength;
    size = strlen(s);
    if(size == 0)
    {
        return 0;
    }
    maxLength = curLength = 0;
    for(i = 0;i < size;i++)
    {
        curLength = 0;
        for(j = 0;j < 102;j++)
        {
            hashTable[j] = 0;
        }
        for(j = i;j < size;j++)
        {
            if(hashTable[s[j] - ' '])
            {
                break;
            }
            curLength++;
            hashTable[s[j] - ' '] = 1;
        }
        if(curLength > maxLength)
        {
            maxLength = curLength;
        }
    }  
    return maxLength;
}