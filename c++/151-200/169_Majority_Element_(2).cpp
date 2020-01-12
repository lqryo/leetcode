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

// 20ms

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];

		int flag = nums[0];
		int count = 1;
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] == flag) count++;
			else {
				count--;
				if (count == 0) {
					flag = nums[i];
					count = 1;
				}
			}
		}
		return flag;
	}
};



 


int main()
{
	Solution s;

	cin.get();
}
