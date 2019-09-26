/*
******???hash?????任????*****
******hash????????????д????????????????临???*****
*/
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	vector<int> ans;
	map<int, int> hash;
	int length = nums.size();
	int complement;
	for (size_t i = 0; i < length; i++)
	{
		complement = target - nums[i];
		if (hash.find(complement) != hash.end())
		{
			ans.push_back(hash[complement]);
			ans.push_back(i);
			return ans;
		}
		hash[nums[i]] = i;
	}
	return ans;
}

int main()
{
	vector<int> num = { 2,7,11,15 };
	Solution solution;
	vector<int> ans = solution.twoSum(num, 9);
	return 0;
}