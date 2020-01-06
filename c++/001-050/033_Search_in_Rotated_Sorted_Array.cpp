/*
参考：https://blog.csdn.net/Gakkis/article/details/78243170
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target);
};


// 使用二分查找
// 此题的关键在于明白[begin,mid]和[mid,end]这两个区间内一定有一个是递增的
int Solution::search(vector<int>& nums, int target)
{
	int length = nums.size();
	if (length == 0) return -1;

	
	int begin = 0;
	int end = length - 1;
	int mid = 0;
	
	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else
		{
			if (nums[begin] <= nums[mid]) //[begin,mid]是增区间
			{
				if (target >= nums[begin] && target <= nums[mid])
				{
					end = mid - 1;
				}
				else {
					begin = mid + 1;
				}
			}
			else { //[mid,end]是增区间
				if (target >= nums[mid] && target <= nums[end])
				{
					begin = mid + 1;
				}
				else {
					end = mid - 1;
				}
			}
		}
	}
	return -1;
}



int main(int argc,char* argv[])
{

	Solution solution;
//	vector<int> nums1 = { 4,5,6,7,0,1,2 };
	vector<int> nums2 = { 5,1,3 };
//	cout << solution.search(nums1, 0) << endl;
	cout << solution.search(nums2, 3) << endl;

	getchar();

	return 0;
}