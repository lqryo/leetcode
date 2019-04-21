//广度优先搜索
//击败44.85%用户，效果不太理想

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<char, string> num2char = 
{ {'2',"abc"},{'3',"def"},
  {'4',"ghi"},{'5',"jkl"}, 
  {'6',"mno"},{'7',"pqrs"}, 
  {'8',"tuv"},{'9',"wxyz"},};

string chartable = "abcdefghijklmnopqrstuvwxyz";

void fun(string& digits, int index, vector<string>& ans,string s,char zimu)
{

	if (index == digits.size() - 1) {
		if (num2char[digits[index]].find(zimu) != string::npos) {
			s += zimu;
			ans.push_back(s);
		}
		return;
	}
	else {
		if (num2char[digits[index]].find(zimu) != string::npos) {
			s += zimu;
			index++;
			for (auto it = chartable.cbegin(); it < chartable.cend(); it++) {
				fun(digits, index, ans, s, *it);
			}
		}
		else {
			return;
		}

	}

}

class Solution {
public:
	vector<string> letterCombinations(string digits);
};

vector<string> Solution::letterCombinations(string digits)
{
	vector<string> ans{};
	string s;
	for (auto it = chartable.cbegin(); it < chartable.cend(); it++) {
		fun(digits, 0, ans, s, *it);
	}
	return ans;
}


int main()
{
	Solution s;
	vector<string> ans = s.letterCombinations("23");

	//string a = "123";
	//if (a.find('a') == a.npos) {
	//	cout << "not found" << endl;
	//}

	//
	//for(auto i = a.cbegin();i<a.cend();i++)
	//{
	//	cout << "i is " << *i << endl;
	//}

//	cout << a.find('1') << endl;
	


	cin.get();
	return 0;
}

