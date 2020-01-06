

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s);
};

int Solution::lengthOfLastWord(string s)
{
	if (s.empty()) { return 0; }



	int length = s.length();

	int lastLenght = 0;
	
	bool extra_space = true;

	for (int i = length - 1; i >= 0; i--) {
		if (s[i] == ' ' && extra_space) {
			continue;
		}
		else if (s[i] == ' ') {
			break;
		}
		else {
			extra_space = false;
			lastLenght++;
		}
	}

	return lastLenght;
}

int main()
{
	string s = "a ";

	Solution sol;
	
	cout << sol.lengthOfLastWord(s) << endl;

	cin.get();

	return 0;
}

