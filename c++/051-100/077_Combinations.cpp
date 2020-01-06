#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 回溯 参考：https://leetcode-cn.com/problems/combinations/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-ma-/
// 按顺序取就无需使用used数值判断是否取过

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (n <= 0 || k <= 0 || n < k) {
			return res;
		}
		vector<int> pre;
		findCombinations(n, k, 1, pre);
		return res;
	}

private:
	void findCombinations(int n, int k, int begin, vector<int>& pre)
	{
		if (pre.size() == k) //数够了，添加到结果集中
		{
			res.push_back(pre);
			return;
		}
		for (int i = begin; i <= n; i++) {
			pre.push_back(i);
			findCombinations(n, k, i + 1, pre);
			pre.pop_back();
		}

	}

	vector<vector<int>> res;

};



int main()
{
	Solution s;

	vector<vector<int>> ans = s.combine(4, 2);


	std::cin.get();
}
