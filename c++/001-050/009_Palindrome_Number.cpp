#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) { return false; }
		else {
			vector<int> des;
			while (x != 0) {
				int remainder = x % 10;
				des.push_back(remainder);
				x /= 10;
			}
			size_t length = des.size();
			for (size_t i = 0; i < length / 2; i++)
			{
				if (des[i] != des[length - i - 1]) return false;
			}
			return true;
		}
	}
};


int main(int argc,char* argv[])
{

	Solution s;
	cout << s.isPalindrome(121) << endl;
	cout << s.isPalindrome(-121) << endl;
	cout << s.isPalindrome(10) << endl;

	getchar();

	return 0;
}