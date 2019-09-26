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
	//用来标记字符串中当前字符上一次出现的位置
	vector<int> lastLoc(256, -1);
	int start = -1;  //窗口起始的前一个位置
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





