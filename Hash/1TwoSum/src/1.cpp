class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashTable;
        vector<int> result;
        if(nums.size() < 2)
            return result;
        for(int i = 0; i < nums.size(); i++)
        {
        	if(hashTable.find(target - nums[i]) == hashTable.end())
        		hashTable[nums[i]] = i;
        	else
        	{
        		result.push_back(hashTable.find(target - nums[i])->second);
        		result.push_back(i);
        		break;
        	}
        }
        return result;
    }
};