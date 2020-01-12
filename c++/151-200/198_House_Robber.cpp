
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// ¶¯Ì¬¹æ»®

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		vector<int> dp(nums.size() + 1);
		
		dp[0] = 0;
		dp[1] = nums[0];

		for (size_t i = 2; i <= nums.size(); i++)
		{
			dp[i] = max(dp[i - 1], nums[i-1] + dp[i - 2]);
		}

		return dp[nums.size()];
	}
};


int main()
{
	Solution s;
	vector<int> m{ 1,2,3,1 };

	cout << s.rob(m) << endl;

	cin.get();

	return 0;
}

