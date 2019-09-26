/*分治算法
参考：https://blog.csdn.net/hk2291976/article/details/51107778
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
};

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int n = nums1.size();
	int m = nums2.size();
	if (n > m) //保证数组1最短
		return findMedianSortedArrays(nums2, nums1);
	if (n == 0)
	{
		if (m % 2)  //n为奇数
		{
			return nums2[m / 2];
		}
		else //n为偶数 
		{
			return (nums2[m / 2] + nums2[m / 2 - 1]) / 2.0;
		}
	}
	//对每个数组填充#，是数组大小变为奇数
	int L1, L2, R1, R2, c1, c2, lo = 0, hi = 2 * n; //加了虚拟的#后，数组1的长度变为2n+1
	
	while (lo <= hi)
	{
		c1 = (lo + hi) / 2;
		c2 = m + n - c1;
		L1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
		R1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
		L2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
		R2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

		if (L1 > R2)
			hi = c1 - 1;
		else if (L2 > R1)
			lo = c1 + 1;
		else
			break;
	}
	return(max(L1, L2) + min(R1, R2)) / 2.0;
}



int main(int argc,char* argv[])
{
	vector<int> nums1 = { 3 };
	vector<int> nums2 = { -2,-1 };
	Solution s;
	cout << s.findMedianSortedArrays(nums1, nums2);
	getchar();

	return 0;
}