//用时540ms 内存消耗 645MB
//击败11%用户 效率很低

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle);
};

int Solution::strStr(string haystack, string needle)
{
	size_t length_h = haystack.size();
	size_t length_n = needle.size();
	if (length_n == 0) return 0;

	for (size_t i = 0; i < length_h; i++)
	{
		if (haystack.substr(i, length_n) == needle) {
			return i;
		}
	}

	return -1;
	
}

int main()
{
	Solution s;
	string t("hello");
//	cout << t.substr(3, 0) << endl;
	cout << s.strStr("hello", "ll") << endl;

	cin.get();
	return 0;
}