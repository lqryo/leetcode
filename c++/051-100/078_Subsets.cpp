#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 回溯 参考：https://leetcode-cn.com/problems/combinations/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-ma-/
// 按顺序取就无需使用used数值判断是否取过

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> cur;
		backtrack(0, nums, cur);
		return ans;
	}

private:
	vector<vector<int>> ans;
	
	void backtrack(int i, vector<int>& nums, vector<int>& cur)
	{
		ans.push_back(cur);
		for (int j = i; j < nums.size(); j++) {
			cur.push_back(nums[j]);
			backtrack(j + 1, nums, cur);
			cur.pop_back();
		}
	}


};



int main()
{
	Solution s;

	


	std::cin.get();
}
