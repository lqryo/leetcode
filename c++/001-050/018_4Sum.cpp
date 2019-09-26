//解题思路
//1)首先对数组进行排序，设置两个for循环，作为四个数中的前两个数，有可能有两个相同的数，遇到相同的数跳过，这样做是为了避免重复。
//2）四个数中的后两个数怎么办，通过设置两个指针m和n,m从数组前往后进行遍历，n用来从数组后往前进行遍历。m>=n是结束循环的条件。
//3）遇到target==a+b+c+d的数就加到数组中

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target);
};

vector<vector<int>> Solution::fourSum(vector<int>& nums, int target)
{
	size_t length = nums.size();
	vector<vector<int>> ans{};

	if (length < 4) {return ans;}


	sort(nums.begin(), nums.end());
	
	for (size_t i = 0; i < length - 3; i++)
	{
		if (i != 0 && nums[i] == nums[i - 1]) { continue; }
		for (size_t j = i + 1; j < length - 2; j++)
		{
			if (j != i + 1 && nums[j] == nums[j - 1]) { continue; }

			int m = j + 1, n = length - 1;
			int sum1 = nums[i] + nums[j];
			while (m < n)
			{
				if (m != j + 1 && nums[m] == nums[m - 1]) { m++; continue; }
				if (sum1 + nums[m] + nums[n] < target) { m++; }
				else if (sum1 + nums[m] + nums[n] > target) { n--;}
				else {
					ans.push_back(vector<int>{nums[i], nums[j], nums[m], nums[n]});
					m++;
					n--;
				}
			}
		}
	}


	return ans;
}

int main()
{
	vector<int> a{ 1, 0, -1, 0, -2, 2 };
	vector<int> b{ -1,0,1,2,-1,-4 };
	Solution s;
	vector<vector<int>> ans = s.fourSum(b, -1);

	cin.get();
	return 0;
}
