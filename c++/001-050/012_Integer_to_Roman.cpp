#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
	string intToRoman(int num);
};


map<int, string>num2roman = {
	{1,string("I")},{4,string("IV")},
	{5,string("V")},{9,string("IX")},
	{10,string("X")},{40,string("XL")},
	{50,string("L")},{90,string("XC")},
	{100,string("C")},{400,string("CD")},
	{500,string("D")},{900,string("CM")},
	{1000,string("M")},
};

vector<int> roman{1,4,5,9,10,40,50,90,100,400,500,900,1000};

string Solution::intToRoman(int num)
{
	string ans = "";
	for (int i = 12; i >= 0; i--)
	{
		while (true)
		{
			if (num - roman[i] >= 0) {
				ans += num2roman[roman[i]];
				num -= roman[i];
			}
			else break;
		}
	}

	return ans;
}


int main()
{
	Solution s;
	cout << s.intToRoman(3) << endl;
	cout << s.intToRoman(4) << endl;
	cout << s.intToRoman(9) << endl;
	cout << s.intToRoman(58) << endl;
	cout << s.intToRoman(1994) << endl;


	cin.get();
	return 0;
}

