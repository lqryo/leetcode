#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	vector<int> ans;
	size_t length = nums.size();
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i+1; j < length; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				ans.push_back(i);
				ans.push_back(j);
				return ans;
			}
		}
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