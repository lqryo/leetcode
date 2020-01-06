#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 超出时间限制

class Solution {
public:
	// string& erase (size_t pos = 0, size_t len = npos);
	// string substr (size_t pos = 0, size_t len = npos) const;
	int numDecodings(string s) {  // s is not empty
		str = s;
		len = s.length();

		return fun(0);
	}

private:
	string str;
	int len;
	int fun(int start)
	{
		if (start == len) return 1;
		if (str[start] == '0') return 0;
		if (start == len - 1) return 1;

		string s2 = str.substr(start,2);
		int tmp = atoi(s2.c_str());
		if (tmp <= 26) {
			return fun(start + 1) + fun(start + 2);
		}
		else {
			return fun(start + 1);
		}
	}

};




int main()
{
	Solution s;
	cout << s.numDecodings("1168963884134125126536966946586868418993819971673459188478711546479621135253876271366851168524933185") << endl;
//	cout << s.numDecodings("226") << endl;

	std::cin.get();
}
