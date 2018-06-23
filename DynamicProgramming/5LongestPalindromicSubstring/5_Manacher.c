char* longestPalindrome(char* s) 
{
	int i;
	int m;
	int l;
	int mx, id;
	int max, maxid;
	int* p;
	char* new_s;
	char* return_s;
	i = 0;
	while(s[i] != '\0')
		i++;
	new_s = (char*)malloc((2*i+3)*sizeof(char));
	p = (int*)malloc((2*i+3)*sizeof(int));

	new_s[0] = '$';
	for(l = 1, m = 0;l < 2*i+2;m++)
	{
		new_s[l++] = '#';
		new_s[l++] = s[m];
	}
	new_s[l] = '\0';
	mx = id = 0;
	max = maxid = 0;
	for(l = 1;l < 2*i+2;l++)
	{
		p[l] = l < mx ? min(p[2*id-l], mx-l) : 1;
		while(new_s[l+p[l]] == new_s[l-p[l]])
			p[l]++;
		if(mx < l + p[l])
		{
			id = l;
			mx = l + p[l];
		}
		if(max < p[l])
		{
			maxid = l;
			max = p[l];
		}
	}
	return_s = (char*)malloc(max*sizeof(char));
	l = maxid/2;
	l = max%2 == 0 ? l-max/2 : l - (max-1)/2;
	for(i = 0;i < max-1;i++)
		return_s[i] = s[i+l];
	return_s[i] = '\0';
	return return_s;
}

int min(int a, int b)
{
	return a < b ? a : b;
}