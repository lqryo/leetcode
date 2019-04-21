/*
**************
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s);
};

int Solution::lengthOfLongestSubstring(string s)
{
	//��������ַ����е�ǰ�ַ���һ�γ��ֵ�λ��
	vector<int> lastLoc(256, -1);
	int start = -1;  //������ʼ��ǰһ��λ��
	int ans = 0;
	size_t length = s.length();
	for (int i = 0; i < length; i++)
	{
		if (lastLoc[s[i]] > start)
		{
			start = lastLoc[s[i]];
		}
		
		lastLoc[s[i]] = i;
		ans = max(ans, i - start);
	}
	return ans;

}


int main()
{
	string str1("dvdf");
	Solution solution;
	cout << solution.lengthOfLongestSubstring(str1) << endl;

	getchar();
}





