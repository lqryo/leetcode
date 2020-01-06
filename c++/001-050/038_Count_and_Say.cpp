#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string countAndSay(int n);

private:
	//将数字n与字符c进行拼接
	string strcat(int n, char c)
	{
		string str1 = to_string(n);
		string str2(1, c);
		return str1 + str2;
	}
};


//1<=n<=30
string Solution::countAndSay(int n)
{
	vector<string> ans;
	ans.push_back("");
	ans.push_back("1");
	ans.push_back("11");

	for (size_t i = 3; i <= 30; i++)
	{
		string say;
		int length = ans[i-1].length();
		int count = 1;
		for (size_t j = 1; j < length; j++)
		{
			if (ans[i - 1][j] == ans[i - 1][j - 1]) {
				count++;
			}
			else {
			//	string temp(count, ans[i - 1][j - 1]);
				string temp = strcat(count, ans[i - 1][j - 1]);
				say += temp;
				count = 1;
			}
		}
		string temp = strcat(count, ans[i - 1][length - 1]);
		say += temp;

		ans.push_back(say);
	}

	return ans[n];
}




int main()
{
	
	//string s(4, 'a');
	//cout << s << endl;
	Solution s;
//	cout << s.countAndSay(1) << endl;
//	cout << s.countAndSay(2) << endl;
	cout << s.countAndSay(3) << endl;
	cout << s.countAndSay(4) << endl;
	cout << s.countAndSay(5) << endl;

	getchar();
	
	return 0;

}