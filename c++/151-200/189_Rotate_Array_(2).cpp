
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 三次反转

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		std::reverse(nums.begin(), nums.end());
		std::reverse(nums.begin(), nums.begin() + k);
		std::reverse(nums.begin() + k, nums.end());
	}
};


int main()
{


	cin.get();

	return 0;
}

