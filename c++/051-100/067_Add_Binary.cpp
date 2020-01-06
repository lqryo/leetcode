
#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>


using namespace std;

class Solution {
public:
	string addBinary(string a, string b);
};

string Solution::addBinary(string a, string b)
{
	string s;
	int len = max(a.size(), b.size()) + 1;

	s.reserve(len);

	int a1 = a.size();
	int b1 = b.size();

	while (a1 < b1)
	{
		a = string("0") + a;
		++a1;
	}

	while (a1 > b1)
	{
		b = string("0") + b;
		++b1;
	}

	int c = 0;

	for (int i = a.size() - 1; i >= 0; i--) {
		int digit = ((a[i] - '0') + (b[i] - '0') + c) % 2;
		c = ((a[i] - '0') + (b[i] - '0') + c) / 2;
		s.push_back('0' + digit);
	}
	if (c == 1) {
		s.push_back('0'+c);
	}

	reverse(s.begin(), s.end());

	return s;
}




int main()
{
	string a("11");
	string b("1");

	Solution s;
	cout << s.addBinary(a, b) << endl;
	
	cin.get();
	return 0;

}