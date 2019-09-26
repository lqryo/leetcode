//��̬�滮 ʱ�临�Ӷ�O(n^2) ��ʱ532ms������14.5%�û�
//P[i][j]��ʾ��i��j���ִ��Ƿ�Ϊ���Ĵ�

#include <iostream>
#include <string>
#include <vector>
#include <utility>


using namespace std;

class Solution {
public:
	string longestPalindrome(string s);
};

string Solution::longestPalindrome(string s)
{
	int n = s.size();
	if (n == 0) {return string("");}
	if (n == 1) { return s.substr(0, 1); }

	int ansLength = 1;
	int index = 0;
	
	vector<vector<bool>> P(n,vector<bool>(n));
	for (size_t i = 0; i < n; i++)
	{
		P[i][i] = true;		
	}
	for (size_t i = 0; i < n-1; i++)
	{
		if (s[i] == s[i + 1]) {
			P[i][i + 1] = true;
			ansLength = 2;
			index = i;
		}
		else { P[i][i + 1] = false;}
	}

	//start��ʾ���ִ�����
	for (size_t step = 3; step <= n; step++)
	{
		for (size_t start = 0; start < n-step+1; start++)
		{
			//if (P[i+1][j-1] && (s[i] == s[j])) {
			//	p[]
			//}
			if (P[start][start+step-1] = (P[start + 1][start + step - 2] && (s[start] == s[start + step -1])))
			{
				if (ansLength < step)
				{
					ansLength = step;
					index = start;
				}
			}
		}
	}

	return s.substr(index,ansLength);
}

int main()
{
	string a = "abcde";
	Solution s;

//	cout << a.substr(0, 2) << endl;
	cout << s.longestPalindrome("babad") << endl;
	cout << s.longestPalindrome("cbbd") << endl;
	cout << s.longestPalindrome("abcba") << endl;

	cin.get();
	return 0;
}
