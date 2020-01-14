#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <stack>


using namespace std;

// 参考：https://leetcode-cn.com/problems/house-robber-ii/solution/213-da-jia-jie-she-iidong-tai-gui-hua-jie-gou-hua-/
// 将问题简化为单排列房间问题
// 1. 不偷第一个房子
// 2. 不偷最后一个房子
// 上面两种情况有交集，但是其并集覆盖所有情况

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		int ans1, ans2;
		vector<int> dp(nums.size() + 1);
		
		// 不偷第一个房子
		dp[0] = 0;
		dp[1] = 0;
		for (size_t i = 2; i <= nums.size(); i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
		}
		ans1 = dp[nums.size()];

		//不偷最后一个房子
		dp.clear();
		dp[0] = 0;
		dp[1] = nums[0];
		for (size_t i = 2; i < nums.size(); i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
		}
		ans2 = dp[nums.size() - 1];

		return max(ans1, ans2);

	}
};



int main()
{

	cin.get();
}
