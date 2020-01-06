#include <vector>
#include <algorithm>
#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target);
};


int Solution::searchInsert(vector<int>& nums, int target)
{
	//¶þ·Ö²éÕÒ
	int length = nums.size();
	if (length == 0) { return 0; }

	int lo = 0, hi = length - 1;
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			lo = mid + 1;
		}
		else if (nums[mid] > target) {
			hi = mid;
		}
	}

	if (nums[lo] > target) { return lo; }
	else if (nums[lo] == target) { return lo; }
	else { return lo + 1; }

}



int main()
{
	
	vector<int> nums1{ 1,3,5,6 };
	Solution s;
	cout << s.searchInsert(nums1, 5) << endl;
	cout << s.searchInsert(nums1, 2) << endl;
	cout << s.searchInsert(nums1, 7) << endl;
	cout << s.searchInsert(nums1, 0) << endl;

	getchar();
	
	return 0;

}