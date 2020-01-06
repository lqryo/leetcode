/*
参考：https://blog.csdn.net/Gakkis/article/details/78243170
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s);
};

//dp[i]表示以下标i结尾的之前的字符串所能组成的最大有效括号长度
int Solution::longestValidParentheses(string s)
{
	int result = 0;
	vector<int> dp(s.length(), 0);
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == ')')
		{
			if ((i - 1 - dp[i - 1]>=0) && (s[i - 1 - dp[i - 1]] == '('))
			{
				dp[i] = dp[i - 1] + 2;
				if(i - dp[i] >= 0)
					dp[i] += dp[i - dp[i]];
			}
		}
		result = max(result, dp[i]);
	}
	return result;


}



int main(int argc,char* argv[])
{

	Solution solution;
	string s1("(");
	string s2("(()()))()())()(");
	cout << solution.longestValidParentheses(s1) << endl;
	cout << solution.longestValidParentheses(s2) << endl;

	getchar();

	return 0;
}