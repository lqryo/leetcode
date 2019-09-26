//Manacher算法
//参考https://segmentfault.com/a/1190000003914228实现
//执行用时 12ms，击败98.24%用户

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s);
};

string Solution::longestPalindrome(string s)
{
	size_t s_len = s.size();
	string s1 = "";
	//对字符串做预处理，在所有空隙位置插入"#"
	for (size_t i = 0; i < s_len; i++)
	{
		s1.push_back('#');
		s1.push_back(s[i]);		
	}
	s1.push_back('#');
	s1.insert(s1.begin(),'$');
	s1.push_back('%');


	size_t s1_len = s1.size();
	//每个字符所对应的半径,不包括自身
	//RL的最大值即为对应的解
	vector<int>RL(s1_len, 0);
	int MaxRight = 0, pos = 0;

	for (size_t i = 1; i < s1_len; i++)
	{
		if (i>=MaxRight)
		{
			int j = 1;
			while (true)
			{
				if (s1[i + j] == s1[i - j]) {
					RL[i]++;
					j++;
				}
				else {
					break;
				}
			}
			pos = i;
			MaxRight = i + RL[i];
		}
		else
		{
			//当i在MaxRight左边且以j为对称轴的回文串比较短时
			//RL[i]一定等于RL[j]，不用再进行扩展
			int j = 2 * pos - i;
			if (j - RL[j] > pos - RL[pos])
			{
				RL[i] = RL[j];  //MaxRight不变
			}

			//i在MaxRight左边且以j为对称轴的回文串比较长时
			//RL[j]超过了MaxRight边界
			//从MaxRight开始以i为中心向两边扩展
			else{
				RL[i] = MaxRight - i;
				int k = 1;
				while (true)
				{
					if (s1[MaxRight + k] == s1[2 * i - MaxRight - k]) { k++; RL[i]++; }
					else { break; }
				}
				MaxRight = i + RL[i];
				pos = i;
			}
		}

	}
	//遍历出RL中的最大值
	int ans = 0, index = 1;
	for (size_t i = 1; i < s1_len; i++)
	{
		if (ans < RL[i]) {
			ans = RL[i];
			index = i;
		}
	}
	string maxstr = s1.substr(index - RL[index], 2 * RL[index] + 1);
	string ansstr("");
	for (size_t i = 0; i < maxstr.size(); i++)
	{
		if (maxstr[i] != '#') { ansstr.push_back(maxstr[i]); }
	}

	return ansstr;
}


int main()
{
	Solution s;

	//cout << s.longestPalindrome("aa") << endl;
	//cout << s.longestPalindrome("cbbd") << endl;
	//cout << s.longestPalindrome("babad") << endl;
	//cout << s.longestPalindrome("") << endl;
	cout << s.longestPalindrome("ccc") << endl;

	cin.get();
	return 0;
}
