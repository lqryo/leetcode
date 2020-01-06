#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target);
};



vector<int> Solution::searchRange(vector<int>& nums, int target)
{
//分两次2分查找
	vector<int> ans{ -1,-1 };
	int length = nums.size();
	if (length == 0) { return ans; }
	if (length == 1 && nums[0] == target) {
		vector<int> ans{ 0,0 };
		return ans;
	}
	int lo = 0, hi = length - 1;
	int mid;
	//寻找左端点
	while (lo<hi)
	{
		mid = (lo + hi) / 2;
		if (nums[mid] > target){
			hi = mid - 1;
		}

		else if (nums[mid] < target) {
			lo = mid + 1;
		}

		else if (nums[mid] == target) {
			hi = mid;
		}
	}
	if (nums[lo] == target) { ans[0] = lo; }


	//寻找右端点
	lo = 0, hi = length - 1;
	while (lo<hi)
	{
		mid = (lo + hi + 1) / 2;
		if (nums[mid] > target) {
			hi = mid - 1;
		}

		else if (nums[mid] < target) {
			lo = mid + 1;
		}

		else if (nums[mid] == target) {
			lo = mid;
		}
	}
	if (nums[hi] == target) { ans[1] = hi; }

	return ans;

}




int main()
{
	vector<int> nums{ 0,0,0,1,2,3 };
	Solution s;
	vector<int> ans = s.searchRange(nums, 0);
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		cout << *it << endl;
	}

}