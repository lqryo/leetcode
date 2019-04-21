#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target);
};

int Solution::threeSumClosest(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	int closest = nums[0] + nums[1] + nums[2];
	//固定一个数，然后对另外两个数首尾遍历
	//a b c为对应坐标
	for (int c = nums.size() - 1; c >= 2; c--)
	{
		int a = 0;
		int b = c - 1;
		while (a < b)
		{
			int temp = nums[a] + nums[b] + nums[c];
			closest = (abs(target - temp) < abs(target - closest)) ? temp : closest;
			if (temp > target) { b--; }
			else if (temp < target) { a++; }
			else {
				return target;
			}
		}
	}
	return closest;
}

int main()
{
	Solution s;

	vector<int> v1{ -1,2,1,-4 };
	cout << s.threeSumClosest(v1,1) << endl;

	cin.get();
	return 0;
}

