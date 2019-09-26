#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs);
};

string Solution::longestCommonPrefix(vector<string>& strs)
{
	string ans = "";
	if (strs.empty()) return ans;
	size_t length = strs[0].size();
	size_t strnum = strs.size();
	bool flag = true;

	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < strnum; j++)
		{
			if (strs[0][i] != strs[j][i]) { flag = false; }
		}
		if (flag) {
			ans += strs[0][i];
		}
		else {
			break;
		}
	}
	
	return ans;
}

int main()
{
	Solution s;

	vector<string> v1{ "flower","flow","flight" };
	cout << s.longestCommonPrefix(v1) << endl;

	vector<string> v2{ "dog","racecar","car" };
	cout << s.longestCommonPrefix(v2) << endl;

	vector<string> v3{ " " };
	cout << s.longestCommonPrefix(v3) << endl;

	cin.get();
	return 0;
}
