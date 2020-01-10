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


using namespace std;



// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
};

// 位操作求解

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];

		int res = 0;
		for (size_t i = 0; i < 32; i++)
		{
			int sum = 0;
			for (auto num : nums)
			{
				sum += (num >> i) & 1;
				sum %= 3;
			}
			res = res | (sum << i);
		}
		return res;

	}
};



int main(int argc, char* argv[])
{
	Solution S;

	vector<int> t{ 2,2,2,1 };

	cout << S.singleNumber(t) << endl;

	std::cin.get();

}
