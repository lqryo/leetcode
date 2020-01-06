#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//利用stringstream和getline分割字符串
class Solution {
public:
	string simplifyPath(string path) {
		stringstream is(path);
		vector<string> strs;
		string res = "";
		string tmp = "";
		while (getline(is,tmp,'/'))
		{
			if (tmp == "" || tmp == ".")
				continue;
			else if (tmp == ".." && !strs.empty())
				strs.pop_back();
			else if (tmp != "..")
				strs.push_back(tmp);

		}
		
		for (string str : strs)
		{
			res += "/" + str;
		}
		if (res.empty())
			return "/";
		return res;

	}
};

int main()
{
	Solution s;

	std::cout << s.simplifyPath("/home/") << std::endl;
	std::cout << s.simplifyPath("/../") << std::endl;
	std::cout << s.simplifyPath("/home//foo/") << std::endl;
	std::cout << s.simplifyPath("/a/./b/../../c/") << std::endl;
	std::cout << s.simplifyPath("/a/../../b/../c//.//") << std::endl;
	std::cout << s.simplifyPath("/a//b////c/d//././/..") << std::endl;

	std::cin.get();
}
