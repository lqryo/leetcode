//�ο���https://leetcode-cn.com/problems/wildcard-matching/solution/shuang-zhi-zhen-he-dong-tai-gui-hua-by-powcai/

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p);
};


//dp[i][j]��ʾs��iλ�ã�p��jλ���Ƿ�ƥ��
//dp[0][0] ��ȻΪtrue
//dp[0][j] ֻ�е�p[j]='*'��dp[0][j] = dp[0][j-1]������dp[0][j]Ϊfalse

//dp[i][j] ���p[j] = s[i] || p[j]='?'��dp[i][j] = dp[i-1][j-1]��
//���p[j]= '*'�����dp[i-1][j]=true || dp[i][j-1] = true,��dp[i][j]=true������dp[i][j]=false


bool Solution::isMatch(string s, string p)
{
	int s_len = s.length();
	int p_len = p.length();

	//Ϊ����dp����������һ�£���1��ʼ
	s = string("#") + s;
	p = string("#") + p;



	vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1));

	dp[0][0] = true;
	for (size_t j = 1; j <= p_len; j++)
	{
		if (p[j] == '*') {
			dp[0][j] = dp[0][j - 1];
		}
		else {
			dp[0][j] = false;
		}
	}

	for (size_t i = 1; i <= s_len; i++)
	{
		dp[i][0] = false;
	}

	for (size_t i = 1; i <= s_len; i++)
	{
		for (size_t j = 1; j <= p_len; j++)
		{
			if (p[j] == s[i] || p[j] == '?') {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if(p[j] == '*'){ 
				if (dp[i - 1][j] || dp[i][j - 1]) {
					dp[i][j] = true;
				}
				else {
					dp[i][j] = false;
				}
			}
		}
	}

	return dp[s_len][p_len];
}



int main()
{
	string s1("acdcb");
	string p1("a*c?b");
	Solution s;

	cout << s.isMatch(s1, p1) << endl;


	cin.get();
	return 0;
}


