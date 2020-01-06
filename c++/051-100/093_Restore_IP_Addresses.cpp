#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// 暴力解

 class Solution {
 public:
	 vector<string> restoreIpAddresses(string s) {
		 //a b c d为字段长度
		 vector<string> ans;
		 for (size_t a = 1; a <= 3; a++)
		 {
			 for (size_t b = 1; b <= 3; b++)
			 {
				 for (size_t c = 1; c <= 3; c++)
				 {
					 for (size_t d = 1; d <= 3; d++)
					 {
						 if (a + b + c + d == s.length()) {
							 int n1 = atoi(s.substr(0, a).c_str());
							 int n2 = atoi(s.substr(a, b).c_str());
							 int n3 = atoi(s.substr(a+b, c).c_str());
							 int n4 = atoi(s.substr(a+b+c, d).c_str());
							 if (n1 <= 255 && n2 <= 255 && n3 <= 255 && n4 <= 255) {
								 string tmp = to_string(n1)+"."+ to_string(n2) + "." + to_string(n3) + "." + to_string(n4);
								 if (tmp.length() == s.length() + 3) ans.push_back(tmp);  //排除1.01.2.3这种情况
							 }
						 }
					 }
				 }
			 }
		 }
		 return ans;
	 }
 };





int main()
{
	Solution s;


	std::cin.get();
}
