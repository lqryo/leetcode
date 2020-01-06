// 参考：https://leetcode-cn.com/problems/jump-game-ii/solution/chao-jian-dan-de-dong-tai-gui-hua-kan-bu-dong-ni-d/

#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>


using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums);



};

int Solution::maxSubArray(vector<int>& nums)
{
	int length = nums.size();

	int ans = nums[0];
	int sum = nums[0];

	for (size_t i = 1; i < length; i++)
	{
		if (sum < 0) {
			sum = nums[i];
			ans = max(sum, ans);
		}
		else {
			sum = sum + nums[i];
			ans = max(sum, ans);
		}
	}


	return ans;
}




int main()
{
	
	Solution s;
	vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
	cout << s.maxSubArray(nums) << endl;

	
	getchar();	
	return 0;

}