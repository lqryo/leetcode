#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

// 两次循环

class Solution {
public:
	bool isPalindrome(string s) {
		string s1;
		for (auto x : s)
		{
			if (x >= '0' && x <= '9') {
				s1.push_back(x);
			}
			else if (x >= 'a' && x <= 'z') {
				s1.push_back(x);
			}
			else if (x >= 'A' && x <= 'Z') {
				char tmp = 'a' + (x - 'A');
				s1.push_back(tmp);
			}
		}
		string s2 = s1;
		reverse(s2.begin(), s2.end());
		return s2 == s1;
	}
};





int main(int argc, char* argv[])
{



	Solution S;

	

	cout << S.isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << S.isPalindrome("race a car") << endl;

	std::cin.get();
}
