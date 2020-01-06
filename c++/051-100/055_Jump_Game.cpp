//参考：https://leetcode-cn.com/problems/n-queens/solution/nhuang-hou-by-leetcode/

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums);
};

bool Solution::canJump(vector<int>& nums)
{
	int length = nums.size();
	int maxRange = 0;   //当前可到达的最远距离
	int curIndex = 0;  //当前的位置
	while (true)
	{
		if ((curIndex + nums[curIndex]) >= length - 1) {
			return true;
		}
		else {
			maxRange = max(maxRange, curIndex + nums[curIndex]);

			if (maxRange == curIndex) { return false; }

			curIndex++;		
		}
	}

}


int main()
{

	Solution s;
	
	vector<int> nums1{ 2,3,1,1,4 };
	vector<int> nums2{ 3,2,1,0,4 };

	cout << s.canJump(nums1) << endl;
	cout << s.canJump(nums2) << endl;

	cin.get();
	return 0;
}


