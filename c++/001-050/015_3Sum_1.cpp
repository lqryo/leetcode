//关于unordered_set的使用参考：https://blog.csdn.net/dream_you_to_life/article/details/46785741
//实测该方法效率极低，击败9.93%用户

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct myHash
{
	size_t operator()(pair<int, int> __val) const
	{
	//	return static_cast<size_t>(__val.first * 101 + __val.second);
		return hash<int>()(__val.first * 101 + __val.second);
	}
};

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums);
};

vector<vector<int>> Solution::threeSum(vector<int>& nums)
{
	//定义两个set防止答案重复，存放满足条件的三元组的前两个元素
	unordered_set<pair<int, int>,myHash> dup{};


	vector<vector<int>> ans{};
	sort(nums.begin(), nums.end());

	size_t length = nums.size();
	for (size_t i = 0; i < length; i++)
	{
		int a = nums[i];
		if (i > 0) {
			if (a == nums[i - 1]) continue;
		}

		vector<int> nums_copy = nums;
		nums_copy.erase(nums_copy.begin() + i);

		auto b_i = nums_copy.begin();
		auto c_i = nums_copy.end() - 1;

		while (b_i < c_i)
		{
			if (*b_i + *c_i + a < 0) { b_i++; }
			else if (*b_i + *c_i + a > 0) { c_i--; }
			else {  //找到满足条件的三元组
				vector<int> temp;
				temp.push_back(a);
				temp.push_back(*b_i);
				temp.push_back(*c_i);
				sort(temp.begin(), temp.end());
				pair<int, int>p(temp[0],temp[1]);


				if (dup.find(p) == dup.end()) {
					dup.insert(p);
					ans.push_back(temp);
				}
				b_i++;
				c_i--;
			}
		}

	}
	return ans;
}

ostream& operator<<(ostream& lh, const vector<vector<int>>& rh)
{
	lh << "[" << endl;
	size_t length = rh.size();
	for (size_t i = 0; i < length; i++)
	{
		lh << "  [";
		size_t length2 = rh[i].size();
		for (size_t j = 0; j < length2; j++)
		{
			if (j != length2 - 1) { lh << rh[i][j] << ","; }
			else { lh << rh[i][j]; }
		}
		lh << "]," << endl;
	}
	lh << "]";
	return lh;
}



int main()
{
	Solution s;
	vector<int> v1{ -1, 0, 1, 2, -1, -4 };
	cout << s.threeSum(v1) << endl;

	//vector<int> v2{ -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
	//cout << s.threeSum(v2) << endl;

	cin.get();
	return 0;
}

