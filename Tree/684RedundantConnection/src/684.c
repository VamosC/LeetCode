/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef int* DisjSet;
typedef int ElementType;
typedef int Vertex;
int Find(DisjSet S, ElementType X);
void Union(int root1, int root2, DisjSet S);
int* findRedundantConnection(int** edges, int edgesRowSize, int edgesColSize, int* returnSize)
{
	DisjSet S;
	int i;
	Vertex u, v;
	int* returnEdge;
	*returnSize = 0;
	if(edgesRowSize == 0)
		return NULL;

	S = (DisjSet)malloc((edgesRowSize + 1)*sizeof(ElementType));
	returnEdge = (int*)malloc(edgesColSize*sizeof(int));
	for(i = 0;i <= edgesRowSize;i++)
	{
		S[i] = -1;
	}

	for(i = 0;i < edgesRowSize;i++)
	{
		u = edges[i][0];
		v = edges[i][edgesColSize - 1];
		if(Find(S, u) == Find(S, v))
		{
			returnEdge[0] = u;
			returnEdge[edgesColSize - 1] = v;
			*returnSize = 2;
			break;
		}
		else
		{
			Union(Find(S, u), Find(S, v), S);
		}
	}
	return returnEdge;
}

int Find(DisjSet S, ElementType X)
{
	if(S[X] < 0)
	{
		return X;
	}
	else
	{
		return S[X] = Find(S, S[X]);
	}
}

void Union(int root1, int root2, DisjSet S)
{
	if(S[root1] <= S[root2])
	{
		S[root1] += S[root2];
		S[root2] = root1;
	}
	else
	{
		S[root2] += S[root1];
		S[root1] = root2;
	}
}