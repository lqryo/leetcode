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


class Solution {
public:
	// 参数：https://leetcode-cn.com/problems/factorial-trailing-zeroes/solution/xiang-xi-tong-su-de-si-lu-fen-xi-by-windliang-3/
	int trailingZeroes(int n) {
		int ans = 0;
		long long rank = 5;
		while (n / rank != 0) {
			ans += n / rank;
			rank *= 5;
		}

		return ans;
	}
};



 


int main()
{
	Solution s;

	cout << s.trailingZeroes(11) << endl;

	cin.get();
}
