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



class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1) return false;
		sort(nums.begin(), nums.end());
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] == nums[i - 1]) return true;
		}
		return false;
	}
};



int main()
{
	Solution s;
	vector<vector<int>> ans;



	cin.get();
}
