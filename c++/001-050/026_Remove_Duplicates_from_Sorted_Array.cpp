#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums);
};

int Solution::removeDuplicates(vector<int>& nums)
{
	
	size_t length = nums.size();
	if (length == 0) { return 0; }

	int current = nums[0] - 1;
	int index = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (nums[i] > current) {
			nums[index] = nums[i];
			current = nums[i];
			index++;
		}
	}

	return index;
}

int main()
{
	vector<int> v1{ 1,1,2 };
	vector<int> v2{ 0,0,1,1,1,2,2,3,3,4 };
	Solution s;
	cout << s.removeDuplicates(v1) << endl;
	cout << s.removeDuplicates(v2) << endl;

	cin.get();
	return 0;
}
