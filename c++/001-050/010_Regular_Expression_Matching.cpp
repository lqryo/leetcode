//注意在vc编译器下如何动态声明二维数组
//用dp[i][j]表示 s 的前 i 个字符与 p 的前 j 个字符是否匹配
//分析 s 的前 i 个字符与 p 的前 j 个字符

//(1) 若p[j-1]不为*，则dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] =='.')
//(2) 若p[j-1]为*,分3种情况，满足其中一种即为true
// (2.1)匹配0位：dp[i][j] = dp[i][j-2]
// (2.2)匹配1位：dp[i][j] = dp[i-1][j-2] && 最后一位匹配
// (2.3)匹配多位：dp[i][j] = dp[i-1][j] && 最后一位满足


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p);
};

bool Solution::isMatch(string s, string p)
{
	int m = s.size();
	int n = p.size();
	//dp[i][j]表示 s 的前 i 个字符与 p 的前 j 个字符是否匹配

	bool** dp = new bool*[m+1];
	for (size_t i = 0; i < m+1; i++)
	{
		dp[i] = new bool[n+1];
	}

	//初始化dp
	for (size_t i = 0; i < m+1; i++)
	{
		for (size_t j = 0; j < n+1; j++)
		{
			dp[i][j] = false;
		}
	}

	dp[0][0] = true;
	//若 s 不为空，p为空，则不匹配
	for (size_t i = 1; i < m+1; i++)
	{
		dp[i][0] = false;
	}

	for (size_t j = 1; j < n+1; j++)
	{
		if (j % 2 == 0) {
			dp[0][j] = dp[0][j - 2] && (p[j - 1] == '*');
		}
		else {
			dp[0][j] = false;
		}
	}

	bool compare;
	for (size_t i = 1; i < m+1; i++)
	{
		for (size_t j = 1; j < n+1; j++)
		{
			if (p[j - 1] != '*') {
				dp[i][j] = dp[i - 1][j - 1] && (s[i-1] == p[j-1] || p[j-1]=='.');
			}
			//当前p字串的最后一个字符为*
			else {
				compare = (s[i - 1] == p[j - 2] || p[j - 2] == '.');
				dp[i][j] = dp[i][j - 2] || (dp[i - 1][j - 2] && compare) || (dp[i - 1][j] && compare);
			}
		}

	}
	bool ans = dp[m][n];
	//释放动态数组
	for (size_t i = 0; i < m+1; i++)
	{
		delete[] dp[i];
	}
	delete[] dp;

	return ans;	
}

int main()
{
	Solution s;
	cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("aa", "a*") << endl;
	cout << s.isMatch("ab", ".*") << endl;
	cout << s.isMatch("aab", "c*a*b") << endl;
	cout << s.isMatch("mississippi", "mis*is*p") << endl;

	cin.get();
	return 0;
}
