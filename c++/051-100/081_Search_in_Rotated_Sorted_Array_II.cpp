#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 参考:https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/solution/zai-javazhong-ji-bai-liao-100de-yong-hu-by-reedfan/

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0) return false;

		int start = 0;
		int end = nums.size() - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			
			if(nums[mid] == target)  return true;
			else if (nums[start] == nums[mid]) {
				start++;
			}
			else if (nums[start] > nums[mid]) {
				if (target > nums[mid] && target <= nums[end])
				{
					start = mid + 1;
				}
				else
				{
					end = mid;
				}
			}
			else if (nums[start] < nums[mid]) {
				if (target < nums[mid] && target >= nums[start])
				{
					end = mid - 1;
				}
				else
				{
					start = mid;
				}
			}
		} // end of while
		return false;

	}
};



int main()
{
	Solution s;

	vector<int> nums1{ 2,5,6,0,0,1,2 };

	cout << s.search(nums1, 0) << endl;
	cout << s.search(nums1, 3) << endl;


	std::cin.get();
}
