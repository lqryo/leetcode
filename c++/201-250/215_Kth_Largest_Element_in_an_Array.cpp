#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <stack>


using namespace std;

// partition
// 参考：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/partitionfen-er-zhi-zhi-you-xian-dui-lie-java-dai-/
// 注意pivot选择的随机化

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int len = nums.size();
		int left = 0;
		int right = len - 1;

		int target = len - k;

		while (true)
		{
			int index = partition(nums, left, right);
			if (index == target) {
				return nums[index];
			}
			else if (index < target) {
				left = index + 1;
			}
			else{
				right = index - 1;
			}
		}
	}

private:
	int partition(vector<int>&nums, int left, int right)
	{
		swap(nums[left],nums[(left+right)/2]); // 避免极端测试情况
		int pivot = nums[left];
		int j = left;
		for (int i = left + 1; i <= right; i++) {
			if (nums[i] < pivot) {
				// 小于pivot的元素被交换到前面
				j++;
				swap(nums[i], nums[j]);
			}
		}
		swap(nums[left], nums[j]);

		return j;
	}
};



int main()
{

	cin.get();
}
