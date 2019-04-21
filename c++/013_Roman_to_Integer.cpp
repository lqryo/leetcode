#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
	int romanToInt(string s);
};


map<string, int> roman2num = {
	{string("I"),1},{string("IV"),4},
	{string("V"),5},{string("IX"),9},
	{string("X"),10},{string("XL"),40},
	{string("L"),50},{string("XC"),90},
	{string("C"),100},{string("CD"),400},
	{string("D"),500},{string("CM"),900},
	{string("M"),1000},
};



int Solution::romanToInt(string s)
{
	int ans = 0;
	size_t length = s.size();
	s += '0';
	for (size_t i = 0; i < length; )
	{
		string sub = s.substr(i, 2);
		if (roman2num.find(sub) == roman2num.end()) {
			sub = s.substr(i, 1);
			ans += roman2num[sub];
			i++;
		}
		else {
			ans += roman2num[sub];
			i += 2;
		}

	}

	return ans;
}


int main()
{
//	string test = "12345678";
//	cout << test.substr(1, 1) << endl;

	Solution s;
	cout << s.romanToInt("III") << endl;
	cout << s.romanToInt("IV") << endl;
	cout << s.romanToInt("IX") << endl;
	cout << s.romanToInt("LVIII") << endl;
	cout << s.romanToInt("MCMXCIV") << endl;

	cin.get();
	return 0;
}


