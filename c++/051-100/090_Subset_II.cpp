#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> cur;
		getAns(nums, 0, cur);
		return ans; 
	}




private:
	vector<vector<int>> ans;

	void getAns(vector<int>& nums, int start, vector<int>& cur)
	{
		ans.push_back(cur);
		for (size_t i = start; i < nums.size(); i++)
		{
			// 和上个数字相等就跳过
			if (i > start && nums[i] == nums[i - 1]) {
				continue;
			}
			cur.push_back(nums[i]);
			getAns(nums, i + 1; cur);
			cur.pop_back();
		}
	}
};




int main()
{


	std::cin.get();
}
