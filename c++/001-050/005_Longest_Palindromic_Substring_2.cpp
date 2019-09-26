//Manacher�㷨
//�ο�https://segmentfault.com/a/1190000003914228ʵ��
//ִ����ʱ 12ms������98.24%�û�

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
	//���ַ�����Ԥ���������п�϶λ�ò���"#"
	for (size_t i = 0; i < s_len; i++)
	{
		s1.push_back('#');
		s1.push_back(s[i]);		
	}
	s1.push_back('#');
	s1.insert(s1.begin(),'$');
	s1.push_back('%');


	size_t s1_len = s1.size();
	//ÿ���ַ�����Ӧ�İ뾶,����������
	//RL�����ֵ��Ϊ��Ӧ�Ľ�
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
			//��i��MaxRight�������jΪ�Գ���Ļ��Ĵ��Ƚ϶�ʱ
			//RL[i]һ������RL[j]�������ٽ�����չ
			int j = 2 * pos - i;
			if (j - RL[j] > pos - RL[pos])
			{
				RL[i] = RL[j];  //MaxRight����
			}

			//i��MaxRight�������jΪ�Գ���Ļ��Ĵ��Ƚϳ�ʱ
			//RL[j]������MaxRight�߽�
			//��MaxRight��ʼ��iΪ������������չ
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
	//������RL�е����ֵ
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
