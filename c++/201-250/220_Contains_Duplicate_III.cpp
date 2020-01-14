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
#include <set>


using namespace std;

// set::lower_bound用法：http://www.cplusplus.com/reference/set/set/lower_bound/

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		// 活动窗口
		set<int> record;
		for (size_t i = 0; i < nums.size(); i++)
		{
			// 找到大于或等于nums[i]-t的数中最小的数
			auto s = record.lower_bound((double)nums[i] - t);  //防止溢出
			if (s != record.end() && *s <= (double)nums[i] + t) return true;

			record.insert(nums[i]);

			if (record.size() == k + 1)
				record.erase(nums[i - k]);
		}
		return false;

	}
};



int main()
{
	Solution s;


	cin.get();
}
