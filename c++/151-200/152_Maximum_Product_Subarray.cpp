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

// 动态规划

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int ans = INT_MIN;
		// imax为当前最大值,imin为当前最小值
		int imax = 1, imin = 1;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 0) {
				swap(imax, imin);
			}
			imax = max(imax*nums[i], nums[i]);
			imin = min(imin*nums[i], nums[i]);

			ans = max(ans, imax);
		}
		return ans;
	}
};



int main()
{
	Solution s;




	cin.get();
}
