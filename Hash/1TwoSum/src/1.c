/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
enum status {empty, legitimate};
typedef int position;

int flag;

struct HNode
{
	int val;
	position index;
	enum status info;
};

struct HashTable
{
	struct HNode* H;
	int Hsize;
};

int* twoSum(int* nums, int numsSize, int target)
{
	int i;
	int complement, pos;
    int* returnSize;
    struct HashTable* HashT;

    flag = 0;
    returnSize = (int*)malloc(2 * sizeof(int));
    HashT = (struct HashTable* )malloc(sizeof(struct HashTable));
    HashT->Hsize = nextPrime(2*numsSize);
    HashT->H = (struct HNode*)malloc(HashT->Hsize * sizeof(struct HNode));

    //init
    for(i = 0;i < HashT->Hsize;i++)
    {
      HashT->H[i].info = empty;
    }

    for(i = 0;i < numsSize;i++)
    {
      complement = target - nums[i];
      pos = find(HashT, complement, 1);
      if(flag)
      {
    	  returnSize[0] = pos;
    	  returnSize[1] = i;
    	  break;
      }
      else
      {
    	  pos = find(HashT, nums[i], 0);
    	  insert(HashT, nums[i], i, pos);
      }
    }

    return returnSize;
}

int hash(struct HashTable* HashT, int key)
{
	if(key < 0)
		key = -key;
	return key % HashT->Hsize;
}

position find(struct HashTable* HashT, int key, int choice)
{
	int i;
	int index;
	for(i = 0;i < HashT->Hsize;i++)
	{
		index = hash(HashT, key + i*i);
		if(HashT->H[index].info == empty)
			break;
		if(HashT->H[index].info != empty && HashT->H[index].val == key && choice)
		{
			flag = 1;
			return HashT->H[index].index;
		}
	}
	return index;
}

void insert(struct HashTable* HashT, int val, int index, position pos)
{
	HashT->H[pos].info = legitimate;
	HashT->H[pos].val = val;
	HashT->H[pos].index = index;
}

int nextPrime(int x)
{
	int i, k;
	for(i = x;;i++)
	{
		for(k = 2;k * k <= i;k++)
		{
			if(i % k == 0)
				break;
		}
		if(i != 1 && k * k > i)
			break;
	}
	return i;
}
