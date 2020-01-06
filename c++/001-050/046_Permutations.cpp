

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums);


private:
	vector<vector<int>> ans;

	void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	void backtrack(vector<int>& nums, int length, int index)
	{
		if (index == length - 1) {
			ans.push_back(nums);
		}
		else {
			for (size_t i = index; i < length; i++)
			{
				swap(nums[index], nums[i]);
				backtrack(nums, length, index + 1);
				swap(nums[i], nums[index]);
			}
		}
	}

};

vector<vector<int>> Solution::permute(vector<int>& nums)
{
	ans.clear();

	int length = nums.size();	
	backtrack(nums, length, 0);

	return ans;
	
}



int main()
{


	



	cin.get();
	return 0;
}


