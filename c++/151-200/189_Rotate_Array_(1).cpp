
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

// STL rotate函数实现如下
// https://blog.csdn.net/li1615882553/article/details/83546763
// 0ms

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		std::rotate(nums.begin(), nums.end() - k % nums.size(), nums.end());
	}
};


int main()
{


	cin.get();

	return 0;
}

