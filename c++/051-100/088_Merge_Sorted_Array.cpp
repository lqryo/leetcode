#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 参考：https://leetcode-cn.com/problems/merge-sorted-array/solution/he-bing-liang-ge-you-xu-shu-zu-by-leetcode/
// 双指针法 从后往前

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int p = m + n - 1;
		int p1 = m - 1;
		int p2 = n - 1;

		while (p >= 0) {
			if (p1 >= 0 && p2 >= 0) {
				if (nums1[p1] >= nums2[p2]) {
					nums1[p--] = nums1[p1--];
				}
				else {
					nums1[p--] = nums2[p2--];
				}
			}
			else if (p1 < 0) {
				nums1[p--] = nums2[p2--];
			}
			else {
				nums1[p--] = nums1[p1--];
			}
		}

	}
};




int main()
{


	std::cin.get();
}
