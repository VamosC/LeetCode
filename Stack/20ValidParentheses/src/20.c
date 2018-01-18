#define MAX 100000
bool isValid(char* s)
{
	char Stack[MAX];
	int top;
	int i;

	//Init
	top = -1;
	i = 0;

	while(s[i] != '\0')
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			Stack[++top] = s[i];//push
		else
		{
			//pop
			if(top == -1)
				return 0;
			if(s[i] == ')'  && Stack[top--] != '(')
				return 0;
			else if(s[i] == ']' && Stack[top--] != '[')
				return 0;
			else if(s[i] == '}' && Stack[top--] != '{')
				return 0;
		}
		i++;
	}

	//check stack empty
	return top == -1 ? 1 : 0;
}