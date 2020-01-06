#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 参考：https://leetcode-cn.com/problems/sort-colors/solution/yan-se-fen-lei-by-leetcode/

// 用三个指针来分别追踪0的最右边界，2的最左边界和当前考虑的元素

class Solution {
public:
	void sortColors(vector<int>& nums) {
		// p0为0的最右边界,p2为2的最左边界
		int p0 = 0, curr = 0;
		int p2 = nums.size() - 1;
		while (curr <= p2)
		{
			if (nums[curr] == 0) {
				swap(nums[curr], nums[p0]);
				p0++;
				curr++;
			}
			else if (nums[curr] == 2) {
				swap(nums[curr], nums[p2]);
				p2--;
			}
			else {
				curr++;
			}
		}

	}
};

int main()
{
	Solution s;

	vector<int> nums{ 2,0,1 };
	s.sortColors(nums);


	std::cin.get();
}
