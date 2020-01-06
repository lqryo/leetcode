#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 参考：https://leetcode-cn.com/problems/gray-code/solution/c-dong-tai-gui-hua-jian-ji-yi-dong-shi-jian-ji-kon/
// 动态规划

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result(1);
		result[0] = 0;
		for (int i = 0; i <= n; i++) {
			int e = 1 << (i - 1);
			for (int j = result.size() - 1; j >= 0; j--) {
				result.push_back(e + result[j]);
			}
		}
		return result;


	}
};




int main()
{


	std::cin.get();
}
