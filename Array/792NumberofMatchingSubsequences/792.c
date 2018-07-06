bool isSubsequecne(char* S, char* words);
int numMatchingSubseq(char* S, char** words, int wordsSize)
{
	int k;
	int i;
	k = 0;
	for(i = 0;i < wordsSize;i++)
	{
		if(isSubsequecne(S, words[i]))
		{
			k++;
		}
	}
	return k;
}

bool isSubsequecne(char* S, char* words)
{
	if(!*words)
		return true;
	while(*words != '\0')
	{
		while(*S != *words && *S != '\0')
			S++;
		if(*S == '\0')
			break;
		S++;
		words++;
	}
	return *words == '\0' ? true : false;
}