//ע����vc����������ζ�̬������ά����
//��dp[i][j]��ʾ s ��ǰ i ���ַ��� p ��ǰ j ���ַ��Ƿ�ƥ��
//���� s ��ǰ i ���ַ��� p ��ǰ j ���ַ�

//(1) ��p[j-1]��Ϊ*����dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] =='.')
//(2) ��p[j-1]Ϊ*,��3���������������һ�ּ�Ϊtrue
// (2.1)ƥ��0λ��dp[i][j] = dp[i][j-2]
// (2.2)ƥ��1λ��dp[i][j] = dp[i-1][j-2] && ���һλƥ��
// (2.3)ƥ���λ��dp[i][j] = dp[i-1][j] && ���һλ����


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
	//dp[i][j]��ʾ s ��ǰ i ���ַ��� p ��ǰ j ���ַ��Ƿ�ƥ��

	bool** dp = new bool*[m+1];
	for (size_t i = 0; i < m+1; i++)
	{
		dp[i] = new bool[n+1];
	}

	//��ʼ��dp
	for (size_t i = 0; i < m+1; i++)
	{
		for (size_t j = 0; j < n+1; j++)
		{
			dp[i][j] = false;
		}
	}

	dp[0][0] = true;
	//�� s ��Ϊ�գ�pΪ�գ���ƥ��
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
			//��ǰp�ִ������һ���ַ�Ϊ*
			else {
				compare = (s[i - 1] == p[j - 2] || p[j - 2] == '.');
				dp[i][j] = dp[i][j - 2] || (dp[i - 1][j - 2] && compare) || (dp[i - 1][j] && compare);
			}
		}

	}
	bool ans = dp[m][n];
	//�ͷŶ�̬����
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
