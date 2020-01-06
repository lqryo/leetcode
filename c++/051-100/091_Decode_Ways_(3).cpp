#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 参考：https://leetcode-cn.com/problems/decode-ways/solution/c-wo-ren-wei-hen-jian-dan-zhi-guan-de-jie-fa-by-pr/
// 动态规划

class Solution {
public:
	// dp[i]为s[0]到s[i]的译码方法总数
	int numDecodings(string s) {  // s is not empty
		if (s[0] == '0') return 0;

		if (s.length() == 1) return 1;

		if (s.length() == 2) {
			int tmp = atoi(s.c_str());
			if (tmp <= 26 && tmp != 10 && tmp != 20) return 2;
			else if (tmp == 10 || tmp == 20) return 1;
			else if (s[1] == '0') return 0;
			else return 1;
		}

		int len = s.length();
		vector<int> dp(len);
		dp[0] = 1;
		int tmp = atoi(s.substr(0,2).c_str());
		if (tmp <= 26 && tmp != 10 && tmp != 20) dp[1] = 2;
		else if (tmp == 10 || tmp == 20) dp[1] = 1;
		else if (s[1] == '0') return 0;
		else dp[1] = 1;

		for (size_t i = 2; i < len; i++)
		{
			if (s[i] == '0') {
				if (s[i - 1] == '1' || s[i - 1] == '2') {
					dp[i] = dp[i - 2];
				}
				else return 0;
			}
			else if (s[i - 1] == '1') {
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			else if (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6') {
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			else {
				dp[i] = dp[i - 1];
			}
		}



		return dp[len - 1];

	}
};




int main()
{
	Solution s;
//	cout << s.numDecodings("1168963884134125126536966946586868418993819971673459188478711546479621135253876271366851168524933185") << endl;
	cout << s.numDecodings("301") << endl;

	std::cin.get();
}
