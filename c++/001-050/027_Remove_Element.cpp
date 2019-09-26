#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val);
};

int Solution::removeElement(vector<int>& nums, int val)
{
	size_t length = nums.size();
	int m = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (nums[i] != val)
		{
			nums[m] = nums[i];
			m++;
		}
	}


	return m;
}

int main()
{


	cin.get();
	return 0;
}
