// �ο���https://leetcode-cn.com/problems/jump-game-ii/solution/chao-jian-dan-de-dong-tai-gui-hua-kan-bu-dong-ni-d/

#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>


using namespace std;

class Solution {
public:
	int jump(vector<int>& nums);
};

int Solution::jump(vector<int>& nums)
{
	int length = nums.size();
	if (length == 1) return 0;
	if (length == 2) return 1;

	vector<int> start(length);
	vector<int> dp(length);  //dp[i]��ʾ�����õ���Ҫ�����ٲ���
	dp[0] = 0;
	start[0] = 0;
	dp[1] = 1;
	start[1] = 1;


	for (size_t i = 2; i < length; i++)
	{
		int jump_num = dp[i-1];  //������i-1����Ҫ�Ĳ���

		//dp[i]ֻ����Ϊdp[i-1]��dp[i-1]+1
		if (nums[i - 1] == 0) {
			dp[i] = dp[i - 1];  //��Ϊһ���н�;
		}

		bool flag = false;

		int jump_start = start[jump_num - 1];
		int jump_end = start[jump_num] - 1;

		for (int j = jump_start; j <= jump_end; j++)
		{
			int diff = i - j;
			if (nums[j] >= diff) {
				dp[i] = dp[i - 1];
				flag = true;
				break;
			}
		}

		if (flag == false) {
			dp[i] = dp[i - 1] + 1;
			start[dp[i]] = i;
		}
	}


	return dp[length - 1];
}




int main()
{
	
	Solution s;
	vector<int> nums{ 3,2,1 };
	cout << s.jump(nums) << endl;

	getchar();	
	return 0;

}