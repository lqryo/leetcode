
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// ²Î¿¼£ºhttps://leetcode-cn.com/problems/bitwise-and-of-numbers-range/solution/shi-yong-ji-er-jin-zhi-1de-ge-shu-si-lu-qiu-de-jie/

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		if (m == 0) return 0;
		while (m < n)
		{
			n &= n - 1;
		}
		return n;
	}
};


int main()
{
	Solution s;

	cin.get();

	return 0;
}

