//参数：https://leetcode-cn.com/problems/first-missing-positive/solution/que-shi-de-di-yi-ge-zheng-shu-by-leetcode/

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
	int firstMissingPositive(vector<int>& nums);
};


int Solution::firstMissingPositive(vector<int>& nums)
{
	int n = nums.size();

	//基本情况
	int contains = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (nums[i] == 1) {
			contains++;
			break;
		}
	}

	if (contains == 0) return 1;
	if (n == 1) return 2;

	//用1替换负数，0和大于n的数
	//在转换以后，nums只会包含正数
	for (size_t i = 0; i < n; i++)
	{
		if (nums[i] <= 0 || nums[i] > n)
			nums[i] = 1;
	}

	//使用索引和数字符号做为检查器
	//例如，如果nums[1]是负数表示在数组中出现了数字1
	//如果nums[2]是正数，表示数字2没有出现
	for (size_t i = 0; i < n; i++)
	{
		int a = abs(nums[i]);

		//如果发现了一个数字a，改变第a个元素的呼号
		//注意重复元素只需操作一次

		if (a == n)
			nums[0] = -abs(nums[0]);
		else
			nums[a] = -abs(nums[a]);
	}

	//现在第一个正数的下标
	//就是第一个缺失的数
	for (size_t i = 1; i < n; i++)
	{
		if (nums[i] > 0)
			return i;
	}

	if (nums[0] > 0)
		return n;

	return n + 1;
}